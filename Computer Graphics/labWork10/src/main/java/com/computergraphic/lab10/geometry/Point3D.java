package com.computergraphic.lab10.geometry;

public class Point3D {
    private double x = 0;
    private double y = 0;
    private double z = 0;

    Point3D(double x, double y, double z) {
        setX(x);
        setY(y);
        setZ(z);
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }

    private Point3D rotateX(double radians) {
        var tmpy = y;
        y = Math.cos(radians) * y - Math.sin(radians) * z;
        z = Math.cos(radians) * z + Math.sin(radians) * tmpy;

        return this;
    }

    private Point3D rotateY(double radians) {
        var tmpx = x;
        x = Math.cos(radians) * x - Math.sin(radians) * z;
        z = Math.cos(radians) * z + Math.sin(radians) * tmpx;

        return this;
    }

    private Point3D rotateZ(double radians) {
        var tmpx = x;

        x = Math.cos(radians) * x - Math.sin(radians) * y;
        y = Math.cos(radians) * y + Math.sin(radians) * tmpx;

        return this;
    }

    public Point3D rotate(double alpha, double betta, double gamma) {
        rotateX(alpha);
        rotateY(betta);
        rotateZ(gamma);

        return this;
    }

    public Point3D scale(double k) {
        x *= k;
        y *= k;
        z *= k;

        return this;
    }
}
