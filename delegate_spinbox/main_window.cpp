#include "main_window.h"
#include "ui_main_window.h"

#include <QStandardItem>
#include <QItemSelectionModel>
#include <QTableView>
#include "delegate_spinbox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int const ROW = 7;
    int const COLUNM = 4;

    QStandardItemModel * model = new QStandardItemModel(ROW,COLUNM,this);
    for(int row=0; row < ROW; row++){
        for(int column = 0; column < COLUNM; column++){
            QStandardItem * item = new QStandardItem(QString("%1").arg(row*COLUNM+column));
            model->setItem(row, column, item);
        }
    }

   QTableView* _table_view = new QTableView;
    _table_view->setModel(model);
    setCentralWidget(_table_view);
    this->resize(800,800);

    QTableView* _table_view2 = new QTableView;
    SpinBoxDelegate * delegate = new SpinBoxDelegate(this);
    // QStandardItemModel * model2 = new QStandardItemModel(ROW,COLUNM,this);
    for(int row=0; row < ROW; row++){
        for(int column = 0; column < COLUNM; column++){
            QStandardItem * item = new QStandardItem(QString("%1").arg(row*COLUNM+column));
            model->setItem(row, column, item);
        }
    }
     _table_view2->setModel(model);
     _table_view2->setItemDelegate(delegate);
     _table_view2->show();
     _table_view2->resize(800,800);
}

MainWindow::~MainWindow()
{
    delete ui;
}
