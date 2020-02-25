package objects;

public class Point {
    private double x;
    private double y;

    public Point(double X, double Y){
        setX(X);
        setY(Y);
    }
    public Point(){
    }

    public void setX(double x) { this.x = x; }
    public void setY(double y) { this.y = y; }

    public double getX() { return x; }
    public double getY() { return y; }

    public void showInfo(){
        System.out.print("X: " + this.x + " Y: " + this.y + "\n");
    }

    public static Point getCopy(Point point) {
        return new Point(point.getX(), point.getY());
    }

    public static String getStringPoints(Point point, String pointName){
        String result = pointName + "(" + String.format("%.2f",point.getX()) + "," + String.format("%.2f", point.getY()) + ")";
        return result;
    }

}
