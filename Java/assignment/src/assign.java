import java.util.*;
import java.lang.NegativeArraySizeException;

public class assign {
    public static void printArray(double arr[][]) {
        System.out.println("The number of rows in the array: " + arr.length);
        for (int i = 0; i < arr.length; i++) {
            System.out.print("arr[" + i + "] ");
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static double[][] run1(Scanner s) {
        double[][] arr;
        int row;
        System.out.print("The number of rows in the real-number non-square array: ");

        row = s.nextInt();

        arr = new double[row][];

        for (int i = 0; i < row; i++)
            arr[i] = new double[i + 1];

        for (int i = 0; i < row; i++) {
            System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j] = s.nextDouble();
            }
        }
        return arr;
    }

    public static double[][] run2(Scanner s) {
        double[][] arr;
        int row;
        while (true) {
            System.out.print("The number of rows in the real-number non-square array: ");
            try {
                row = s.nextInt();
                arr = new double[row][];
                if (row >= 0) break;
            } catch (NegativeArraySizeException e) {
                System.out.println("Input a positive integer!");
                s.nextLine();
            } catch (InputMismatchException e) {
                System.out.println("Input an integer!");
                s.nextLine();
            }

        }

        for (int i = 0; i < row; i++)
            arr[i] = new double[i + 1];

        for (int i = 0; i < row; i++) {
            while (true) {
                System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
                for (int j = 0; j < arr[i].length; j++) {
                    try {
                        arr[i][j] = Double.parseDouble(String.valueOf(s.nextInt()));
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
