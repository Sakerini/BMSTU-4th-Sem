package com.computergraphic.lab10.geometry;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

import java.util.HashMap;
import java.util.LinkedHashMap;

public class FloatHorizont {

    private Func func = null;
    private PixelWriter pw = null;
    private GraphicsContext gc = null;
    private double width = 0;
    private double height = 0;

    private double minx = 0;
    private double maxx = 0;
    private double stepx = 0;

    private double minz = 0;
    private double maxz = 0;
    private double stepz = 0;

    // For rotation
    private double rx = 0;
    private double ry = 0;
    private double rz = 0;

    private double scale = 30;


    public FloatHorizont() {

    }

    public FloatHorizont(GraphicsContext gc,
                         double minx, double maxx, double stepx,
                         double minz, double maxz, double stepz, Func func) {
        setGraphicContext(gc);
        setFunc(func);
        setXs(minx, maxx, stepx);
        setZs(minz, maxz, stepz);

    }

    public void setGraphicContext(GraphicsContext gc) {
        this.gc = gc;
        this.pw = gc.getPixelWriter();
        this.width = gc.getCanvas().getWidth();
        this.height = gc.getCanvas().getHeight();
    }

    public void setFunc(Func func) {
        this.func = func;
    }

    public void setXs(double minx, double maxx, double stepx) {
        this.minx = minx;
        this.maxx = maxx;
        this.stepx = stepx;
    }

    public void setZs(double minz, double maxz, double stepz) {
        this.minz = minz;
        this.maxz = maxz;
        this.stepz = stepz;
    }

    public void setRotationX(double radians) {
        rx = radians;
    }

    public void setRotationY(double radians) {
        ry = radians;
    }

    public void setRotationZ(double radians) {
        rz = radians;
    }

    public void setScale(double k) {
        scale = k;
    }

    public Point2D findIntersection(Point2D prev, Point2D cur, LinkedHashMap<Integer, Integer> hor) {
        Integer res_x = prev.getY(), res_y = prev.getY();
        Integer arr_y1 = hor.getOrDefault(prev.getX(), null);
        Integer arr_y2 = hor.getOrDefault(cur.getX(), null);
        if (arr_y1 == null || arr_y2 == null) {
            return null;
        }

        int dx = cur.getX() - prev.getX();
        int dy_cur = cur.getY() - prev.getY();
        int dy_prev = arr_y2 - arr_y1;
        if (dx == 0)
        {
            res_x = cur.getX();
            res_y = hor.getOrDefault(res_x, null);
            if (res_y == null) {
                return null;
            }
        }
        else if (prev.getY() == arr_y1 && cur.getY() == arr_y2)
        {
            res_x = prev.getX();
            res_y = prev.getY();
        }
        else
        {
            double m = dy_cur / (double)(dx);
            if (dy_cur != dy_prev)
            {
                res_x = prev.getX() - (int)Math.round(((prev.getY() - arr_y1) * dx / (double)(dy_cur - dy_prev)));
                res_y = (int)Math.round((res_x - prev.getX()) * m + prev.getY());
            }
        }

        return new Point2D(res_x, res_y);
    }

    public void draw() {
        clean(gc);
        boolean firstCurve = true;
        // <x, y>
        var topCoords = new LinkedHashMap<Integer, Integer>();
        var botCoords = new LinkedHashMap<Integer, Integer>();
        for (int i = -(int)(width / 2); i < width / 2; i++) {
            topCoords.put(i, -  (int)height / 2);
            botCoords.put(i, (int)height / 2);
        }

        // Для каждой секущей плосковти
        for (var z = maxz; z >= minz; z -= stepz) {

            boolean firstPoint = true;

            // 2. Для каждой точки, расположеной на кривой, полученой
            //    в текущей секущей плоскости
            for(var x = minx; x <= maxx; x += stepx) {
                var y = func.applyFunc(x, z);

                // 1. Обработка левое баковое ребро
                if (firstPoint && !firstCurve) {
                    drawHorizont(
                            to2D(transform(new Point3D(x, y, z))),
                            to2D(transform(new Point3D(x, func.applyFunc(x, z + stepz), z + stepz))),
                            topCoords, botCoords);
                }

                if (!firstPoint) {
                    Point2D curr = to2D(transform(new Point3D(x, y, z)));
                    Point2D prev = to2D(transform(new Point3D(x - stepx,
                            func.applyFunc(x - stepx, z), z)));
                    int visCurr = isVisible(curr, topCoords, botCoords);
                    int visPrev = isVisible(prev, topCoords, botCoords);

                    if (visCurr != 0 && visPrev != 0) {
                        // if both are visible
                        drawHorizont(prev, curr, topCoords, botCoords);
                    } else if (visCurr == 0) {
                        // if only prev is visible
                        if (visPrev == 1) {
                            var intersection = findIntersection(prev, curr, topCoords);
                            drawHorizont(prev, intersection, topCoords, botCoords);
                        } else if (visPrev == -1) {
                            var intersection = findIntersection(prev, curr, botCoords);
                            drawHorizont(prev, intersection, topCoords, botCoords);
                        }
                    } else {
                        // if only curr is visible
                        if (visCurr == 1) {
                            var intersection = findIntersection(prev, curr, topCoords);
                            drawHorizont(intersection, curr, topCoords, botCoords);
                        } else if (visCurr == -1) {
                            var intersection = findIntersection(prev, curr, botCoords);
                            drawHorizont(intersection, curr, topCoords, botCoords);
                        }
                        // if both are unvisible continue
                    }
                }

                firstPoint = false;
            }

            // 2.7 Обработать правое баковое ребро
            if (!firstCurve) {
                //var prev = new Point3D(maxx, func.applyFunc(maxx, z - stepz), z - stepz);
                //var curr = new Point3D(maxx, func.applyFunc(maxx, z), z);
                //drawHorizont(to2D(transform(prev)), to2D(transform(curr)), topCoords, botCoords);
            }
            firstCurve = false;
        }
    }

    private void drawHorizont(Point2D from, Point2D to,
                              LinkedHashMap<Integer, Integer> top, LinkedHashMap<Integer, Integer> bot) {
        if (from == null || to == null)
            return;
        if (from.getX() > to.getX()){
            Point2D tmp= from;
            from =  to;
            to = tmp;
        }

        int dx = to.getX() - from.getX();
        int dy = to.getY() - from.getY();

        if (dx == 0)
        {
            top.put(from.getX(), Math.max(from.getY(), top.get(from.getX())));
            bot.put(from.getX(), Math.min(from.getY(), bot.get(from.getX())));
            strokeLine(from, to);
        }
        else {
            Point2D prev = new Point2D(from.getX(), to.getY());
            double m = (dy) / (double) (dx);
            for (int x = from.getX(); x <= to.getX(); x++) {
                int y = (int)Math.round(m * (x - from.getX()) + from.getY());

                top.put(x, Math.max(top.get(x), y));
                bot.put(x, Math.min(bot.get(x), y));

                Point2D cur = new Point2D(x, y);
                strokeLine(prev, cur);
                prev = cur;
            }
        }
    }

    void addPixel(Point2D p) {
        pw.setColor(p.getX(), p.getY(), Color.BLACK);
    }

    private Point2D to2D(Point3D p) {
        return new Point2D((int)Math.round(p.getX()), (int)Math.round(p.getY()));
    }

    private int isVisible(Point2D p,
                              HashMap<Integer, Integer> top, HashMap<Integer, Integer> bot) {
        var topY = top.getOrDefault(p.getX(), null);
        var botY = bot.getOrDefault(p.getX(), null);
        var y = p.getY();
        var x = p.getX();
        if(topY == null || botY == null)
            return 0;
        if (y < top.get(x) && y > bot.get(x))
            return 0;
        if (y >= top.get(x))
            return 1;
        return -1;
    }


    private Point3D transform(Point3D p) {
        p.rotate(rx, ry, rz);
        p.scale(scale);

        return p;
    }

    private void clean(GraphicsContext gc) {
        gc.clearRect(-width / 2, -height / 2, width, height);
    }

    private void strokeLine(Point2D p1, Point2D p2) {
        gc.strokeLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }


}
