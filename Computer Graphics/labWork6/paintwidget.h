#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <cmath>
#include <QtCore>

enum Mode { SEED, FIGURE, ARBITRARY };

class PaintWidget : public QWidget
{

    Q_OBJECT

public:
    explicit PaintWidget(QWidget *parent = nullptr);
    void setBGColor(QColor &color);
    void setBordersColor(QColor &color);
    void setFillColor(QColor &color);
    void drawByButton(const QPoint &point);
    void finishByButton();
    void clearAll();
    void clearFill();
    void fillFigure(const int &time);
    void setSeedMode();
    void setFigureMode();
    void setArbitraryMode();
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    Mode mode;
    QPoint seed_pos;
    int start_point_index;
    QPoint last_point;
    QPoint arbitrary_last_point;
    QVector<QPoint> points;
    QVector<std::pair<int, int>> edges;
    QVector<QPoint> arbitrary_points;
    QVector<std::pair<int, int>> arbitrary_edges;
    QImage *image;
    int widget_height;
    int widget_width;
    QColor borders_color;
    QColor fill_color;
    QColor bg_color;
    bool drawing_enabled;

    void redrawImage();
    void finishFigure(QPainter &painter);
    void addLine(QPainter &painter, const QPoint &cur_point);
    void setStartPoint(QPainter &painter, const QPoint &cur_point);
    void drawBresenham(QPainter &painter, const QPoint &first, const QPoint &second);
    void fillLine(int &x_left, int &x_right, QPainter &painter, const QPoint &cur);
    void findSeed(QStack<QPoint> &stack, const int &xleft, const int &xright, const int &y);
    void sleepFeature(const int &time);
    void setSeed(const QPoint &seed);
    int sign(int x);

signals:
    void pointsChanged(const int&, const int&);
    void seedChanged(const QPoint &);
};

#endif // DRAWWIDGET_H
