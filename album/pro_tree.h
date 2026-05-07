#ifndef PRO_TREE_H
#define PRO_TREE_H

#include <QDialog>

namespace Ui {
class ProTree;
}

class ProTree : public QDialog
{
    Q_OBJECT

public:
    explicit ProTree(QWidget *parent = nullptr);
    ~ProTree();

private:
    Ui::ProTree *ui;

public slots:
    void add_pro_to_tree(const QString name,const QString path);
};

#endif // PRO_TREE_H
