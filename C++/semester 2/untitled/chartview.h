#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>

QT_CHARTS_USE_NAMESPACE

    class ChartView : public QChartView {
    Q_OBJECT
public:
    explicit ChartView(QWidget *parent = nullptr);
    void setData(const QVector<int>& data);
private:
    QChart* m_chart;
    QBarSeries* m_series;
    QValueAxis* m_axisX;
    QValueAxis* m_axisY;
};

#endif // CHARTVIEW_H
