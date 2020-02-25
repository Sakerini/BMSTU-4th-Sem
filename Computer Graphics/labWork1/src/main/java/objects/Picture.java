package objects;

import javafx.collections.ObservableArray;
import javafx.collections.ObservableList;

import java.util.ArrayList;
import java.util.List;

public class Picture {
    private MyCircle circleOne;
    private MyCircle circleTwo;
    private Line tangentOne;
    private Line tangentTwo;
    private Point IntersectionPoint;
    private double squareDifference;
    private List<Point> PointList1;
    private List<Point> PointList2;

    public MyCircle getCircleOne() { return circleOne; }
    public MyCircle getCircleTwo() { return circleTwo; }
    public Line getTangentOne() { return tangentOne; }
    public Line getTangentTwo() { return tangentTwo; }
    public Point getIntersectionPoint() { return IntersectionPoint; }
    public double getSquareRoot() { return squareDifference; }
    public List<Point> getPointList1() { return PointList1; }
    public List<Point> getPointList2() { return PointList2; }

    public void setCircleOne(MyCircle circleOne) { this.circleOne = circleOne; }
    public void setCircleTwo(MyCircle circleTwo) { this.circleTwo = circleTwo; }
    public void setTangentOne(Line tangentOne) { this.tangentOne = tangentOne; }
    public void setTangentTwo(Line tangentTwo) { this.tangentTwo = tangentTwo; }
    public void setIntersectionPoint(Point intersectionPoint) { IntersectionPoint = intersectionPoint; }
    public void setSquareRoot(double squareRoot) { squareDifference = squareRoot; }
    public void setPointList1(List<Point> pointList1) { PointList1 = pointList1; }
    public void setPointList2(List<Point> pointList2) { PointList2 = pointList2; }

    public void showInfo(){
        this.circleOne.showInfo();
        this.circleTwo.showInfo();
        this.tangentOne.showInfo();
        this.tangentTwo.showInfo();
        this.IntersectionPoint.showInfo();
        System.out.println("Square diff:" + this.squareDifference);
        System.out.flush();
    }

    public List<Point> getAllPoints(){
        List<Point> points = new ArrayList<Point>();
        points.add(this.circleOne.getCentr());
        points.add(this.circleOne.getscalePointDownLeft());
        points.add(this.circleOne.getscalePointDownRight());
        points.add(this.circleOne.getScalePointUpLeft());
        points.add(this.circleOne.getscalePointUpRight());
        points.add(this.circleTwo.getscalePointDownLeft());
        points.add(this.circleTwo.getscalePointDownRight());
        points.add(this.circleTwo.getScalePointUpLeft());
        points.add(this.circleTwo.getscalePointUpRight());
        points.add(this.circleTwo.getCentr());
        points.add(this.IntersectionPoint);
        points.add(this.tangentOne.getPointA());
        points.add(this.tangentOne.getPointB());
        points.add(this.tangentTwo.getPointA());
        points.add(this.tangentTwo.getPointB());

        return points;
    }
}
