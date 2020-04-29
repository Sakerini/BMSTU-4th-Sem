package com.computergraphics.lab04.geometry;

import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

public class MiddlePoint extends BasePixelWriterWorker {

    public MiddlePoint(PixelWriter pw, Color color) {
        super(pw, color);
    }

    @Override
    public void drawCircle(int xc, int yc, int r) {
        int x = 0;
        int y = r;
        int p = 1 - r;

        add4Points(xc, yc, x, y);
        add4Points(xc, yc, y, x);

        while (x < y)
        {
            x++;
            if (p < 0)
            {
                p += 2 * x + 1;
            }
            else
            {
                y--;
                p += 2 * (x - y) + 1;
            }

            add4Points(xc, yc, x, y);
            add4Points(xc, yc, y, x);
        }
    }

    @Override
    public void drawEllipse(int xc, int yc, int rx, int ry) {
        int rx2 = rx * rx;
        int ry2 = ry * ry;
        int r2y2 = 2 * ry2;
        int r2x2 = 2 * rx2;

        int rdel2 =(int)(rx2 / Math.sqrt(rx2 + ry2)); //производная для ограничения


        int x = 0;
        int y = ry;

        int df = 0;
        int f = (int)(ry2 - rx2 * y + 0.25 * rx2 + 0.5);

        int delta = -r2x2 * y;
        for (x = 0; x <= rdel2; x += 1)
        {

            add4Points(xc, yc, x, y);
            if (f >= 0)
            {
                y -= 1;
                delta += r2x2;
                f += delta;
            }
            df += r2y2; ;
            f += df + ry2;
        }


        delta = r2y2 * x ;
        f +=(int) (-ry2 * (x + 0.75) - rx2 * (y - 0.75));
        df = -r2x2 * y;


        for (; y >= 0; y -= 1)
        {

            add4Points(xc, yc, x, y);

            if (f < 0)
            {
                x += 1;
                delta += r2y2;
                f += delta;
            }
            df += r2x2;
            f += df + rx2;
        }
    }

}
