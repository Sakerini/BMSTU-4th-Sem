package objects;

public class CircleMath {

    public static boolean isCircle(Point A, Point B, Point C){
        if (Math.abs(TriangleMath.SquareRoot(A, B, C)) <= .0001){
            return false;
        }
        return true;
    }

    public static Point findCircleCentre(Point A, Point B, Point C) {

        double xa = A.getX(), xb = B.getX(), xc = C.getX();
        double ya= A.getY(), yb = B.getY(), yc = C.getY();

        if (xa == xb && xb == xc){
            return null;
        }
        if (xb == xa){ //kogda odna xorda veritalkynaq
            double tmp = xb;
            xb = xc;
            xc = tmp;

            tmp = yb;
            yb = yc;
            yc = tmp;
        } else if (xb == xc) {
            double tmp = xa;
            xa = xb;
            xb = tmp;

            tmp = ya;
            ya = yb;
            yb = tmp;
        }
        double ma = (yb - ya) / (xb - xa); // Коефицент наклонения линиии;
        double mb = (yc - yb) / (xc - xb);


        if (ma != mb) {
            double x = (ma * mb * (ya - yc) + mb * (xa + xb) - ma * (xb + xc)) / (2 * (mb - ma));
            double y;
            if (Math.abs(ma) < 0.0001) {
                y = -(1 / mb) * (x - (xb + xc) / 2) + (yb + yc) / 2;
            }
            else {
                y = -(1 / ma) * (x - (xa + xb) / 2) + ((ya + yb) / 2);
            }
            Point circlePoint = new Point(x, y);
            return circlePoint;
        }
        return null;
    }


}
