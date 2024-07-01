#include "chartwidget.h"
#include <QPainter>
#include <QResizeEvent>
#include <QRandomGenerator>

ChartWidget::ChartWidget(QWidget *parent)
    : QWidget(parent), m_pen(Qt::black, 1, Qt::SolidLine), m_brush(Qt::lightGray), m_modified(false)
{
    QRandomGenerator *randomGenerator = QRandomGenerator::global();
    for (int i = 1; i <= 5; ++i) {
        m_data.push_back(randomGenerator->bounded(1, 101));
    }
}

ChartWidget::ChartWidget(const ChartWidget &other)
    : QWidget(other.parentWidget()), m_data(other.m_data), m_pen(other.m_pen), m_brush(other.m_brush), m_modified(other.m_modified)
{
}

ChartWidget &ChartWidget::operator=(const ChartWidget &other)
{
    if (this != &other) {
        m_data = other.m_data;
        m_pen = other.m_pen;
        m_brush = other.m_brush;
        m_modified = other.m_modified;
        update();
    }
    return *this;
}

void ChartWidget::setData(const QVector<int> &data)
{
    m_data = data;
    m_modified = true;
    update();
}

void ChartWidget::setPenColor(const QColor &color)
{
    if (m_pen.color() != color) {
        m_pen.setColor(color);
        m_modified = true;
        update();
    }
}

void ChartWidget::setPenWidth(int width)
{
    if (m_pen.width() != width) {
        m_pen.setWidth(width);
        m_modified = true;
        update();
    }
}

void ChartWidget::setPenStyle(Qt::PenStyle style)
{
    if (m_pen.style() != style) {
        m_pen.setStyle(style);
        m_modified = true;
        update();
    }
}

void ChartWidget::setBrushColor(const QColor &color)
{
    if (m_brush.color() != color) {
        m_brush.setColor(color);
        m_modified = true;
        update();
    }
}

void ChartWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(m_pen);
    painter.setBrush(m_brush);
    draw3DBarChart(painter);
}

void ChartWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    update();
}


void ChartWidget::draw3DBarChart(QPainter &painter)
{
    if (m_data.isEmpty())
        return;

    int leftMargin = 50;
    int barWidth = (width() - leftMargin) / (m_data.size() * 2);
    int maxBarHeight = height() - 75;
    int maxValue = *std::max_element(m_data.begin(), m_data.end());
    int depth = barWidth / 3;


    painter.drawLine(leftMargin, height() - 30, leftMargin, 5);

    painter.drawLine(leftMargin + 5, 15, leftMargin, 5);
    painter.drawLine(leftMargin - 5, 15, leftMargin, 5);

    painter.drawText(leftMargin - 35, 15, QString("Y"));


    painter.drawLine(leftMargin, height() - 30, width() - 5, height() - 30);

    painter.drawLine(width() - 15, height() - 35, width() - 5, height() - 30);
    painter.drawLine(width() - 15, height() - 25, width() - 5, height() - 30);

    painter.drawText(width() - 15, height() - 10, QString("X"));


    painter.drawLine(leftMargin, height() - 30, leftMargin + depth * 10, height() - 30 - depth * 10);

    // Draw Y-axis markings
    int numMarks = 10;
    for (int i = 0; i <= numMarks; ++i) {
        int y = height() - 30 - (i * maxBarHeight / numMarks);
        painter.drawLine(leftMargin - 5, y, leftMargin, y);
        int markValue = (i * maxValue) / numMarks;
        painter.drawText(leftMargin - 40, y + 5, QString::number(markValue));
    }

    for (int i = 0; i < m_data.size(); ++i) {
        int barHeight = (m_data[i] * maxBarHeight) / (maxValue > 0 ? maxValue : 1);

        QRect frontRect(i * 2 * barWidth + barWidth / 2 + leftMargin, height() - barHeight - 30, barWidth, barHeight);
        painter.drawRect(frontRect);

        QPolygon topPolygon;
        topPolygon << QPoint(frontRect.left(), frontRect.top())
                   << QPoint(frontRect.right(), frontRect.top())
                   << QPoint(frontRect.right() + depth, frontRect.top() - depth)
                   << QPoint(frontRect.left() + depth, frontRect.top() - depth);
        painter.drawPolygon(topPolygon);

        QPolygon sidePolygon;
        sidePolygon << QPoint(frontRect.right(), frontRect.top())
                    << QPoint(frontRect.right(), frontRect.bottom())
                    << QPoint(frontRect.right() + depth, frontRect.bottom() - depth)
                    << QPoint(frontRect.right() + depth, frontRect.top() - depth);
        painter.drawPolygon(sidePolygon);

        painter.drawText(frontRect, Qt::AlignCenter, QString::number(m_data[i]));
    }

    for (int i = 0; i < m_data.size(); ++i) {
        int x = i * 2 * barWidth + barWidth + leftMargin;
        painter.drawText(x - barWidth / 2, height() - 10, QString::number(i + 1));
    }
}


