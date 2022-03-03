#include "graph.h"
#include "mainwindow.h"


graph::graph(QWidget *parent)
    : QWidget{parent}
{
    series = new QLineSeries();

    series->append(0, 1);
    series->append(2, 1);
    series->append(2, 0);
    series->append(4, 0);
    series->append(4, 1);
    series->append(6, 1);
    series->append(6, 0);
    series->append(8, 0);
    series->append(8, 1);

    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3)
                << QPointF(20, 2);

    chart = new QChart();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(w->ui->lineGraph);

}
