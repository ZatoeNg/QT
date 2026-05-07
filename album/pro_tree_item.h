#ifndef PRO_TREE_ITEM_H
#define PRO_TREE_ITEM_H
#include <QTreeWidget>
#include <QTreeWidgetItem>

class ProTreeItem : public QTreeWidgetItem
{
public:
    ProTreeItem(QTreeWidget *view, const QString & name,const QString & path, int type = Type);
    ProTreeItem(QTreeWidgetItem *parent, const QString & name,const QString & path
                , QTreeWidgetItem* root, int type = Type);

    const QString& get_path();
    QTreeWidgetItem* get_root();
    void set_pre_item(QTreeWidgetItem* item);
    void set_next_item(QTreeWidgetItem* item);
    ProTreeItem* get_pre_item();
    ProTreeItem* get_next_item();
    ProTreeItem* get_last_pic_child();
    ProTreeItem* get_first_pic_child();
private:
    QString _path;
    QString _name;
    QTreeWidgetItem* _root;
    QTreeWidgetItem* _pre_item;
    QTreeWidgetItem* _next_item;
};

#endif // PRO_TREE_ITEM_H
