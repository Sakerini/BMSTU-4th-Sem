package Objects;

import javafx.scene.canvas.GraphicsContext;

public class Triangle {
    private Point A;
    private Point B;
    private Point C;

    public Triangle(Point A, Point B, Point C){
        this.A = A;
        this.B = B;
        this.C = C;
    }

    public Point getA() { return A; }
    public Point getB() { return B; }
    public Point getC() { return C; }

    public void setA(Point a) { A = a; }
    public void setB(Point b) { B = b; }
    public void setC(Point c) { C = c; }

    public void drawTriangle(GraphicsContext gc){
        gc.strokeLine(this.A.getX(),this.A.getY(),this.B.getX(),this.B.getY());
        gc.strokeLine(this.A.getX(),this.A.getY(),this.C.getX(),this.C.getY());
        gc.strokeLine(this.C.getX(),this.C.getY(),this.B.getX(),this.B.getY());
    }

    private void rotatePUSH(GraphicsContext gc, Point center, double angle) {
        gc.save();
        gc.translate(center.getX(), center.getY());
        gc.rotate(angle);
        gc.translate(-center.getX(), -center.getY());

    }
    private void rotatePOP(GraphicsContext gc) {
        gc.restore();
    }
}
