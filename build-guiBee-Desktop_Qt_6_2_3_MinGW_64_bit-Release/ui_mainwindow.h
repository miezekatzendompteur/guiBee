/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionFind_Interface;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionInfo;
    QAction *actionExit;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QCustomPlot *customPlot;
    QMenuBar *menubar;
    QMenu *menuAdjustment;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QString::fromUtf8("actionFile"));
        actionFile->setCheckable(false);
        actionFile->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/file.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionFile->setIcon(icon);
        actionFind_Interface = new QAction(MainWindow);
        actionFind_Interface->setObjectName(QString::fromUtf8("actionFind_Interface"));
        actionFind_Interface->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/usb.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind_Interface->setIcon(icon1);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionStart->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/img/start.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon2);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/img/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon3);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rec/img/bee.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 434, 751, 91));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);

        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(30, 10, 751, 421));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuAdjustment = new QMenu(menubar);
        menuAdjustment->setObjectName(QString::fromUtf8("menuAdjustment"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuAdjustment->menuAction());
        menuAdjustment->addAction(actionFile);
        menuAdjustment->addAction(actionFind_Interface);
        menuAdjustment->addAction(actionStart);
        menuAdjustment->addAction(actionStop);
        menuAdjustment->addAction(actionInfo);
        menuAdjustment->addAction(actionExit);
        toolBar->addAction(actionFind_Interface);
        toolBar->addAction(actionFile);
        toolBar->addAction(actionStart);
        toolBar->addAction(actionStop);
        toolBar->addAction(actionInfo);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFile->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        actionFind_Interface->setText(QCoreApplication::translate("MainWindow", "Interface", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuAdjustment->setTitle(QCoreApplication::translate("MainWindow", "Adjustment", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
