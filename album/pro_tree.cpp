#include "pro_tree.h"
#include "ui_pro_tree.h"

ProTree::ProTree(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProTree)
{
    ui->setupUi(this);
    this->setMinimumWidth(378);
    this->setMaximumWidth(378);
}

ProTree::~ProTree()
{
    delete ui;
}

void ProTree::add_pro_to_tree(const QString name, const QString path)
{
    ui->tree_wig->add_pro_to_tree(name,path);
}
