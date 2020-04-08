import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;


public class Main {

    private static ArrayList<Map.Entry<Double, Double>> readTableFromFile(File filePath) throws Exception {
        ArrayList<Map.Entry<Double, Double>> table = new ArrayList<>();

         Scanner sc = new Scanner(filePath);

         while (sc.hasNextDouble()) {
             Double key = sc.nextDouble();
             if (!sc.hasNextDouble())
                 throw new Exception("Incorrect data in file with table!");

             Double value = sc.nextDouble();
             Map.Entry<Double, Double>  el = new AbstractMap.SimpleEntry<>(key, value);

             table.add(el);
         }
         sc.close();

         return table;
    }

    private static void writeTableToFile(File f) throws Exception {
        PrintWriter pw;
        Scanner sc = new Scanner(System.in);

        double i = 0, end = 0, step = 0;
        try {
            pw = new PrintWriter(f);
        } catch (FileNotFoundException e) {
            throw new Exception("Can't write to file");
        }
        System.out.println("Creating table");
        System.out.println("-----------------");
        System.out.println("Start value");
        i = sc.nextDouble();

        System.out.println("End value");
        end = sc.nextDouble();

        System.out.println("Step:");
        step = sc.nextDouble();

        for (; i <= end; i += step) {
            pw.printf("%.2f %f\n", i, SplineInterpolation.getActualValue(i));
            // System.out.printf("%f %.2f\n", SplineInterpolation.getActualValue(i), i);
        }

        pw.close();
    }

    private static double readDouble(Scanner sc) throws Exception {
        if (!sc.hasNextDouble()) {
            throw new Exception("Can't read double");
        }
        return sc.nextDouble();
    }

    public static void main(String[] args) {
        // print();
        int n = 0;
        double x = 0d;

        String filePath;

        // Open file with table
        // System.out.println("Input path to file with table: ");
        // filePath = sc.nextLine().trim();
        filePath = "resources/table.txt";
        File f = new File(filePath);

        // Input table
        ArrayList<Map.Entry<Double, Double>> table = null;
        try {
            writeTableToFile(f);
            table = readTableFromFile(f);

            Scanner sc = new Scanner(System.in);

            // Print readed table
            SplineInterpolation.printTable(table);

            System.out.println("Input x: ");

            x = readDouble(sc);
            sc.close();
        } catch (Exception e) {
            //System.out.println("Can't read file!");
            e.printStackTrace();
            return;
        }


        // Input x

        double result = 0d;
        Double actualResult = SplineInterpolation.getActualValue(x);
        try {
            result = SplineInterpolation.calculate(table, x);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return;
        }

        System.out.printf("Result:        %15.3f\n", result);
        System.out.printf("Actual result: %15.3f\n", actualResult);
    }
}
