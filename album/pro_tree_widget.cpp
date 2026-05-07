#include "pro_tree_widget.h"
#include <QDir>
#include "pro_tree_item.h"
#include "const.h"
#include <QHeaderView>
#include <QGuiApplication>
#include <QMenu>
#include <QFileDialog>

ProTreeWidget::ProTreeWidget(QWidget *parent)
{
    this->header()->hide();
    connect(this,&ProTreeWidget::itemPressed
            ,this,&ProTreeWidget::slot_item_pressed);
    _action_import = new QAction(QIcon(":/icon/import.png"),tr("导入文件"),this);
    _action_set_start = new QAction(QIcon(":/icon/core.png"),tr("设置活动项目"),this);
    _action_close_pro = new QAction(QIcon(":/icon/close.png"),tr("关闭项目"),this);
    _action_slide_show = new QAction(QIcon(":/icon/slideshow.png"),tr("轮播图播放"),this);

    connect(_action_import,&QAction::triggered,this,&ProTreeWidget::slot_import);
}

void ProTreeWidget::add_pro_to_tree(const QString &name, const QString &path)
{
    QDir dir(path);
    QString file_path = dir.absoluteFilePath(name);
    if(_set_path.find(file_path) !=_set_path.end())
    {
        return;
    }

    QDir pro_dir(file_path);
    if(!pro_dir.exists())
    {
        bool enable = pro_dir.mkpath(file_path);
        if(!enable)
        {
            return;
        }
    }

    _set_path.insert(file_path);
    auto item = new ProTreeItem(this,name,file_path
                                ,TreeItemPro);
    item->setData(0,Qt::DisplayRole,name);
    item->setData(0,Qt::DecorationRole,QIcon(":/icon/dir.png"));
    item->setData(0,Qt::ToolTipRole,file_path);

    this->addTopLevelItem(item);

}

void ProTreeWidget::slot_item_pressed(QTreeWidgetItem *item, int column)
{
    if(QGuiApplication::mouseButtons()==Qt::RightButton)
    {
        QMenu menu(this);
        int item_type = item->type();
        if(item_type==TreeItemPro)
        {
            _right_bth_item=item;
            menu.addAction(_action_import);
            menu.addAction(_action_set_start);
            menu.addAction(_action_close_pro);
            menu.addAction(_action_slide_show);
            menu.exec(QCursor::pos());
        }
    }
}

void ProTreeWidget::slot_import()
{
    QFileDialog file_dialog;
    file_dialog.setFileMode(QFileDialog::Directory);
    file_dialog.setWindowTitle(tr("选择导入的文件夹"));
    QString path = "";
    if(!_right_bth_item)
    {
        qDebug()<<"_right_bth_item is empty";
        // path = QDir::currentPath();
        return;
    }

    path=dynamic_cast<ProTreeItem*>(_right_bth_item)->get_path();
    file_dialog.setDirectory(path);
    file_dialog.setViewMode(QFileDialog::Detail);

    QStringList file_names;
    if(file_dialog.exec())
    {
        file_names =file_dialog.selectedFiles();
    }

    if(file_names.length()<=0)
    {
        return;
    }

    QString import_path = file_names.at(0);
    int file_count = 0;
    _dialog_progress = new QProgressDialog(this);

    _thread_create_pro = std::make_shared<ProTreeThread>(std::ref(import_path),std::ref(path),_right_bth_item
                                                         ,file_count,this,_right_bth_item,nullptr);

    connect(_thread_create_pro.get(),&ProTreeThread::sig_update_progress
            ,this,&ProTreeWidget::slot_update_progress);

    connect(_thread_create_pro.get(),&ProTreeThread::sig_finish_progress
            ,this,&ProTreeWidget::slot_finish_progress);

    connect(_dialog_progress,&QProgressDialog::canceled,this,&ProTreeWidget::slot_cancel_progress);
    connect(this,&ProTreeWidget::sig_cancel_progress,_thread_create_pro.get()
            ,&ProTreeThread::slot_cancel_progress);

    _thread_create_pro->start();
    _dialog_progress->setWindowTitle("Please wait....");
    _dialog_progress->setFixedWidth(PRO_GRESS_WIDTH);
    _dialog_progress->setRange(0,PRO_GRESS_WIDTH);
    _dialog_progress->exec();
}

void ProTreeWidget::slot_update_progress(int count)
{
    if(!_dialog_progress)
    {
        return;
    }

    if(count >=PRO_GRESS_MAX)
    {
        _dialog_progress->setValue(count%PRO_GRESS_MAX);
    }
    else
    {
        _dialog_progress->setValue(count);
    }
}

void ProTreeWidget::slot_finish_progress()
{
    _dialog_progress->setValue(PRO_GRESS_MAX);
    _dialog_progress->deleteLater();
}

void ProTreeWidget::slot_cancel_progress()
{
    emit sig_cancel_progress();
    delete _dialog_progress;
    _dialog_progress =nullptr;
}


