package Drawer;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

public class Line {

    private Color color;
    private int red;
    private int green;
    private int blue;

    private PixelWriter pixelWriter;
    private GraphicsContext gc;

    public Line (Color color, PixelWriter pw, GraphicsContext gc) {
        setColor(color);
        setPixelWriter(pw);
        setGc(gc);
    }


    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
        this.red = (int)(color.getRed() * 255);
        this.green = (int)(color.getGreen() * 255);
        this.blue = (int)(color.getBlue() * 255);
        System.out.printf("rgb: %d %d %d", red, green, blue);
    }

    public PixelWriter getPixelWriter() {
        return pixelWriter;
    }

    public void setPixelWriter(PixelWriter pixelWriter) {
        this.pixelWriter = pixelWriter;
    }

    public GraphicsContext getGc() {
        return gc;
    }

    public void setGc(GraphicsContext gc) {
        this.gc = gc;
    }

    private void addPixel(int x, int y) {
        if (pixelWriter != null)
            pixelWriter.setColor(x, y, color);
    }

    private void addPixel(int x, int y, Color color) {
        if (pixelWriter != null)
            pixelWriter.setColor(x, y, color);
    }


    public void drawDDA(int x1, int y1, int x2, int y2) {
        float dx = x2 - x1;
        float dy = y2 - y1;
        float l;
        float x = x1;
        float y = y1;

        if (dx != 0 || dy != 0) {
            if (Math.abs(dx) > Math.abs(dy)) {
                l = Math.abs(dx);
            } else {
                l = Math.abs(dy);
            }

            float sx = dx / l;
            float sy = dy / l;

            for (int i = 0; i <= l; i++) {
                addPixel(Math.round(x), Math.round(y));
                x += sx;
                y += sy;
            }
        } else {
            addPixel(Math.round(x), Math.round(y));
        }
    }

    public void drawBresenhamFloat(int x1, int y1, int x2, int y2) {
        int x = x1;
        int y = y1;

        int dx = x2 - x1;
        int dy = y2 - y1;

        if (dx != 0 && dy != 0) {                    // Check for x1 == x2 || y1 == y2
            int sx = Integer.signum(dx);              // compute step every pixel coords
            int sy = Integer.signum(dy);                // compute step every pixel coords

            dx = Math.abs(dx);
            dy = Math.abs(dy);

            float m = ((float) dy) / dx;        //compute angle incline

            boolean changeFlag = false;
            if (m > 1) {
                changeFlag = true;
                int temp = dx;
                dx = dy;
                dy = temp;
                m = 1 / m;
            }

            float e = m - 0.5f;
            for (int i = 0; i < dx; i++) {
                addPixel(x, y);
                if (e >= 0) {

                    if (!changeFlag) {
                        y += sy;
                    } else {
                        x += sx;
                    }

                    e--;
                }

                if (!changeFlag) {
                    x += sx;
                } else {
                    y += sy;
                }

                e += m;
            }
        } else {
            addPixel(x, y);
        }
    }

    public void drawBresenhamInteger(int x1, int y1, int x2, int y2) {
        int x = x1;
        int y = y1;

        int dx = x2 - x1;
        int dy = y2 - y1;

        if (dx != 0 || dy != 0) {
            int sx = Integer.signum(dx);
            int sy = Integer.signum(dy);

            dx = Math.abs(dx);
            dy = Math.abs(dy);

            boolean changeFlag = false;
            if (dx < dy) {
                changeFlag = true;
                int temp = dx;
                dx = dy;
                dy = temp;
            }

            int fl = 2 * dy - dx;
            for (int i = 0; i <= dx; i++) {
                addPixel(x, y);
                if (fl >= 0) {
                    if (!changeFlag) {
                        y += sy;
                    } else {
                        x += sx;
                    }

                    fl -= 2 * dx;
                }

                if (fl < 0) {
                    if (!changeFlag) {
                        x += sx;
                    } else {
                        y += sy;
                    }

                    fl += 2 * dy;
                }
            }
        } else {
            addPixel(x, y);
        }
    }
    public void drawBresenhamStepSmooth(int x1, int y1, int x2, int y2) {
        int I = 255;
        //  GHj
        int dx = x2 - x1;
        int dy = y2 - y1;
        int x = x1;
        int y = y1;
        if (dx != 0 || dy != 0) {
            int sx = Integer.signum(dx);
            int sy = Integer.signum(dy);
            dx = Math.abs(dx);
            dy = Math.abs(dy);
            float e;

            boolean changeFlag = false;
            float m = ((float)dy) / dx;

            if (m > 1) {
                int temp = dx;
                dx = dy;
                dy = temp;
                m = 1 / m;
                changeFlag = true;
            }

            e = I * 0.5f;

            m = m * I;
            float W = I - m;

            addPixel(x, y);
            for (int i = 0; i < dx; i++) {
                if (e <= W) {
                    if (!changeFlag) {
                        x = x + sx;
                    } else {
                        y = y + sy;
                    }
                    e += m;
                } else {
                    x = x + sx;
                    y = y + sy;
                    e  = e - W;
                }
                addPixel(x, y, Color.rgb(
                        red,
                        green,
                        blue,
                        1 - (e / I)));
            }
        } else {
            addPixel(x, y);
        }
    }

    public void drawBy(int x1, int y1, int x2, int y2) {

        float I = 255;

        if (x2 <= x1) {
            int tmp = x2;
            x2 = x1;
            x1 = tmp;

            tmp = y2;
            y2 = y1;
            y1 = tmp;
        }

        float dx = x2 - x1;
        float dy = y2 - y1;
        float gradient = 0;

        if (dx > dy) {
            gradient = dy / dx;
            float itery = y1 + gradient;
            addPixel(x1, y1);

            for (int x = x1; x < x2; ++x) {
                float alpha = ((I - fractionalPart(itery) * I)) / I;
                addPixel(x, (int)itery, Color.rgb(red, green, blue, alpha));

                alpha = fractionalPart(itery);
                addPixel(x, (int)itery + 1, Color.rgb(red, green, blue, alpha));
                itery += gradient;
            }
            addPixel(x2, y2);
        } else {
            gradient = (float)(dx / dy);

            float iterx = x1 + gradient;
            addPixel(x1, y1);
            for (int y = y1; y < y2; ++y) {
                float alpha = 1 - ((I - fractionalPart(iterx) * I)) / I;
                addPixel((int)iterx, y, Color.rgb(red, green, blue, alpha));

                alpha = fractionalPart(iterx);
                addPixel((int)iterx + 1, y, Color.rgb(red, green, blue, alpha));

                iterx += gradient;
            }

            addPixel(x2, y2);
        }
    }
    public void drawLib(int x1, int y1, int x2, int y2) {
        gc.setStroke(color);
        gc.strokeLine(x1, y1, x2, y2);
    }

    private float fractionalPart(float x)
    {
        int tmp = (int) x;
        return x - tmp; //вернёт дробную часть числа
    }

}
