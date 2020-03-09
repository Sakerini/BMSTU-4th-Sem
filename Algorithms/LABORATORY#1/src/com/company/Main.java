package com.company;

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static ArrayList<Double> xTable = new ArrayList<Double>();
    public static ArrayList<Double> yTable = new ArrayList<Double>();

    public static void sortXTable(){
        for (int i = 0; i < xTable.size() - 1; i++){
            for (int j = 0; j < xTable.size() - i - 1; j++){
                if (xTable.get(j) > xTable.get(j + 1)){
                    Double tmp = xTable.get(j);
                    xTable.set(j, xTable.get(j + 1));
                    xTable.set(j + 1, tmp);

                    tmp = yTable.get(j);
                    yTable.set(j, yTable.get(j + 1));
                    yTable.set(j + 1, tmp);
                }
            }
        }
    }

    public static void readDataFromFile(File file) throws Exception {
        Scanner sc = new Scanner(file);
        System.out.println("in file reading");

        while (sc.hasNextDouble()){
            Double xValue = sc.nextDouble();
            if (!sc.hasNextDouble()){
                throw new Exception("Incorrect file written");
            }

            Double yValue = sc.nextDouble();
            xTable.add(xValue);
            yTable.add(yValue);
        }

        sortXTable();
    }
    public static void printTable(){
        for(int i = 0; i < xTable.size(); i++){
            System.out.println("| " + xTable.get(i) + " | " + yTable.get(i) + " | " );
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Input path to the file: ");
        String filePath = sc.nextLine().trim();
        File inputTableFile = new File(filePath);
        try{
            readDataFromFile(inputTableFile);
        }catch (Exception e){
            System.out.println("Error Reading File");
        }

        //Print Readed File
        printTable();

        int n = 0;
        System.out.print("Input n: ");
        if (!sc.hasNextInt()) {
            System.out.println("Can't read int");
            return;
        }
        n = sc.nextInt();

        double x = 0d;
        System.out.print("Input x: ");
        System.out.flush();
        if (!sc.hasNextDouble()) {
            System.out.println("Can't read double");
            return;
        }
        x = sc.nextDouble();

        Double result = NewtonPolynominal.NewtonMethod(xTable, yTable, n, x);
        double actualResult = NewtonPolynominal.getActualValue(x);

        System.out.printf("Result:            %15.3f\n", result);
        System.out.printf("Actual result:     %15.3f\n", actualResult);

        Double root = HalfDivision.halfDiv(xTable,yTable, n);
        if(root != null){
            System.out.printf("Root half division:%15.3f\n", root);
        }
        else{
            System.out.print("Root not found!!");
        }
        double reverseResult = NewtonPolynominal.NewtonMethod(yTable,xTable,n, 0);
        System.out.printf("Root rev. interpol:%15.3f\n", reverseResult);

    }
}
