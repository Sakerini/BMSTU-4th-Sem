package com.computergraphics.lab04.geometry;

import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

public class CanonEq extends BasePixelWriterWorker {

    public CanonEq(PixelWriter pw, Color color) {
        super(pw, color);
    }

    @Override
    public void drawCircle(int xc, int yc, int r) {
        //x^2+y^2=R^2
        int a2 =r * r;
        double deltax = 0, deltay = r;
        int dx, dy;
        int step = 1;

        // производня для остановки цикла
        int flag = (int)Math.round(r / Math.sqrt(2)); ;
        for (; deltax <= flag; deltax += step)
        {
            deltay = Math.sqrt(a2 - deltax * deltax);

            dx = (int)Math.round(deltax);
            dy = (int)Math.round(deltay);

            add4Points(xc, yc, dx, dy);
            add4Points(xc, yc, dy, dx);
        }
    }

    @Override
    public void drawEllipse(int xc, int yc, int rx, int ry) {
        // x^2/a^2+y^2/b^2=1

        int rx2 = rx * rx;//a^2
        int ry2 = ry * ry;//b^2

        // Производная при y`=-1 , является границей для оптимального рисования
        // y`=-b/a*x/sqrt(a^2-x^2)
        int rdel2 =(int)Math.round(rx2 / Math.sqrt(rx2 + ry2));

        int x = 0, y = 0;
        double m = (double)ry / rx;//b/a
        for (x = 0; x <= rdel2; x++)
        {
            y = (int)Math.round(Math.sqrt(rx2 - x * x) * m);  //y=b/a*sqrt(a^2-x^2)
            add4Points(xc, yc, x, y);
        }

        // Производная , является границей для оптимального рисования
        rdel2 = (int)Math.round(ry2 / Math.sqrt(rx2 + ry2));
        m = 1 / m; // переворачиваем m

        for (y = 0; y <= rdel2; y++)
        {
            x = (int)Math.round(Math.sqrt(ry2 - y * y) * m); // аналогично выше
            add4Points(xc, yc, x, y);
        }
    }
}
