#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QSerialPort>

class myThread : public QObject
{
    Q_OBJECT
    QSerialPort *myPort;
public:
    explicit myThread(const QString &interfaceName = QString(), QObject *parent = nullptr);
    ~myThread();


public slots:
    void closeInterface();
    void readData();

signals:
    void emitData(const QByteArray &);

};

#endif // MYTHREAD_H
