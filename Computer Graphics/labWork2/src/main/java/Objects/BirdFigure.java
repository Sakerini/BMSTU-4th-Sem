package Objects;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.shape.Arc;
import javafx.scene.shape.ArcType;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;

public class BirdFigure {
    //private Ellipse head;
    //private Ellipse body;
    private Arc head;
    private Arc body;
    private Line leftLeg;
    private Line rightLeg;
    private Triangle headTriangle;
    private Triangle tailTriangle;
    private Triangle wingTriangle;

    private double width = 0;
    private double height = 0;
    private final Point center = new Point(0 , 0);
    private double rotationAngle = 0;

    /**
     * Creating a Bird shape object
     * @param center is center of the shape
     * @param width is width of the shape
     * @param height is height of the shape
     */

    public BirdFigure(Point center, double width, double height, double rotationAngle) {
        final double W = 300;
        final double H = 300;

        this.width = width;
        this.height = height;
        this.rotationAngle = rotationAngle;
        this.center.setX(center.getX());
        this.center.setY(center.getY());

        double rxkoef = width / W;
        double rykoef = height / H;

        double centrx = this.center.getX();
        double centry = this.center.getY();

        //Ellipse body = new Ellipse(centrx - 40 * rxkoef , centry - 20 * rykoef , 80 * rxkoef, 40 * rykoef);
        Arc body = new Arc(centrx - Math.abs(40 * rxkoef), centry - Math.abs(20 * rykoef), Math.abs(80 * rxkoef), Math.abs(40* rykoef), 90, 360);
        rotateArc(body);
        //Ellipse head = new Ellipse(centrx - 40  * rxkoef, centry - 40 * rykoef,  25 * rxkoef, 25 * rykoef);
        Arc head = null;
        if (rxkoef < 0 && rykoef < 0){
            head = new Arc(centrx - 18 * rxkoef, centry - 16 * rykoef, Math.abs(25* rxkoef), Math.abs(25 *rykoef), 90, 360);
        }
        else if (rxkoef < 0){
            head = new Arc(centrx - 18 * rxkoef, centry - Math.abs(40 * rykoef), Math.abs(25* rxkoef), Math.abs(25 *rykoef), 90, 360);
        }
        else if (rykoef < 0){
            head = new Arc(centrx - Math.abs(40 * rxkoef), centry - 16 * rykoef, Math.abs(25 * rxkoef), Math.abs(25 * rykoef), 90, 360);
        }
        else {
            head = new Arc(centrx - 40 * rxkoef, centry - 40 * rykoef, Math.abs(25 * rxkoef), Math.abs(25 * rykoef), 90, 360);
        }

        rotateArc(head);

        Line leftLine = new Line(centrx - 10 * rxkoef, centry + 20 * rykoef, centrx - 20 * rxkoef, centry + 50 * rykoef);
        rotateLine(leftLine);
        Line rightLine = new Line(centrx + 10 * rxkoef, centry + 20 * rykoef, centrx + 20 * rxkoef, centry + 50 * rykoef);
        rotateLine(rightLine);
        Triangle headTriangle = new Triangle(new Point(centrx - 35 * rxkoef, centry - 35 * rykoef),
                new Point(centrx - 50 * rxkoef , centry - 30 * rykoef ), new Point(centrx - 35 * rxkoef,centry - 25 * rykoef));
        rotateTriangle(headTriangle);
        Triangle tailTriangle = new Triangle(new Point(centrx + 30 * rxkoef, centry + 5 * rykoef),
                new Point(centrx + 30 * rxkoef, centry - 5 * rykoef), new Point(centrx + 55 * rxkoef, centry));
        rotateTriangle(tailTriangle);
        Triangle wingTriangle = new Triangle(new Point(centrx + 5 * rxkoef,centry),
                new Point(centrx - 5 * rxkoef, centry), new Point(centrx, centry + 15 * rykoef));
        rotateTriangle(wingTriangle);

        //this.body = body;
        this.body = body;
        this.head = head;
        this.leftLeg = leftLine;
        this.rightLeg = rightLine;
        this.headTriangle = headTriangle;
        this.tailTriangle = tailTriangle;
        this.wingTriangle = wingTriangle;

        //BODY PARTS TO BE ADDED!! HERE NOT IN DRAW METHOD!!!
    }

    public double getHeight() { return height; }
    public double getWidth() { return width; }
    public double getRotationAngle() { return rotationAngle; }
    //public Ellipse getHead() { return head; }
    //public Ellipse getBody() { return body; }
    public Line getLeftLeg() { return leftLeg; }
    public Line getRightLeg() { return rightLeg; }
    public Point getCenter() { return center; }
    public Triangle getHeadTriangle() { return headTriangle; }
    public Triangle getTailTriangle() { return tailTriangle; }
    public Triangle getWingTriangle() { return wingTriangle; }


    public void drawBird(GraphicsContext gc){

        //gc.strokeOval(this.body.getCenterX(),this.body.getCenterY(),this.body.getRadiusX(),this.body.getRadiusY());
        rotatePUSH(gc, new Point(body.getCenterX(), body.getCenterY()), Math.toDegrees(rotationAngle));
        gc.strokeArc(this.body.getCenterX(), this.body.getCenterY(),this.body.getRadiusX(),this.body.getRadiusY(),this.body.getStartAngle(),this.body.getLength(), ArcType.OPEN);
        rotatePOP(gc);
        rotatePUSH(gc, new Point(head.getCenterX(), head.getCenterY()), Math.toDegrees(rotationAngle));
        gc.strokeArc(head.getCenterX(),head.getCenterY(),head.getRadiusX(),head.getRadiusY(),head.getStartAngle(),head.getLength(), ArcType.OPEN);
        rotatePOP(gc);
        gc.strokeLine(this.leftLeg.getStartX(),this.leftLeg.getStartY(),this.leftLeg.getEndX(),this.leftLeg.getEndY());
        gc.strokeLine(this.rightLeg.getStartX(),this.rightLeg.getStartY(),this.rightLeg.getEndX(),this.rightLeg.getEndY());
        this.headTriangle.drawTriangle(gc);
        this.tailTriangle.drawTriangle(gc);
        this.wingTriangle.drawTriangle(gc);

    }

    private void rotateLine(Line line) {
        Point start = new Point(line.getStartX(), line.getStartY());
        Point end = new Point(line.getEndX(), line.getEndY());

        start.rotate(center, rotationAngle);
        end.rotate(center, rotationAngle);

        line.setStartX(start.getX());
        line.setStartY(start.getY());
        line.setEndX(end.getX());
        line.setEndY(end.getY());
    }
    private void rotateTriangle(Triangle triangle){
        Point a = Point.getCopy(triangle.getA());
        Point b = Point.getCopy(triangle.getB());
        Point c = Point.getCopy(triangle.getC());

        a.rotate(center, rotationAngle);
        b.rotate(center, rotationAngle);
        c.rotate(center, rotationAngle);

        triangle.setA(a);
        triangle.setB(b);
        triangle.setC(c);
    }


    private void rotateArc(Arc arc) {
        Point arcCenter = new Point(arc.getCenterX(), arc.getCenterY());
        // Rotate center
        arcCenter.rotate(center, rotationAngle);

        // Change arc start angle
        // arc.setStartAngle(arc.getStartAngle() - rotationAngle);

        arc.setCenterX(arcCenter.getX());
        arc.setCenterY(arcCenter.getY());
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
