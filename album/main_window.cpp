#include "main_window.h"
#include "ui_main_window.h"
#include "wizard.h"
#include "pro_tree.h"

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

    _pro_tree = new ProTree();
    ui->pro_lay->addWidget(_pro_tree);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotCreatrPro(bool)
{
    Wizard wizard(this);
    wizard.setWindowTitle(tr("创建项目"));
    auto* page = wizard.page(0);
    page->setTitle(tr("设置项目配置"));
    //TODO: 连接信号和槽
    connect(&wizard,&Wizard::sig_pro_settings
            ,dynamic_cast<ProTree*>(_pro_tree),&ProTree::add_pro_to_tree);

    wizard.show();
    wizard.exec();

    //TODO：断开信号
    disconnect();

}
