#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include "mythread.h"
#include "qcustomplot.h"
#include <stdint.h>
#include "mysave.h"

#ifndef A_H
#define A_H

struct lastData {
    uint32_t time;
    uint boValue;
};

#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const QString programName = "BeeGui 1V0";

public:
    MainWindow(QWidget *parent = nullptr);
    void setupRealtimeDataDemo(QCustomPlot *customPlot);
    ~MainWindow();

private:
    lastData arrayLastData[4] = {{0,0}, {0,0}, {0,0}, {0,0}};
    QThread *thread;
    myThread *mThread;
    QThread *threadSave;
    mySave *mSave;
    QLineSeries *series;
    QTimer dataTimer;
    QChart *chart;
    QChartView *chartView;
    QString demoName;
    QString fileName {};
    QComboBox* comboBox;
    QList<QString> interfaceList;
    QString interfaceValue;

    lastData* getLastData();
    void setLastData(uint, uint, uint);

private slots:
    void setEditText(const QByteArray &);
    void realtimeDataSlot();
    void on_actionFile_triggered();
    void on_actionStart_triggered();
    void setInterface(int);
    void on_actionStop_triggered();

    void on_actionFind_Interface_triggered();

    void on_actionInfo_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
