#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <cmath>
#include <QtCore>

class PaintWidget : public QWidget
{

    Q_OBJECT

public:
    explicit PaintWidget(QWidget *parent = nullptr);
    void setBGColor(QColor &color);
    void setBordersColor(QColor &color);
    void setFillColor(QColor &color);
    void setSeparatorColor(QColor &color);
    void drawByButton(QPoint &point);
    void finishByButton();
    void clearAll();
    void clearFill();
    void fillFigure(const int &time);
    void sleepFeature(const int &time);
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    int start_point_index;
    int x_max;
    int x_min;
    int x_sep;
    QPoint last_point;
    QVector<QPoint> points;
    QVector<std::pair<int, int>> edges;
    QImage *image;
    int widget_height;
    int widget_width;
    QColor borders_color;
    QColor fill_color;
    QColor bg_color;
    QColor separator_color;
    bool drawing_enabled;

    void redrawImage();
    void finishFigure(QPainter &painter);
    void addLine(QPainter &painter, const QPoint &cur_point);
    void setStartPoint(QPainter &painter, const QPoint &cur_point);
    void findBorders();
    void setSeparator(QPainter &painter);
    void drawPoint(QPainter &painter, const int &x, const int &y);
    void drawBresenham(QPainter &painter, const QPoint &first, const QPoint &second);
    int sign(int x);
signals:
    void pointsChanged(const int&, const int&);
};

#endif // PAINTWIDGET_H
