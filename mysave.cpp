#include "mysave.h"
#include <QDebug>

mySave::mySave(const QString &stringFileName, QObject *parent)
    : QObject(parent)
    , m_string(stringFileName)
{
    qDebug() << "Thread open " << QThread::currentThread()  << stringFileName;
}

void mySave::startFile(QString fileName){
    file.setFileName(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
}

void mySave::writeFile(QString writeValue)
{
    QTextStream out(&file);
    out << writeValue;
}

void mySave::closeFile(){
    file.flush();
    file.close();
}
