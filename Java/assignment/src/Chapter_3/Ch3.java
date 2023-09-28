package Chapter_3;

import java.util.*;

public class Ch3 {
    public static double[][] run1(Scanner s) {
        System.out.print("The number of rows in the real-number non-square array: ");
        int row = s.nextInt();
        double arr2[][] = new double[row][];

        for (int i = 0; i < row ; i++) {
            arr2[i] = new double[i+1];
            System.out.print("Input "+ (i+1) +" real numbers in row "+ (i+1) +": ");
            for(int j = 0; j < arr2[i].length; j++) {
                arr2[i][j] = s.nextDouble();
            }
        }

        System.out.println("The number of rows in the array: " + arr2.length);

        return arr2;
    }
    public static double[][] run2(Scanner s) {
        int row = 0;
        while (true) {
            System.out.print("The number of rows in the real-number non-square array: ");
            try {
                row = s.nextInt();
                if (row <= 0) {
                    System.out.println("Input a positive integer!");
                    continue;
                }
                break;
            } catch (InputMismatchException e) {
                System.out.println("Input an integer!");
                s.next();
            } catch (NegativeArraySizeException e) {
                s.next();
            }
        }

        double arr2[][] = new double[row][];

        for (int i = 0; i < row ; i++) {
            arr2[i] = new double[i+1];
            while (true) {
                System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
                for (int j = 0; j < arr2[i].length; j++) {
                    try {
                        arr2[i][j] = s.nextDouble();
                    } catch (InputMismatchException e) {
                        System.out.println("Input an integer or a real number!");
                        s.nextLine();
                        j--;
                        System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
                    }
                }
                break;
            }
        }
        System.out.println("The number of rows in the array: " + arr2.length);
        return arr2;
    }

    public static void printArray(double arr[][]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print("arr[" + i + "] ");
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
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
