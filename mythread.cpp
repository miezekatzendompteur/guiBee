#include "mythread.h"
#include <QSerialPort>
#include <QDebug>

myThread::myThread(QObject *parent)
    : QObject{parent}
{
    qDebug() << "Thread open " << QThread::currentThread();
}

void myThread::interfaceSerial(){

    myPort = new QSerialPort();
    connect(myPort, &QSerialPort::readyRead, this, &myThread::readData);
    qDebug() << "Init";
    myPort->setPortName("COM4");
    myPort->setBaudRate(QSerialPort::Baud115200);
    if(!myPort->open(QIODevice::ReadWrite)){
        qDebug() << "Interface failed";
    }
    qDebug() << "Interface open " << QThread::currentThread();

    myPort->write("start\r\n");
    myPort->flush();
}

void myThread::readData(){
    if (myPort->canReadLine()){
        const QByteArray data = myPort->readLine();
        qDebug() << "Read: " << data;
        emit emitData (data);
    }



}


void myThread::closeInterface(){
    myPort->write("stop\r\n");
    myPort->flush();
    myPort->close();
    qDebug() << "Interface close";
}

