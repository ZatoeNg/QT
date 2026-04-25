#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "ui_main_window.h"
#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_color_clicked();

    void on_text_clicked();

    void on_int_2_clicked();

    void on_float_2_clicked();

    void on_item_clicked();

    void on_tip_clicked();

    void on_progress_clicked();

    void on_update_pg_dlg();

    void on_cancel_pg_dlh();

    void on_wizard_clicked();

private:
    Ui::MainWindow *ui;
    QProgressDialog* _progress_diglog;
    QTimer* _timer;
    int _counter;

};
#endif // MAIN_WINDOW_H
