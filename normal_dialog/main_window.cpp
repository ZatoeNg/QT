#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),_counter(0)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_color_clicked()
{
    QColorDialog color_dlg(Qt::blue,this);
    color_dlg.setOption(QColorDialog::ShowAlphaChannel);
    color_dlg.exec();
    QColor color = color_dlg.currentColor();
    qDebug()<<"color: "<< color<<Qt::endl;
}

void MainWindow::on_text_clicked()
{
    QString path = QDir::currentPath();
    QString title = tr("文件对话框");
    QString filter = tr("文本文件(*.txt);;"
                        "图片文件(*.jpg *.gif *.png)"
                        ";;所有文件(*.*)");
    QString a_file_name = QFileDialog::getOpenFileName(this,title,path,filter);

    qDebug()<<a_file_name<<Qt::endl;
}

void MainWindow::on_int_2_clicked()
{
    bool flag =false;
    auto int_data = QInputDialog::getInt(this,tr("数字输入对话框")
                                         ,tr("请输入提示"),0,-200,400,10,&flag);
    if(flag)qDebug()<<int_data<<Qt::endl;
}

void MainWindow::on_float_2_clicked()
{
    bool flag =false;
    auto double_data = QInputDialog::getDouble(this,tr("浮点输入对话框")
                                               ,tr("请输入浮点数"),0.0f,-200.0f,400.0f,3.0f,&flag,Qt::WindowFlags(),10.0f);
    if(flag)qDebug()<<double_data<<Qt::endl;
}



void MainWindow::on_item_clicked()
{
    QStringList items;
    items << tr("条目1") << tr("条目2");
    bool flag = false;
    auto item_data = QInputDialog::getItem(this,tr("条目对话框"),tr("输入/选择"),items,0,true,&flag);
    if(flag)qDebug()<<item_data<<Qt::endl;
}


void MainWindow::on_tip_clicked()
{
    auto ret = QMessageBox::question(this,tr("提问对话框"),tr("你是人机吗?")
                                                                 ,QMessageBox::Yes,QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        qDebug()<<"我是人机_1: "<<ret;
    }

    auto ret_2 = QMessageBox::information(this,tr("通知对话框"),tr("你是人机吗?")
                                          ,QMessageBox::Yes,QMessageBox::No);

    if(ret_2 == QMessageBox::Yes)
    {
        qDebug()<<"我是人机_2: "<<ret;
    }

    auto ret_3 = QMessageBox::warning(this,tr("警告对话框"),tr("你是人机吗?")
                                      ,QMessageBox::Yes,QMessageBox::No);
    if(ret_3 == QMessageBox::Yes)
    {
        qDebug()<<"我是人机_3: "<<ret;
    }

    auto ret_4 =  QMessageBox::critical(this,tr("提示对话框"),tr("你是人机吗?")
                                       ,QMessageBox::Yes,QMessageBox::No);
    if(ret_4 == QMessageBox::Yes)
    {
        qDebug()<<"我是人机_4: "<<ret;
    }

}


void MainWindow::on_progress_clicked()
{
    _progress_diglog = new QProgressDialog(tr("正在复制"),tr("取消复制"),0,5000,this);
    _progress_diglog->setWindowTitle(tr("文件复制进度对话框"));
    _progress_diglog->setWindowModality(Qt::ApplicationModal);
    _timer = new QTimer(this);
    connect(_timer,&QTimer::timeout,this,&MainWindow::on_update_pg_dlg);
    connect(_progress_diglog,&QProgressDialog::canceled,this,&MainWindow::on_cancel_pg_dlh);
    _timer->start(2);
}

void MainWindow::on_update_pg_dlg()
{
    _counter++;
    if(_counter > 5000)
    {
        _timer->stop();
        delete _timer;
        _timer = nullptr;
        delete _progress_diglog;
        _progress_diglog = nullptr;
        _counter = 0;
        return;
    }

    _progress_diglog->setValue(_counter);
}

void MainWindow::on_cancel_pg_dlh()
{
    _timer->stop();
    delete _timer;
    _timer = nullptr;
    delete _progress_diglog;
    _progress_diglog = nullptr;
    _counter = 0;
    return;
}


void MainWindow::on_wizard_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));

    auto page_1 = new QWizardPage();
    page_1->setTitle(tr("page_1 program"));
    auto label_1 = new QLabel();
    label_1->setText(tr("program label 1"));
    auto layout_1=  new QVBoxLayout();

    layout_1->addWidget(label_1);
    page_1->setLayout(layout_1);
    wizard.addPage(page_1);

    auto page_2 =new QWizardPage();
    page_2->setTitle("向导对话框2");
    auto group= new QButtonGroup(page_2);

    auto btn_1=new QRadioButton();
    btn_1->setText("A");
    auto btn_2=new QRadioButton();
    btn_2->setText("B");
    auto btn_3=new QRadioButton();
    btn_3->setText("C");

    group->addButton(btn_1);
    group->addButton(btn_2);
    group->addButton(btn_3);

    auto layout_2= new QVBoxLayout();
    for(int i =0;i<group->buttons().size();i++)
    {
        layout_2->addWidget(group->buttons()[i]);
    }

    page_2->setLayout(layout_2);
    wizard.addPage(page_2);

    QWizardPage* page_3 = new QWizardPage();
    page_3->setTitle(tr("page_3"));
    auto lable_3 = new QLabel();
    lable_3->setText(tr("lable_3"));
    auto layout_3=  new QVBoxLayout();
    layout_3->addWidget(lable_3);
    page_3->setLayout(layout_3);
    wizard.addPage(page_3);

    wizard.show();
    wizard.exec();
}

