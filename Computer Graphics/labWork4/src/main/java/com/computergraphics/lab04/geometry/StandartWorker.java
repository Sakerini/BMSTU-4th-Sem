package com.computergraphics.lab04.geometry;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class StandartWorker implements ISpectre, ICurve {

    private GraphicsContext gc = null;
    protected Color color;

    private StandartWorker(Color color) {
        setColor(color);
    }

    public StandartWorker(GraphicsContext gc, Color color) {
        setGraphicsContext(gc);
        setColor(color);
    }

    public void setColor(Color color) {
        if (gc != null) {
            gc.setStroke(color);
        }

        this.color = color;
    }

    public Color getColor() {
        return color;
    }

    public void setGraphicsContext(GraphicsContext gc) {
        this.gc = gc;
    }

    public GraphicsContext getGraphicsContext() {
        return gc;
    }

    @Override
    public void drawCircle(int x, int y, int r) {
        gc.strokeOval(x - r, y - r, 2 * r, 2 * r);
    }

    @Override
    public void drawEllipse(int x, int y, int rx, int ry) {
        gc.strokeOval(x - rx, y - ry, 2 * rx, 2 * ry);
    }

    @Override
    public void drawSpectreCircle(int x, int y, int r, int dr, int n) {
        int rCurr = r;

        for (int i = 0; i < n; i++) {
            drawCircle(x, y, rCurr);
            rCurr += dr;
        }
    }

    @Override
    public void drawSpectreEllipse(int x, int y, int rx, int ry, int drx, int dry, int n) {
        int rxCurr = rx;
        int ryCurr = ry;

        for (int i = 0; i < n; i++) {
            drawEllipse(x, y, rxCurr, ryCurr);
            rxCurr += drx;
            ryCurr += dry;
        }
    }
}
