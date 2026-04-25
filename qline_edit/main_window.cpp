#include "main_window.h"
#include "ui_main_window.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString ip_mask = "000.000.000.000;";
    ui->ip_edit->setInputMask(ip_mask);

    QString mac_mask = "HH:HH:HH:HH:HH:HH;_";
    ui->mac_edit->setInputMask(mac_mask);
    ui->pwd_edit->setEchoMode(QLineEdit::Password);

    QRegularExpression regx(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*\.[a-zA-Z]{2,}$)");
    QValidator* validator = new QRegularExpressionValidator(regx,ui->email_edit);
    ui->email_edit->setValidator(validator);

}

MainWindow::~MainWindow()
{
    delete ui;
}
