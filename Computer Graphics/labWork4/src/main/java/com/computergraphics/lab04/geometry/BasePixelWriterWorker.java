package com.computergraphics.lab04.geometry;

import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

public abstract class BasePixelWriterWorker implements ISpectre, ICurve {

    protected Color color;
    protected PixelWriter pw = null;

    private BasePixelWriterWorker(Color color) {
        setColor(color);
    }

    public BasePixelWriterWorker(PixelWriter pw, Color color) {
        setColor(color);
        setPixelWriter(pw);
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public Color getColor() {
        return color;
    }

    public void setPixelWriter(PixelWriter pw) {
        this.pw = pw;
    }

    public PixelWriter getPixelWriter() {
        return pw;
    }

    public abstract void drawCircle(int x, int y, int r);
    public abstract void drawEllipse(int x, int y, int rx, int ry);

    protected void addPoint(int x, int y) {
        pw.setColor(x, y, color);
    }

    protected void add4Points(int xc, int yc, int dx, int dy) {
        pw.setColor(xc - dx, yc - dy, color);
        pw.setColor(xc + dx, yc + dy, color);
        pw.setColor(xc - dx, yc + dy, color);
        pw.setColor(xc + dx, yc - dy, color);
    }

    public void drawSpectreCircle(int x, int y, int r, int dr, int n) {
        int rCurr = r;

        for (int i = 0; i < n; i++) {
            drawCircle(x, y, rCurr);
            rCurr += dr;
        }
    }

    public void drawSpectreEllipse(int x, int y, int rx, int ry, int drx, int dry, int n) {
        int rxCurr = rx;
        int ryCurr = ry;

        for (int i = 0; i < n; i++) {
            drawEllipse(x, y, rxCurr, ryCurr);
            rxCurr += drx;
            ryCurr += dry;
        }
    }

    // TODO
    public long testTimeCircle(int r0, int rn, int step) {

        long start = System.currentTimeMillis();
        // drawCircle();
        long end = System.currentTimeMillis();

        return end - start;
    }

    // TODO
    public long testTimeEllipse(int r0, int rn, int step) {
        long start = System.currentTimeMillis();

        long end = System.currentTimeMillis();

        return end - start;
    }
}
