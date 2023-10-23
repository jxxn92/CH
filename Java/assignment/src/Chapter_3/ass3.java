package Chapter_3;

import java.util.*;
import java.lang.*;

public class ass3 {
    public static void printArray(double arr[][]) {
        System.out.println("The number of rows in the array: " + arr.length);
        for(int i = 0; i < arr.length; i++) {
            System.out.print("arr[" + i + "] ");
            for(int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static double[][] run1(Scanner s) {
        int row;
        System.out.print("The number of rows in the real-number non-square array: ");
        row = s.nextInt();
        double arr[][] = new double[row][];

        for(int i = 0; i < row; i++) {
            System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
            arr[i] = new double[i + 1];
            for(int j = 0; j < arr[i].length; j++) {
                arr[i][j] = s.nextDouble();
            }
        }
        return arr;
    }

    public static double[][] run2(Scanner s) {
        double[][] arr;
        int row;

        while (true){
            try {
                System.out.print("The number of rows in the real-number non-square array: ");
                row = s.nextInt();
                arr = new double[row][];

                for(int i = 0; i < row; i ++) {
                    arr[i] = new double[i+1];
                    System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
                    for(int j = 0; j < arr[i].length; j++) {
                        try {
                            arr[i][j] = s.nextDouble();
                        } catch (InputMismatchException e) {
                            s.nextLine();
                            j--;
                            System.out.println("Input an integer or a real number!");
                        }
                    }
                } break;
            } catch (InputMismatchException e) {
                System.out.println("Input an integer!");
                s.nextLine();
            } catch (NegativeArraySizeException e) {
                System.out.println("Input a positive integer!");
                s.nextLine();
            }

        }
        return arr;
    }

    public static void main(String[] args) {
        double array[][] = { {0}, {1,2}, {3,4,5} };
        printArray(array);
        System.out.println();

        Scanner scanner = new Scanner(System.in);
        double dArr1[][] = run1(scanner);
        printArray(dArr1);
        System.out.println();

        double dArr2[][] = run2(scanner);
        printArray(dArr2);
        System.out.println();

        scanner.close();
        System.out.println("Exit.");
    }
}