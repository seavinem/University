#include "chartview.h"

ChartView::ChartView(QWidget *parent) : QChartView(new QChart(), parent) {
    m_chart = chart();
    m_chart->setTitle("Simple Histogram");
    m_series = new QBarSeries();
    m_chart->addSeries(m_series);

    m_axisX = new QValueAxis();
    m_axisX->setRange(0, 100); // Example range
    m_chart->addAxis(m_axisX, Qt::AlignBottom);
    m_series->attachAxis(m_axisX);

    m_axisY = new QValueAxis();
    m_axisY->setRange(0, 50); // Example range
    m_chart->addAxis(m_axisY, Qt::AlignLeft);
    m_series->attachAxis(m_axisY);
}

void ChartView::setData(const QVector<int>& data) {
    m_series->clear();
    QBarSet* set = new QBarSet("Data");
    for (int value : data) {
        *set << value;
    }
    m_series->append(set);
    m_axisX->setRange(0, data.size()); // Set correct range for X-axis
    m_axisY->setRange(0, *std::max_element(data.begin(), data.end())); // Set correct range for Y-axis
}
