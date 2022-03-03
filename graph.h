#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QLineSeries>
#include <QChart>
#include <QChartView>

class graph : public QWidget
{
    Q_OBJECT
public:
    explicit graph(QWidget *parent = nullptr);
    QLineSeries *series;
    QChart *chart;

signals:

};

#endif // GRAPH_H
