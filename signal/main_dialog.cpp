#include "main_dialog.h"
#include "ui_main_dialog.h"
#include "child_dialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_send_to_c_clicked()
{
    close();
    ChildDialog cdl;
    if(cdl.exec() == QDialog::Accepted)
    {
        this->show();
    }else
    {
        return;
    }
}

