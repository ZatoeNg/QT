#include "main_window.h"
#include "ui_main_window.h"
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //create menu
    QMenu* menu_file = menuBar()->addMenu(tr("文件(&F)"));

    //create project action
    QAction* act_create_pro = new QAction(QIcon(":/icon/createpro.png"),tr("创建项目"),this);
    act_create_pro->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));

    //open project action
    QAction* act_open_pro = new QAction(QIcon(":/icon/openpro.png"),tr("打开项目"),this);
    act_open_pro->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));

    //menu file add action
    menu_file->addAction(act_create_pro);
    menu_file->addAction(act_open_pro);

    //create setting menu
    QMenu* menu_set = menuBar()->addMenu(tr("设置(&S)"));
    // add background music
    QAction* act_music = new QAction(QIcon(":/icon/music.png"),tr("音乐"),this);
    act_music->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_M));

    //menu music add action
    menu_set->addAction(act_music);

    //connect signals and slots
    connect(act_create_pro,&QAction::triggered,this,&MainWindow::SlotCreatrPro);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotCreatrPro(bool)
{
    qDebug()<<"test slots triggered"<<Qt::endl;
}
