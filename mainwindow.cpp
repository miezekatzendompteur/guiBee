#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include "mysave.h"
#include <QThread>
#include <QFileDialog>
#include <QStandardPaths>
#include <QChartView>
#include <QSerialPortInfo>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setupRealtimeDataDemo(ui->customPlot);

    comboBox = new QComboBox();
    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setInterface(int)));

    thread = new QThread();
    mThread = new myThread();
    threadSave = new QThread();
    mSave = new mySave();

}

MainWindow::~MainWindow()
{
    if (thread->isRunning()){
        thread->quit();
        thread->wait();
        delete thread;
        delete mThread;
        qDebug() << "Thread is running: " << thread->isRunning();
    }

    if (threadSave->isRunning()){
        threadSave->quit();
        threadSave->wait();
        delete threadSave;
        delete mSave;
        qDebug() << "ThreadSave is running: " << threadSave->isRunning();
    }

    qDebug() << "Thread closed";
    delete ui;
}


void MainWindow::setEditText(const QByteArray &text){
    qDebug() << "Main: " << text;
    ui->textEdit->moveCursor (QTextCursor::End);
    ui->textEdit->insertPlainText (text);

    QMetaObject::invokeMethod(mSave, "writeFile", Q_ARG(QString, text));

    QString list= QString::fromUtf8(text.constData(), text.length());
    list = list.simplified();
    QStringList stringList = list.split(';');
    QString selectChannel = stringList[0].back();


    switch(selectChannel.toUInt()) {
        case 0:
            setLastData(0, stringList[1].toUInt(), stringList[2].toUInt());
            break;
        case 1:
            setLastData(1, stringList[1].toUInt(), stringList[2].toUInt());
            break;
        case 2:
            setLastData(2, stringList[1].toUInt(), stringList[2].toUInt());
            break;
        case 3:
            setLastData(3, stringList[1].toUInt(), stringList[2].toUInt());
            break;
        default:
            break;

    }

    qDebug() << stringList;

}

void MainWindow::setLastData(uint channel, uint time, uint boValue){
    switch(channel) {
    case 0:
        arrayLastData[0].time = time;
        arrayLastData[0].boValue = boValue;
        break;
    case 1:
        arrayLastData[1].time = time;
        arrayLastData[1].boValue = boValue;
        break;
    case 2:
        arrayLastData[2].time = time;
        arrayLastData[2].boValue = boValue;
        break;
    case 3:
        arrayLastData[3].time = time;
        arrayLastData[3].boValue = boValue;
        break;
    default:
        break;
    }
}



void MainWindow::setupRealtimeDataDemo(QCustomPlot *customPlot)
{
  // include this section to fully disable antialiasing for higher performance:
  /*
  customPlot->setNotAntialiasedElements(QCP::aeAll);
  QFont font;
  font.setStyleStrategy(QFont::NoAntialias);
  customPlot->xAxis->setTickLabelFont(font);
  customPlot->yAxis->setTickLabelFont(font);
  customPlot->legend->setFont(font);
  */
  customPlot->addGraph(); // red line
  customPlot->graph(0)->setPen(QPen(Qt::darkRed));
  customPlot->addGraph(); // green line
  customPlot->graph(1)->setPen(QPen(Qt::darkGreen));
  customPlot->addGraph(); // cyan line
  customPlot->graph(2)->setPen(QPen(Qt::blue));
  customPlot->addGraph(); // magenta line
  customPlot->graph(3)->setPen(QPen(Qt::magenta));

  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%m:%s:%z");
  customPlot->xAxis->setTicker(timeTicker);
  customPlot->axisRect()->setupFullAxesBox();
  customPlot->yAxis->setRange(-0.1, 4.4);

  // make left and bottom axes transfer their ranges to right and top axes:
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));

}

void MainWindow::realtimeDataSlot()
{
  static QTime timeStart = QTime::currentTime();
  // calculate two new data points:
  double key = timeStart.msecsTo(QTime::currentTime())/1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;

  //qDebug()<< returnLastData[0].boValue << ";" << returnLastData[1].boValue << ";" << returnLastData[2].boValue << ";" << returnLastData[3].boValue;

  if (key-lastPointKey > 0.002)
  {
      ui->customPlot->graph(0)->addData(key, arrayLastData[0].boValue);
      ui->customPlot->graph(1)->addData(key, arrayLastData[1].boValue + 1.1);
      ui->customPlot->graph(2)->addData(key, arrayLastData[2].boValue + 2.2);
      ui->customPlot->graph(3)->addData(key, arrayLastData[3].boValue + 3.3);
      //qDebug() << arrayLastData[0].boValue << ";" << arrayLastData[1].boValue << ";" << arrayLastData[2].boValue << ";" << arrayLastData[3].boValue;
      lastPointKey = key;
  }


  // make key axis range scroll with the data (at a constant range size of 8):
  ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  ui->customPlot->replot();

  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    ui->statusBar->showMessage(
          QString("%1 FPS, Total Data points: %2")
          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          .arg(ui->customPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
          , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}

void MainWindow::on_actionFile_triggered()
{
    fileName = QFileDialog::getSaveFileName(this,
        tr("Save Values"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + QDir::separator() + QDateTime::currentDateTime().toString("yyyy_MM_dd_hh-mm-ss"), tr("Text files (*.txt)"));
    qDebug() << fileName;

    if (fileName != nullptr){
        ui->actionFind_Interface->setEnabled(true);
    }
    else
    {
        ui->actionFind_Interface->setEnabled(false);
    }
}


void MainWindow::on_actionStart_triggered()
{
//    connect(thread, SIGNAL(finished()), mThread, SLOT(deleteLater()));
//    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    qDebug() << thread;
    qDebug() << mThread;

    connect(mThread, SIGNAL(emitData(QByteArray)), this, SLOT(setEditText(QByteArray)));

    mThread->moveToThread(thread);
    thread->start();

    mSave->moveToThread(threadSave);
    threadSave->start();

    QMetaObject::invokeMethod(mThread, "setInterfaceName", Q_ARG(QString, interfaceValue));

    QMetaObject::invokeMethod(mSave, "setFile", Q_ARG(QString, fileName));

    qDebug() << "Main open " << QThread::currentThread() << " InterfaceName: " << interfaceValue;

    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}


void MainWindow::on_actionStop_triggered()
{
    QMetaObject::invokeMethod(mThread, "closeInterface");
    QMetaObject::invokeMethod(mSave, "closeFile");
    dataTimer.stop();
}


void MainWindow::on_actionFind_Interface_triggered()
{

    ui->toolBar->addWidget(comboBox);
    comboBox->clear();

    const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos){
        if (info.vendorIdentifier() == 0x04B4 && info.productIdentifier() == 0xF139){
            qDebug() << "SystemLocation" << info.systemLocation();
            interfaceList.append(info.systemLocation());
            comboBox->addItem(info.portName());
        }

    }
}




void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::information(this, tr("BeeGui 1V0"),
                                   tr("Contact me: "
                                      "johann.schmid@ur.de"),
                                   QMessageBox::Ok);

}

void MainWindow::setInterface(int currentIndex){
    qDebug() << currentIndex;
    qDebug() << interfaceList.value(currentIndex);
    if (currentIndex > -1 && fileName != nullptr){
        interfaceValue = interfaceList.value(currentIndex);
        ui->actionStart->setEnabled(true);
    }
    else
    {
        ui->actionStart->setEnabled(false);
    }

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}
