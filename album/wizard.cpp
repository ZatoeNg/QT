#include "wizard.h"
#include "ui_wizard.h"

Wizard::Wizard(QWidget *parent)
    : QWizard(parent)
    , ui(new Ui::Wizard)
{
    ui->setupUi(this);
}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::done(int result)
{
    if(result==QDialog::Rejected)
    {
        return QWizard::done(result);
    }

    QString name,path;
    ui->wizardPage1->get_pro_settings(name,path);
    emit sig_pro_settings(name,path);
    QWizard::done(result);
}
