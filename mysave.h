#ifndef MYSAVE_H
#define MYSAVE_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QFile>

class mySave : public QObject
{
    Q_OBJECT
    QString m_string;
public:
    explicit mySave(const QString &stringFileName = QString(), QObject *parent = nullptr);
    ~mySave();

private:
    QFile file;

signals:

public slots:
    void writeFile(QString);
    void closeFile();
    void startFile(QString);
};

#endif // MYSAVE_H
