#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    widget_width = 740;
    widget_height = 620;
    mode = FIGURE;
    seed_pos = QPoint(0, 0);
    bg_color = Qt::white;
    borders_color = Qt::black;
    fill_color = Qt::blue;
    drawing_enabled = false;
    image = new QImage(widget_width, widget_height, QImage::Format_RGB32);
    image->fill(bg_color);
    setGeometry(20, 20, widget_width, widget_height);
}

void PaintWidget::redrawImage()
{
    image->fill(bg_color);
    QPainter painter(image);
    painter.setPen(borders_color);

    for (const QPoint &point: points)
    {
        painter.drawPoint(point);
    }

    for (const auto &edge: edges)
    {
        drawBresenham(painter, points[edge.first], points[edge.second]);
    }

    for (const QPoint &point: arbitrary_points)
    {
        painter.drawPoint(point);
    }

    for (const auto &edge: arbitrary_edges)
    {
        painter.drawLine(arbitrary_points[edge.first], arbitrary_points[edge.second]);
    }

    update();
}

void PaintWidget::addLine(QPainter &painter, const QPoint &cur_point)
{
    edges.push_back(std::make_pair(points.size() - 1, points.size()));
    if (cur_point.y() < last_point.y())
        qSwap(edges.back().first, edges.back().second);
    points.push_back(cur_point);
    drawBresenham(painter, last_point, cur_point);
    last_point = cur_point;
    update();
    emit pointsChanged(points.size(), start_point_index);
}

void PaintWidget::setStartPoint(QPainter &painter, const QPoint &cur_point)
{
    start_point_index = points.size();
    points.push_back(cur_point);
    painter.drawPoint(cur_point);
    last_point = cur_point;
    drawing_enabled = true;
    update();
}

void PaintWidget::drawBresenham(QPainter &painter, const QPoint &first, const QPoint &second)
{

    int xn = first.x();
    int yn = first.y();
    int xk = second.x();
    int yk = second.y();
    if (xn == xk && yn == yk)
    {
        painter.drawPoint(xk, yk);
    }
    else
    {
        int dx = xk - xn;
        int dy = yk - yn;
        int sx = sign(dx);
        int sy = sign(dy);
        dx = abs(dx);
        dy = abs(dy);
        bool exchange;
        if (dy > dx)
        {
            qSwap(dx, dy);
            exchange = true;
        }
        else
            exchange = false;
        int e = 2 * dy - dx;
        int x = xn, y = yn;
        for (int i = 0; i < dx + 1; i++)
        {
            painter.drawPoint(x, y);
            if (e >= 0)
            {
                if (exchange)
                    x += sx;
                else
                    y += sy;
                e -= 2 * dx;
            }
            if (exchange)
                y += sy;
            else
                x += sx;
            e += 2 * dy;
        }
    }

//    painter.drawLine(first, second);
}

int PaintWidget::sign(int x)
{
    if (x > 0)
        return 1;
    else if (x == 0)
        return 0;
    return -1;
}

void PaintWidget::fillLine(int &x_left, int &x_right, QPainter &painter, const QPoint &cur)
{
    int x = cur.x() + 1;
    int y = cur.y();
    painter.drawPoint(cur);
    while (x < widget_width && image->pixelColor(x, y) != borders_color)
    {
        painter.drawPoint(x, y);
        x++;
    }
    x_right = x - 1;
    x = cur.x() - 1;
    while (x >= 0 && image->pixelColor(x, y) != borders_color)
    {
        painter.drawPoint(x, y);
        x--;
    }
    x_left = x + 1;
}

void PaintWidget::findSeed(QStack<QPoint> &stack, const int &x_left, const int &x_right, const int &y)
{
    bool fl;
    int x = x_left;
    int xt;
    while (x <= x_right)
    {
        fl = false;
        while ((x <= x_right) &&
               (image->pixelColor(x, y) != borders_color) &&
               (image->pixelColor(x, y) != fill_color))
        {
            fl = true;
            x++;
        }
        if (fl == true)
        {
            if ((x == x_right) &&
                (image->pixelColor(x, y) != borders_color) &&
                (image->pixelColor(x, y) != fill_color))
            {
                stack.push(QPoint(x, y));
            }
            else
            {
                stack.push(QPoint(x - 1, y));
            }
        }
        xt = x;
        while ((x <= x_right) &&
               ((image->pixelColor(x, y) == borders_color) ||
               (image->pixelColor(x, y) == fill_color)))
        {
            x++;
        }
        if (x == xt)
        {
            x++;
        }
    }
}

void PaintWidget::finishFigure(QPainter &painter)
{void PaintWidget::findSeed(QStack<QPoint> &stack, const int &x_left, const int &x_right, const int &y)
    {
        bool fl;
        int x = x_left;
        int xt;
        while (x <= x_right)
        {
            fl = false;
            while ((x <= x_right) &&
                   (image->pixelColor(x, y) != borders_color) &&
                   (image->pixelColor(x, y) != fill_color))
            {
                fl = true;
                x++;
            }
            if (fl == true)
            {
                if ((x == x_right) &&
                    (image->pixelColor(x, y) != borders_color) &&
                    (image->pixelColor(x, y) != fill_color))
                {
                    stack.push(QPoint(x, y));
                }
                else
                {
                    stack.push(QPoint(x - 1, y));
                }
            }
            xt = x;
            while ((x <= x_right) &&
                   ((image->pixelColor(x, y) == borders_color) ||
                   (image->pixelColor(x, y) == fill_color)))
            {
                x++;
            }
            if (x == xt)
            {
                x++;
            }
        }
    }


    if (start_point_index + 2 < points.size())
    {
        edges.push_back(std::make_pair(points.size() - 1, start_point_index));
        if (last_point.y() > points[start_point_index].y())
            qSwap(edges.back().first, edges.back().second);
        drawBresenham(painter, last_point, points[start_point_index]);
        drawing_enabled = false;
        emit pointsChanged(points.size(), points.size());
        update();
    }
}

void PaintWidget::setBGColor(QColor &color)
{
    bg_color.setRgb(color.rgb());
    redrawImage();
}

void PaintWidget::setBordersColor(QColor &color)
{
    borders_color.setRgb(color.rgb());
    redrawImage();
}

void PaintWidget::setFillColor(QColor &color)
{
    fill_color.setRgb(color.rgb());
}

void PaintWidget::drawByButton(const QPoint &cur_point)
{
    QPainter painter(image);
    painter.setPen(borders_color);
    if (drawing_enabled && mode == FIGURE)
    {
        addLine(painter, cur_point);
    }
    else if (mode == FIGURE)
    {
        setStartPoint(painter, cur_point);
    }
    else if (mode == SEED)
    {
        setSeed(cur_point);
    }
}

void PaintWidget::finishByButton()
{
    if (drawing_enabled)
    {
        QPainter painter(image);
        painter.setPen(borders_color);
        finishFigure(painter);
    }
}

void PaintWidget::clearAll()
{
    image->fill(bg_color);
    if (!points.empty())
    {
        points.clear();
        edges.clear();
        drawing_enabled = false;
        emit pointsChanged(points.size(), points.size());
    }
    if (!arbitrary_points.empty())
    {
        arbitrary_edges.clear();
        arbitrary_points.clear();
    }
    update();
}

void PaintWidget::clearFill()
{
    redrawImage();
}

void PaintWidget::fillFigure(const int &time)
{
    setbuf(stdout, NULL);
    float fTimeStart = clock()/(float)CLOCKS_PER_SEC;
    QPainter painter(image);
    if (drawing_enabled)
    {
        painter.setPen(borders_color);
        finishFigure(painter);
    }
    if (!drawing_enabled)
    {
        QPoint cur;
        int x_left, x_right;
        QStack<QPoint> stack;
        painter.setPen(fill_color);
        stack.push(seed_pos);
        while (!stack.empty())
        {
            cur = stack.pop();
            if (image->pixelColor(cur) != borders_color)
            {
                fillLine(x_left, x_right, painter, cur);
                if (cur.y() < widget_height - 1)
                {
                    findSeed(stack, x_left, x_right, cur.y() + 1);
                }
                if (cur.y() > 0)
                {
                    findSeed(stack, x_left, x_right, cur.y() - 1);
                }
                sleepFeature(time);
                update();
            }
        }
    }
    float fTimeStop = clock()/(float)CLOCKS_PER_SEC;
    printf("Длительность процесса %f секунд\n", fTimeStop-fTimeStart);
}

void PaintWidget::setSeedMode()
{
    mode = SEED;
}

void PaintWidget::setFigureMode()
{
    mode = FIGURE;
}

void PaintWidget::setArbitraryMode()
{
    mode = ARBITRARY;
}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
    QPainter painter(image);
    painter.setPen(borders_color);
    if (drawing_enabled && mode == FIGURE)
    {
        if (event->button() == Qt::LeftButton)
        {
            QPoint cur_point = event->pos();
            if (event->modifiers() == Qt::ShiftModifier)
            {
                if (abs(last_point.x() - cur_point.x()) <= abs(last_point.y() - cur_point.y()))
                {
                    cur_point.setX(last_point.x());
                }
                else
                {
                    cur_point.setY(last_point.y());
                }
            }
            addLine(painter, cur_point);
        }
        else if (event->button() == Qt::RightButton)
        {
            finishFigure(painter);
        }
    }
    else if (mode == FIGURE)
    {
        if (event->button() == Qt::LeftButton)
        {
            QPoint cur_point = event->pos();
            setStartPoint(painter, cur_point);
        }
    }
    else if (mode == SEED)
    {
        if (event->button() == Qt::LeftButton)
        {
            setSeed(event->pos());
        }
    }
    else if (mode == ARBITRARY)
    {
        if (event->button() == Qt::LeftButton)
        {
            QPoint cur = event->pos();
            painter.drawPoint(cur);
            arbitrary_points.push_back(cur);
            arbitrary_last_point = cur;
            update();
        }
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (mode == ARBITRARY)
    {
        if (event->button() == Qt::LeftButton)
        {
            QPainter painter(image);
            painter.setPen(borders_color);
            QPoint cur = event->pos();
            arbitrary_edges.push_back(std::make_pair(arbitrary_points.size(), arbitrary_points.size() - 1));
            painter.drawLine(cur, arbitrary_last_point);
            arbitrary_points.push_back(cur);
            arbitrary_last_point = cur;
            update();
        }
    }
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *image);
    Q_UNUSED(event);
}

void PaintWidget::sleepFeature(const int &time)
{
    QTime end = QTime::currentTime().addMSecs(time);
    while (QTime::currentTime() < end)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
    }
    return;
}

void PaintWidget::setSeed(const QPoint &seed)
{
    seed_pos = seed;
    emit seedChanged(seed_pos);
}
