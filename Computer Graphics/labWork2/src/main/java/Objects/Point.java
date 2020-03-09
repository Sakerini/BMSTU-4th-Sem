package Objects;

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

    public Point scale(Point center, double kx, double ky) {
        Point tmp = new Point((x - center.getX()) * kx + center.getX(), (y - center.getY()) * ky + center.getY());
        return tmp;
    }

    public Point add(double dx, double dy) {
        Point tmp = new Point(x + dx, y + dy);
        return tmp;
    }

    public Point rotate(Point center, double angle) {
        double newX = Math.cos(angle) * (x - center.getX()) - Math.sin(angle) * (y - center.getY()) + center.getX();
        double newY = Math.sin(angle) * (x - center.getX()) + Math.cos(angle) * (y - center.getY()) + center.getY();
        setX(newX);
        setY(newY);

        return this;
    }
    public Point rotateTwo(Point center, double angle) {
        double newX = Math.cos(angle) * (x - center.getX()) - Math.sin(angle) * (y - center.getY()) + center.getX();
        double newY = Math.sin(angle) * (x - center.getX()) + Math.cos(angle) * (y - center.getY()) + center.getY();
        Point tmp = new Point(newX,newY);
        return tmp;
    }
}
