#include "main_window.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/style.qss");
    if(qss.open(QFile::ReadOnly))
    {
        qDebug("open qss success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else
    {
        qDebug() << "Open qss failed! Error:" << qss.errorString();
        return 0;
    }

    MainWindow w;
    w.setWindowTitle("album");
    w.showMaximized();
    return a.exec();
}
