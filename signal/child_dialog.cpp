#include "child_dialog.h"
#include "ui_child_dialog.h"
#include <QDebug>

ChildDialog::ChildDialog(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::ChildDialog)
{
	ui->setupUi(this);
}

ChildDialog::~ChildDialog()
{
	delete ui;
}

void ChildDialog::on_enter_main_clicked()
{
	qDebug() << "enter main window" << Qt::endl;
	accept();
}

