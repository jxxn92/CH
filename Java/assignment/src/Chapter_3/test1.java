package Chapter_3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class test1 {

    public static void printArray(double array[][]) {
        System.out.println("The number of rows in the array: " + array.length);
        for(int i = 0; i < array.length; i++) {
            System.out.print("arr[" + i + "] ");
            for(int j = 0; j < array[i].length; j++) {
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static double[][] run1(Scanner s) {
        System.out.print("The number of rows in the real-number non-square array: ");
        int row = s.nextInt();
        double[][] array = new double[row][];

        for(int i = 0; i < row; i++) {
            System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
            array[i] = new double[i + 1];

            for(int j = 0; j < i + 1; j++) {
                array[i][j] = s.nextDouble();
            }
        }

        return array;
    }

    public static double[][] run2(Scanner s) {
        while(true) {
            try{
                System.out.print("The number of rows in the real-number non-square array: ");
                int row = s.nextInt();
                s.nextLine();
                double[][] array = new double[row][];

                for(int i = 0; i < row; i++) {
                    while (true) {
                        try{
                            System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
                            array[i] = new double[i + 1];

                            for(int j = 0; j < i + 1; j++){
                                array[i][j] = s.nextDouble();
                            }
                            break;

                        }catch (InputMismatchException e) {
                            System.out.println("Input an integer or a real number!");
                            s.nextLine();
                        }
                    }
                }
                return array;
            } catch (InputMismatchException e) {
                System.out.println("Input an integer!");
                s.nextLine();
            } catch (NegativeArraySizeException e) {
                System.out.println("Input a positive integer!");
            }
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