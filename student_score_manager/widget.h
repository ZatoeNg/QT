#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

public slots:
    void on_SearchBtn_clicked();
    void on_SearchEdit_editingFinished();
    void on_InsertBtn_clicked();
    void on_DeleteBtn_clicked();
    void on_UpdateBtn_clicked();

public:
    void loadTestData(const QString& filename);
    void iniDatabase();
    void onSearch();

private:
    Ui::widget *ui;
};

#endif // WIDGET_H
