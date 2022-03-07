#include "mainwindow.h"
#include <QLatin1String>

#include <QApplication>
#include <QtWidgets>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QFile styleSheetFile("Adaptic.qss");
//    styleSheetFile.open(QFile::ReadOnly);
//    QString styleSheet = QLatin1String(styleSheetFile.readAll());
//    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    return a.exec();
}

