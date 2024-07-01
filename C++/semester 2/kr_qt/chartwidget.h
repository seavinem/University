#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPen>
#include <QBrush>

class ChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChartWidget(QWidget *parent = nullptr);

    ~ChartWidget() {};
    ChartWidget(const ChartWidget &other);
    ChartWidget &operator=(const ChartWidget &other);

    void setData(const QVector<int> &data);
    const QVector<int> &data() const { return m_data; }

    void setPenColor(const QColor &color);
    QColor penColor() const { return m_pen.color(); }

    void setPenWidth(int width);
    int penWidth() const { return m_pen.width(); }

    void setPenStyle(Qt::PenStyle style);
    Qt::PenStyle penStyle() const { return m_pen.style(); }

    void setBrushColor(const QColor &color);
    QColor brushColor() const { return m_brush.color(); }

    bool isModified() const { return m_modified; }

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QVector<int> m_data;
    QPen m_pen;
    QBrush m_brush;
    bool m_modified;

    void draw3DBarChart(QPainter &painter);
};

#endif // CHARTWIDGET_H
