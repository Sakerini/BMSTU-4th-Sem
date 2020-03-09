package com.company;

import java.util.ArrayList;

public class NewtonPolynominal {
    public static Double getActualValue(Double x){
        return Math.cos(x);
    }

    public static Integer getStartIndex(ArrayList<Double> xTable,ArrayList<Double> yTable, Integer n, Integer xCenterIndex) {
        Integer result = xCenterIndex - n / 2;
        if (result < 0)
            result = 0;

        if (result + n >= xTable.size()) {
            result = xTable.size() - n - 1;
        }

        return result;
    }

    public static Double NewtonMethod(ArrayList<Double>xTable, ArrayList<Double> yTable,int n, double x){
        double result;

        /* Check arguments */
        if (xTable.size() < 2) {
            throw new IllegalArgumentException("Table size is less than 2!");
        }

        if (xTable.size() < n + 1)
            throw new IllegalArgumentException("n + 1 should be smaller or equal table.size()!");

        /* Find x0 */
        int xFirstIndex = 0; // First number in table less than x
        boolean finded = false;
        for (int i = 0; i < xTable.size() - 1; i++) {
            if (xTable.get(i) <= x && xTable.get(i + 1) >= x ||
                    xTable.get(i) >= x && xTable.get(i + 1) <= x ) {
                xFirstIndex = i;
                finded = true;
                break;
            }
        }
        if (!finded)
            throw new IllegalArgumentException("x is outside the table!");

        if (Math.abs(x - xTable.get(xFirstIndex)) <= 1e-5)
            return yTable.get(xFirstIndex);

        Integer xi0 = getStartIndex(xTable, yTable, n, xFirstIndex);

        // Preparation
        Double[] y = new Double[n];
        Double[] y_tmp = new Double[n];
        for (int i = 0; i < n; i++) {
            y[i] = (yTable.get(xi0 + i) - yTable.get(xi0 + i + 1)) /
                    (xTable.get(xi0 + i) - xTable.get(xi0 + i + 1));
        }

        for (int i = 1; i < n; i++) {
            for (int p = 0; p < n; p++) {
                y_tmp[p] = y[p];
            }
            for (int j = i; j < n; j++) {
                y_tmp[j] = (y[j - 1] - y[j]) / (xTable.get(xi0 + j - i) - xTable.get(xi0 + j + 1));
            }
            for (int p = 0; p < n; p++) {
                y[p] = y_tmp[p];
            }
        }

        Double yn = yTable.get(xi0);
        Double obsht = 1d;

        for (int i = 0; i < n; i++) {
            obsht *= (x - xTable.get(xi0 + i));
            yn += obsht * y[i];
        }

        return yn;
    }
}
