#ifndef DELEGATE_SPINBOX_H
#define DELEGATE_SPINBOX_H

#include <QItemDelegate>

class SpinBoxDelegate : public QItemDelegate
{
     Q_OBJECT
public:
    explicit SpinBoxDelegate(QObject * parent=0);
    QWidget * createEditor(QWidget* parent,   const QStyleOptionViewItem &option,
                           const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // DELEGATE_SPINBOX_H
