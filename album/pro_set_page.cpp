#include "pro_set_page.h"
#include "ui_pro_set_page.h"
#include <QDir>
#include <QFileDialog>

ProSetPage::ProSetPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::ProSetPage)
{
    ui->setupUi(this);
    registerField("ProName*",ui->name_edit);
    registerField("ProPath",ui->path_edit);
    connect(ui->name_edit,&QLineEdit::textEdited,this,&ProSetPage::completeChanged);
    connect(ui->path_edit,&QLineEdit::textEdited,this,&ProSetPage::completeChanged);

    ui->name_edit->setClearButtonEnabled(true);
    QString cur_path = QDir::currentPath();
    ui->path_edit->setText(cur_path);
    ui->path_edit->setCursorPosition(ui->path_edit->text().size());
    ui->path_edit->setClearButtonEnabled(true);
}

ProSetPage::~ProSetPage()
{
    delete ui;
}

void ProSetPage::get_pro_settings(QString &name, QString &path)
{
    name=ui->name_edit->text();
    path=ui->path_edit->text();
}

bool ProSetPage::isComplete() const
{
    if(ui->name_edit->text()=="" || ui->path_edit->text()=="")
    {

        return false;
    }

    QDir dir(ui->path_edit->text());
    if(!dir.exists())
    {
        ui->tips_lab->setText("project path is not exists");
        return false;
    }

    //判断路径
    QString abs_file_path = dir.absoluteFilePath(ui->name_edit->text());
    QDir dist_dir(abs_file_path);
    if(dist_dir.exists())
    {
        ui->tips_lab->setText("project has exists,change name or path");
        return false;
    }

    ui->tips_lab->setText("");
    return QWizardPage::isComplete();
}

void ProSetPage::on_browse_clicked()
{
    QFileDialog file_dialog;
    file_dialog.setFileMode(QFileDialog::Directory);
    file_dialog.setWindowTitle("选择导入的文件夹");
    auto path = QDir::currentPath();
    file_dialog.setDirectory(path);
    file_dialog.setViewMode(QFileDialog::Detail);

    QStringList file_names;
    if(file_dialog.exec())
    {
        file_names=file_dialog.selectedFiles();
    }

    if(file_names.length()<=0)
    {
        return;
    }

    QString import_path = file_names.at(0);
    ui->path_edit->setText(import_path);
}

