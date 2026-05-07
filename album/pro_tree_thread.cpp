#include "pro_tree_thread.h"
#include <QDir>
#include "pro_tree_item.h"
#include "const.h"

ProTreeThread::ProTreeThread(const QString &src_path, const QString &dist_path
                             , QTreeWidgetItem *parent_item, int file_count
                             , QTreeWidget *self, QTreeWidgetItem *root, QObject *parent)
    :QThread(parent),_src_path(src_path),_dist_path(dist_path)
    ,_file_count(file_count),_parent_item(parent_item),_self(self)
    ,_root(root),_b_stop(false)
{

}

ProTreeThread::~ProTreeThread()
{

}

void ProTreeThread::run()
{
    create_pro_tree(_src_path,_dist_path,_parent_item
                    ,_file_count,_self,_root);
    if(_b_stop)
    {
        auto path = dynamic_cast<ProTreeItem*>(_root)->get_path();
        auto index = _self->indexOfTopLevelItem(_root);
        delete _self->takeTopLevelItem(index);
        QDir dir(path);
        dir.removeRecursively();
        return;
    }

    emit sig_finish_progress(_file_count);
}



void ProTreeThread::create_pro_tree(const QString &src_path, const QString &dist_path
                                    , QTreeWidgetItem *parent_item, int &file_count
                                    , QTreeWidget *self, QTreeWidgetItem *root
                                    , QTreeWidgetItem *pre_item)
{
    if(_b_stop)
    {
        return;
    }
    bool need_copy = true;
    if(src_path == dist_path)
    {
        need_copy = false;
    }

    QDir import_dir(src_path);
    QStringList name_filters;
    import_dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    import_dir.setSorting(QDir::Name);
    QFileInfoList list = import_dir.entryInfoList();
    for(int i =0;i<list.size();i++)
    {
        if(_b_stop)
        {
            return;
        }
        QFileInfo file_info = list.at(i);
        bool b_is_dir = file_info.isDir();
        if(b_is_dir)
        {
            if(_b_stop)
            {
                return;
            }
            file_count++;
            emit sig_update_progress(file_count);

            QDir dist_dir(_dist_path);
            QString sub_dist_path = dist_dir.absoluteFilePath(file_info.fileName());
            QDir sub_dist_dir(sub_dist_path);
            if(!sub_dist_dir.exists())
            {
                bool ok = sub_dist_dir.mkpath(sub_dist_path);
                if(!ok)
                {
                    continue;
                }
            }
            auto* item = new ProTreeItem(parent_item,file_info.fileName()
                                         ,sub_dist_path,root,TreeItemDir);
            item->setData(0,Qt::DisplayRole,file_info.fileName());
            item->setData(0,Qt::DecorationRole,QIcon(":/icon/dir.png"));
            item->setData(0,Qt::ToolTipRole,sub_dist_path);
            create_pro_tree(file_info.absoluteFilePath(),sub_dist_path
                            ,item,file_count,self,root,pre_item);
        }else
        {
            if(_b_stop)
            {
                return;
            }

            const QString& suffix = file_info.completeSuffix();
            if(suffix !="png" && suffix !="jpeg" && suffix!="jpg")
            {
                continue;
            }

            file_count++;
            emit sig_update_progress(file_count);
            if(!need_copy)
            {
                continue;
            }

            QDir dist_dir(dist_path);
            QString dist_file_path = dist_dir.absoluteFilePath(file_info.fileName());
            if(!QFile::copy(file_info.absoluteFilePath(),dist_file_path))
            {
                continue;
            }

            auto* item = new ProTreeItem(parent_item,file_info.fileName()
                                         ,dist_file_path,root,TreeItemPic);
            item->setData(0,Qt::DisplayRole,file_info.fileName());
            item->setData(0,Qt::DecorationRole,QIcon(":/icon/pic.png"));
            item->setData(0,Qt::ToolTipRole,dist_file_path);

            if(pre_item)
            {
                auto * pre_pro_item=dynamic_cast<ProTreeItem*>(pre_item);
                pre_pro_item->set_next_item(item);
            }
            item->set_pre_item(pre_item);
            pre_item = item;

        }
    }
}

void ProTreeThread::slot_cancel_progress()
{
    this->_b_stop = true;
}
