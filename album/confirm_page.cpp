#include "confirm_page.h"
#include "ui_confirm_page.h"

ConfirmPage::ConfirmPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::ConfirmPage)
{
    ui->setupUi(this);
}

ConfirmPage::~ConfirmPage()
{
    delete ui;
}
