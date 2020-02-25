package objects;

public class Line {
    private Point pointA;
    private Point pointB;

    public Line(Point A, Point B){
        this.pointA = A;
        this.pointB = B;
    }

    public Point getPointA() { return pointA; }
    public Point getPointB() { return pointB; }

    public void setPointA(Point pointA) { this.pointA = pointA; }
    public void setPointB(Point pointB) { this.pointB = pointB; }

    public void showInfo(){
        System.out.println("Line:");
        System.out.print("Point1: ");
        this.pointA.showInfo();
        System.out.print("Point2: ");
        this.pointB.showInfo();
    }
}
