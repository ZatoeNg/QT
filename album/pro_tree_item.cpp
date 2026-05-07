#include "pro_tree_item.h"

ProTreeItem::ProTreeItem(QTreeWidget *view, const QString &name, const QString &path, int type)
    :QTreeWidgetItem(view,type),_path(path),_name(name)
    ,_root(this),_pre_item(nullptr),_next_item(nullptr)
{

}

ProTreeItem::ProTreeItem(QTreeWidgetItem *parent, const QString &name, const QString &path
                        , QTreeWidgetItem *root, int type)
    :QTreeWidgetItem(parent,type),_path(path),_name(name)
    ,_root(root),_pre_item(nullptr),_next_item(nullptr)
{

}

const QString &ProTreeItem::get_path()
{
    return _path;
}

QTreeWidgetItem *ProTreeItem::get_root()
{
    return _root;
}

void ProTreeItem::set_pre_item(QTreeWidgetItem *item)
{
    _pre_item = item;
}

void ProTreeItem::set_next_item(QTreeWidgetItem *item)
{
    _next_item = item;
}

ProTreeItem *ProTreeItem::get_pre_item()
{
    return dynamic_cast<ProTreeItem*>(_pre_item);
}

ProTreeItem *ProTreeItem::get_next_item()
{
    return dynamic_cast<ProTreeItem*>(_next_item);
}

ProTreeItem *ProTreeItem::get_last_pic_child()
{

}

ProTreeItem *ProTreeItem::get_first_pic_child()
{

}
