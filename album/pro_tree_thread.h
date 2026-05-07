#ifndef PRO_TREE_THREAD_H
#define PRO_TREE_THREAD_H

#include <QThread>
#include <QTreeWidgetItem>
#include <QTreeWidget>
class ProTreeThread : public QThread
{
    Q_OBJECT
public:
    ProTreeThread(const QString& src_path,const QString& dist_path,QTreeWidgetItem* parent_item
                  ,int file_count,QTreeWidget* self,QTreeWidgetItem* root
                  ,QObject* parent = nullptr);
    ~ProTreeThread();

protected:
    virtual void run();

private:
    void create_pro_tree(const QString& src_path,const QString& dist_path
                         ,QTreeWidgetItem* parent_item,int & file_count,QTreeWidget* self
                         ,QTreeWidgetItem* root,QTreeWidgetItem* pre_item=nullptr);

    QString _src_path;
    QString _dist_path;
    int _file_count;
    QTreeWidgetItem* _parent_item;
    QTreeWidget* _self;
    QTreeWidgetItem* _root;
    bool _b_stop;
public slots:
    void slot_cancel_progress();
signals:
    void sig_update_progress(int);
    void sig_finish_progress(int);
};

#endif // PRO_TREE_THREAD_H
