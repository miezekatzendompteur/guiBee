#include "mythread.h"
#include <QSerialPort>
#include <QDebug>

myThread::myThread(const QString &interfaceName, QObject *parent)
    : QObject{parent}
{
    myPort = new QSerialPort();
    connect(myPort, &QSerialPort::readyRead, this, &myThread::readData);
    qDebug() << "InterfaceName: " << interfaceName;
    myPort->setPortName(interfaceName);
    myPort->setBaudRate(QSerialPort::Baud115200);
    if(!myPort->open(QIODevice::ReadWrite)){
        qDebug() << "Interface failed";
    }
    myPort->write("start\r\n");
    myPort->flush();
    qDebug() << "Interface open " << QThread::currentThread();
}

myThread::~myThread(){
    myPort->write("stop\r\n");
    myPort->flush();
    myPort->close();
    qDebug() << "Interface close";
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

