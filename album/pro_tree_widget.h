#ifndef PRO_TREE_WIDGET_H
#define PRO_TREE_WIDGET_H

#include <QTreeWidget>
#include <QAction>
#include <QProgressDialog>
#include "pro_tree_thread.h"

class ProTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    ProTreeWidget(QWidget *parent = nullptr);

public:
    void add_pro_to_tree(const QString& name, const QString& path);
private:
    QSet<QString> _set_path;
    QTreeWidgetItem* _right_bth_item;
    QAction* _action_import;
    QAction* _action_set_start;
    QAction* _action_close_pro;
    QAction* _action_slide_show;
    QProgressDialog* _dialog_progress;
    std::shared_ptr<ProTreeThread> _thread_create_pro;
private slots:
    void slot_item_pressed(QTreeWidgetItem *item, int column);
    void slot_import();
    void slot_update_progress(int count);
    void slot_finish_progress();
    void slot_cancel_progress();
signals:
    void sig_cancel_progress();
};

#endif // PRO_TREE_WIDGET_H
