package objects;

import javax.swing.*;

public class MyCircle {
    private Point centr;
    private double radius;

    public MyCircle(Point centr, double radius){
        this.centr = centr;
        this.radius = radius;
    }
    public MyCircle(){
        this.centr = null;
        this.radius = 0;
    }

    public double getRadius() { return radius; }
    public Point getCentr() { return centr; }

    public void setCentr(Point centr) { this.centr = centr; }
    public void setRadius(double radius) { this.radius = radius; }

    public void showInfo(){
        System.out.println("Circle");
        System.out.println("Circle radius: " + this.radius);
        System.out.println("Centre point: ");
        this.centr.showInfo();
    }
    public Point getScalePointUpLeft(){
        double xscale = this.centr.getX() - this.radius;
        double yscale = this.centr.getY() + this.radius;

        return new Point(xscale, yscale);
    }

    public Point getscalePointUpRight(){
        double xscale = this.centr.getX() + this.radius;
        double yscale = this.centr.getY() + this.radius;

        return new Point(xscale, yscale);
    }

    public Point getscalePointDownLeft(){
        double xscale = this.centr.getX() - this.radius;
        double yscale = this.centr.getY() - this.radius;

        return new Point(xscale, yscale);
    }

    public Point getscalePointDownRight(){
        double xscale = this.centr.getX() + this.radius;
        double yscale = this.centr.getY() - this.radius;

        return new Point(xscale, yscale);
    }
}
