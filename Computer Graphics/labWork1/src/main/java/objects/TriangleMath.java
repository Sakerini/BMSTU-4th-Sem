package objects;

public class TriangleMath {
    public static double SquareRoot(Point A, Point B, Point C){
        double AB = Math.sqrt((B.getX() - A.getX()) * (B.getX() - A.getX()) + (B.getY() - A.getY()) * (B.getY() - A.getY()));
        double AC = Math.sqrt((C.getX() - A.getX()) * (C.getX() - A.getX()) + (C.getY() - A.getY()) * (C.getY() - A.getY()));
        double BC = Math.sqrt((C.getX() - B.getX()) * (C.getX() - B.getX()) + (C.getY() - B.getY()) * (C.getY() - B.getY()));

        double p = (AB + AC + BC) / 2;
        double s = Math.sqrt(p * (p - BC) * (p - AC) * (p - AC));
        if (Double.isNaN(s)) {
            System.out.println("nan");
        }
        return s;
    }

    public static void main(String[] args) {
        Point A = new Point(-10,-20);
        Point B = new Point(2,1);
        Point C = new Point(0,0);

        System.out.println(SquareRoot(A,B,C));
    }
}
