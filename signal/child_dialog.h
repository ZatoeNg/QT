#ifndef CHILD_DIALOG_H
#define CHILD_DIALOG_H

#include <QDialog>

namespace Ui {
	class ChildDialog;
}

class ChildDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ChildDialog(QWidget* parent = nullptr);
	~ChildDialog();

private slots:
	void on_enter_main_clicked();

private:
	Ui::ChildDialog* ui;
};

#endif // CHILD_DIALOG_H
