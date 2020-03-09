package com.company;

import java.util.ArrayList;

public class HalfDivision{
    public static Double halfDiv(ArrayList<Double> xTable, ArrayList<Double> yTable, int n) {
        double a = xTable.get(0), ya = yTable.get(0);
        double b = xTable.get(xTable.size() - 1), yb = yTable.get(yTable.size() - 1);
        double x = (a + b) / 2;
        double yn = NewtonPolynominal.NewtonMethod(xTable, yTable, n, x);

        while (!(Math.abs(yn) < .0001)) {
            if (Math.abs(a - b) < .0001){
                break;
            }
            if (yn > 0) {
                a = x;
                x = (x + b) / 2;
                yn = NewtonPolynominal.NewtonMethod(xTable, yTable, n, x);
            }
            if (yn < 0) {
                b = x;
                x = (x + a) / 2;
                yn = NewtonPolynominal.NewtonMethod(xTable, yTable, n, x);
            }
        }

        if (Math.abs(yn) < 0.001) {
            return x;
        }
        return null;
    }
}
