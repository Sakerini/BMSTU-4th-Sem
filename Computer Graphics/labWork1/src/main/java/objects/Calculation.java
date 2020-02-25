package objects;

import controllers.MainController;
import javafx.collections.ObservableList;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.List;

public class Calculation {
    public static Picture solve(ObservableList<Point> pointListOne, ObservableList<Point> pointListTwo){
        Picture picture = new Picture();
        MyCircle circle1 = null;
        MyCircle circle2 = null;
        Point intersectionPoint = null;
        Line tangent1 = null;
        Line tangent2 = null;
        Double minSquare = null;

        Point a = null;
        Point b = null;
        Point c = null;

        Point d = null;
        Point e = null;
        Point f = null;

        Double diff = null;
        Double square1 = null;
        Double square2 = null;

        for (int i = 0; i < (pointListOne.size() - 2); i++){
            for(int j = i + 1; j < pointListOne.size() - 1; j++){
                for (int k = j + 1; k < pointListOne.size(); k++){

                    Point A = pointListOne.get(i);
                    Point B = pointListOne.get(j);
                    Point C = pointListOne.get(k);

                    MyCircle circle1TMP = null;
                    MyCircle circle2TMP = null;
                    if (CircleMath.isCircle(A ,B ,C)) {
                        Point centreTMP = CircleMath.findCircleCentre(A,B,C);
                        if (centreTMP == null)
                            continue;
                        double radiusTMP = calcDistance(centreTMP, A);
                        circle1TMP = new MyCircle(centreTMP, radiusTMP);
                    }
                    else
                        continue;
                    for (int l = 0; l < pointListTwo.size() - 2; l++) {
                        for (int m = l + 1; m < pointListTwo.size() - 1; m++) {
                            for (int n = m + 1; n < pointListTwo.size(); n++) {
                                Point D = pointListTwo.get(l);
                                Point E = pointListTwo.get(m);
                                Point F = pointListTwo.get(n);

                                if (CircleMath.isCircle(D ,E ,F)) {
                                    Point centreTMP = CircleMath.findCircleCentre(D,E,F);
                                    if (centreTMP == null)
                                        continue;
                                    double radiusTMP =calcDistance(centreTMP, D);
                                    circle2TMP = new MyCircle(centreTMP, radiusTMP);
                                }
                                else
                                    continue;
                                double distanceBetweenCentres = calcDistance(circle1TMP.getCentr(),circle2TMP.getCentr());

                                if (distanceBetweenCentres <= circle1TMP.getRadius() + circle2TMP.getRadius())
                                    continue;
                                Point intersectionPointTMP = findIntersectionPoint(circle1TMP, circle2TMP);
                                //Point tangentPointA1TMP = findTangent(circle1TMP, intersectionPointTMP);
                                //Point tangentPointB1TMP = findTangent(circle2TMP, intersectionPointTMP);
                                Pair<Line, Line> tangentspair = findTangents(circle1TMP, circle2TMP, intersectionPointTMP);
                                Line tangent1TMP = tangentspair.getKey();
                                Line tangent2TMP = tangentspair.getValue();

                                //double squareTriangle1 = 0;
                                //if (Math.abs(calcDistance(tangent1TMP.getPointA(), circle1TMP.getCentr()) - circle1TMP.getRadius()) < 0.0001) {
                                double squareTriangle1 = TriangleMath.SquareRoot(intersectionPointTMP, tangent1TMP.getPointA(), circle1TMP.getCentr());
                                //}
                                //double squareTriangle2 = 0;
                                //if (Math.abs(calcDistance(tangent1TMP.getPointB(),circle2TMP.getCentr()) - circle2TMP.getRadius()) < 0.0001) {
                                double squareTriangle2 = TriangleMath.SquareRoot(intersectionPointTMP, tangent1TMP.getPointB(), circle2TMP.getCentr());
                                //}

                                double difference = Math.abs(squareTriangle1 - squareTriangle2);

                                //System.out.println("difference between " + squareTriangle1 + " and " + squareTriangle2 + " is " + difference);

                                if (minSquare == null || difference < minSquare){
                                    minSquare = difference;
                                    circle1 = circle1TMP;
                                    circle2 = circle2TMP;
                                    intersectionPoint = intersectionPointTMP;
                                    tangent1 = tangent1TMP;
                                    tangent2 = tangent2TMP;
                                    diff = difference;
                                    square1 = squareTriangle1;
                                    square2 = squareTriangle2;
                                    a = A;
                                    b = B;
                                    c = C;
                                    d = D;
                                    e = E;
                                    f = F;
                                }
                                // Continue calculation here!!!!
                            }
                        }
                    }
                }
            }
        }
        if (circle1 == null || circle2 == null || intersectionPoint == null
                || tangent1 == null || tangent2 == null || a == null || b == null || c == null
        || d == null || e == null || f == null) {
            MainController.giveErrorAlert("ERROR: Could'not find circles that match the result needed");
            return null;
        }
        picture.setCircleOne(circle1);
        picture.setCircleTwo(circle2);
        picture.setIntersectionPoint(intersectionPoint);
        picture.setTangentOne(tangent1);
        picture.setTangentTwo(tangent2);
        picture.setSquareRoot(diff);
        List<Point> pointList1 = new ArrayList<Point>();
        pointList1.add(a);
        pointList1.add(b);
        pointList1.add(c);
        picture.setPointList1(pointList1);
        List<Point> pointList2 = new ArrayList<Point>();
        pointList2.add(d);
        pointList2.add(e);
        pointList2.add(f);
        picture.setPointList2(pointList2);
        return picture;
    }

    public static Pair<Point, Point> findTangentPoints (MyCircle circle, Point point) {
        double a = circle.getCentr().getX(), b = circle.getCentr().getY();
        double xp = point.getX(), yp = point.getY();
        double r = circle.getRadius();

        double xt1 = ((r * r) * (xp - a) + r * (yp - b) * Math.sqrt((xp - a) * (xp - a) + (yp - b) * (yp - b) - r * r))
                / ((xp - a) * (xp - a) + (yp - b) * (yp - b)) + a;

        double yt1 = ((r * r) * (yp - b) - r * (xp - a) * Math.sqrt((xp - a) * (xp - a) + (yp - b) * (yp - b) - r * r))
                / ((xp - a) * (xp - a) + (yp - b) * (yp - b)) + b;

        double xt2 = ((r * r) * (xp - a) - r * (yp - b) * Math.sqrt((xp - a) * (xp - a) + (yp - b) * (yp - b) - r * r))
                / ((xp - a) * (xp - a) + (yp - b) * (yp - b)) + a;

        double yt2 = ((r * r) * (yp - b) + r * (xp - a) * Math.sqrt((xp - a) * (xp - a) + (yp - b) * (yp - b) - r * r))
                / ((xp - a) * (xp - a) + (yp - b) * (yp - b)) + b;

        Point t1 = new Point(xt1, yt1);
        Point t2 = new Point(xt2, yt2);

        Pair<Point, Point> pairPoint = new Pair<Point, Point>(t1, t2);

        //Correctness check
        double s = ((b - yt1) * (yp - yt1)) / ((xt1 - a) * (xt1 - xp));

        if (Math.abs(s - 1) < 0.0001) {
            double tmp = yt1;
            yt1 = yt2;
            yt2 = tmp;
        }

        return pairPoint;
    }

    public static Pair<Line,Line> findTangents(MyCircle circle, MyCircle circle2, Point point){
        Pair<Point, Point> pair1 = findTangentPoints(circle, point);
        Pair<Point, Point> pair2 = findTangentPoints(circle2, point);

        Line tangent1 = new Line(pair1.getKey(), pair2.getKey());
        Line tangent2 = new Line(pair1.getValue(), pair2.getValue());

        Pair<Line, Line> tangentspair = new Pair<Line, Line>(tangent1, tangent2);

        return tangentspair;
    }

    public static Point findIntersectionPoint(MyCircle circle1, MyCircle circle2){
        double r0 = circle1.getRadius(), r1 = circle2.getRadius(), xc1 = circle1.getCentr().getX(), xc2 = circle2.getCentr().getX();
        double yc1 = circle1.getCentr().getY(), yc2 = circle2.getCentr().getY();
        double xintersec = ((xc2*r0) + (xc1 * r1)) / (r0 + r1);
        double yintersec = ((yc2 * r0) + (yc1 * r1)) / (r0 + r1);
        return new Point(xintersec, yintersec);
    }

    public static double calcDistance(Point A, Point B){
        double distance = Math.sqrt(((B.getX() - A.getX()) * (B.getX() - A.getX())) + ((B.getY() - A.getY()) * (B.getY() - A.getY())));
        return distance;
    }

    public static void main(String[] args) {
        MyCircle circle1 = new MyCircle(new Point(3, 1.5), 1);
        MyCircle circle2 = new MyCircle(new Point(8.5, 1.5), 0.5);

        Point intersectionPoint = findIntersectionPoint(circle1,circle2);
        System.out.println("Intersaction Point " + intersectionPoint.getX() + " | " + intersectionPoint.getY());

        Pair<Line, Line> tangents = findTangents(circle1,circle2,intersectionPoint);
        Line tangent1 = tangents.getKey();
        Line tangent2 = tangents.getValue();

        tangent1.showInfo();
        tangent2.showInfo();
    }
}
