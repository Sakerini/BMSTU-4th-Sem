package com.computergraphics.lab04.geometry;

import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

public class ParamEq extends BasePixelWriterWorker {

    public ParamEq(PixelWriter pw, Color color) {
        super(pw, color);
    }

    @Override
    public void drawCircle(int xc, int yc, int r) {
        // x = r * cos(t);
        // y = r * sin(t);
        double d = 1.0 / r;
        for (double t = Math.PI / 4.0; t >= 0; t -= d)
        {
            int dx = (int)Math.round(r * Math.cos(t));
            int dy = (int)Math.round(r * Math.sin(t));

            add4Points(xc, yc, dx, dy);
            add4Points(xc, yc, dy, dx);
        }
    }

    @Override
    public void drawEllipse(int xc, int yc, int rx, int ry) {
        // x = a * cos(t)
        // y = b * sin(t)
        double deltax = 0;
        double deltay = 0;
        int dx = 0, dy = 0;
        double d = 1.0 / Math.max(rx, ry);

        for (double t = Math.PI / 2.0; t >= 0; t -= d)
        {
            deltax = rx * Math.cos(t);
            deltay = ry * Math.sin(t);
            dx = (int)Math.round(deltax);
            dy = (int)Math.round(deltay);

            //add4Points(xc, yc, dx, dy);
            pw.setColor(xc - dx, yc + dy, color);
            pw.setColor(xc + dx, yc - dy, color);
        }
    }
}
