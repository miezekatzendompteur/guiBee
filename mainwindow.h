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

    lastData* getLastData();
    void setLastData(uint, uint, uint);

private slots:
    void on_startButton_clicked();
    void setEditText(const QByteArray &);
    void on_stopButton_clicked();
    void on_fileDialog_clicked();
    void realtimeDataSlot();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
