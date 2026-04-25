#include "main_dialog.h"

#include <QApplication>
#include "child_dialog.h"
#include <QDebug>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
    MainDialog w;
	ChildDialog child_dialog;
	auto res = child_dialog.exec();
	if (res == QDialog::Accepted)
	{
		qDebug() << "child exec: " << res << Qt::endl;
		w.show();
		a.exec();
	}
	else {
		qDebug() << "child exit: " << res << Qt::endl;
		return 0;
	}

}
