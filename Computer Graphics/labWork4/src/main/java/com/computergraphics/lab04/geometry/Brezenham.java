package com.computergraphics.lab04.geometry;

import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

public class Brezenham extends BasePixelWriterWorker {

    public Brezenham(PixelWriter pw, Color color) {
        super(pw, color);
    }

    @Override
    public void drawCircle(int xc, int yc, int r) {
        int x = 0, y = r;

        int d = 2 * (1 - r);//первоначальная ошибка
        int d1, d2;

        while (y >= 0)
        {
            add4Points(xc, yc, x, y);

            if (d < 0)  //диагональная точка лежит внутри окружности=>
            {           //ближайшими точками могут быть только диагональная и правая

                d1 = 2 * d + 2 * y - 1;
                if (d1 > 0)//диагональный
                {
                    y -= 1;
                    x += 1;
                    d += 2 * (x - y + 1); // новое расстояние до точки по диагонали
                }
                else      //горизонтальный шаг
                {
                    x += 1;
                    d += 2 * x + 1;
                }
            }
            else if (d == 0) //диагональный шаг
            {
                x += 1;
                y -= 1;
                d += 2 * (x - y + 1);
            }
            else
            {
                d2 = 2 * d - 2 * x - 1;
                if (d2 < 0)//диагональный шаг
                {
                    y -= 1;
                    x += 1;
                    d += 2 * (x - y + 1);
                }
                else //вертикальный
                {
                    y -= 1;
                    d += -2 * y + 1;
                }
            }
        } //end while
    }

    @Override
    public void drawEllipse(int xc, int yc, int rx, int ry) {

        int rx2 = rx * rx;//a^2
        int ry2 = ry * ry;//b^2
        int r2y2 = 2 * ry2;
        int r2x2 = 2 * rx2;
        int x = 0, y = ry;
        //f(x,y)=x^2*b^2+a^2y^2-a^2*b^2=0 из каноического


        //error=b^2*(x+1)^2 + a^2*(y-1)^2-a^2*b^2=
        int d = rx2 + ry2 - r2x2 * y;
        int d1, d2;

        while (y >= 0)
        {
            add4Points(xc, yc, x, y);

            if (d < 0)//гор и диаг
            {
                d1 = 2 * d + r2x2 * y - 1;
                if (d1 > 0) //диагональная
                {
                    y -= 1;
                    x += 1;
                    d += r2y2 * x + ry2 + rx2 - r2x2 * y;//b^2 (2x+1)+a^2(1-2y)
                }
                else     //гор
                {
                    x += 1;
                    d += r2y2 * x + ry2;    //+b^2 (2x+1)
                }
            }
            else if (d == 0)//диагональная
            {
                x += 1;
                y -= 1;
                d += r2y2 * x + ry2 + rx2 - r2x2 * y;
            }
            else
            {
                d2 = 2 * d - r2y2 * x - 1; //2d-b^2x-1
                if (d2 < 0) //диагональная
                {
                    y -= 1;
                    x += 1;
                    d += r2y2 * x + ry2 + rx2 - r2x2 * y;
                }
                else//вертикальная
                {
                    y -= 1;
                    d += rx2 - r2x2 * y;  //a^2(1-2y)
                }
            }
        } //end while
    }

    private void drawEllipse2(int xc, int yc, int rx, int ry) {
        int a2 = rx * rx;
        int b2 = ry * ry;
        int fa2 = 4 * a2;
        int fb2 = 4 * b2;

        int x, y, sigma;
        x = 0;
        y = ry;
        sigma = (2 * b2) + (a2 * (1 - 2 * ry));

        for (x = 0; b2 * x <= a2 * y; x++)
        {
            add4Points(xc, yc, x, y);

            if (sigma >= 0)
            {
                sigma += fa2 * (1 - y);
                y--;
            }
            sigma += b2 * ((4 * x) + 6);
        }

        for (x = rx, y = 0, sigma = 2 * a2 + b2 * (1 - 2 * rx); a2 * y <= b2 * x; y++)
        {
            add4Points(xc, yc, x, y);
            if (sigma >= 0)
            {
                sigma += fb2 * (1 - x);
                x--;
            }
            sigma += a2 * ((4 * y) + 6);
        }
    }
}
