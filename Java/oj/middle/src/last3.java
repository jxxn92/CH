import java.util.InputMismatchException;
import java.util.Scanner;

public class last3 {
    public static void printArray(double arr[][]) {
        System.out.println("The number of rows in the array: " + arr.length);
        for(int i = 0; i < arr.length; i++) {
            System.out.print("arr[" + i + "]");
            for(int j = 0; j < arr[i].length; j++) {
                System.out.print(" " + arr[i][j]);
            }
            System.out.println();
        }
    }

    public static double[][] run1(Scanner s) {
        int num;
        System.out.print("The number of rows in the real-number non-square array: ");
        num = s.nextInt();
        double arr[][];
        arr = new double[num][];

        for(int i = 0; i < arr.length; i++) {
            arr[i] = new double[i+1];
            System.out.print("Input " + (i+1) + " real numbers in row " + (i+1) + ": ");
            for(int j = 0; j < arr[i].length; j++) {
                double data = s.nextDouble();
                arr[i][j] = data;
            }
        }
        return arr;
    }

    public static double[][] run2(Scanner s) {
        int num;
        double arr[][];
        while (true) {
            try {
                System.out.print("The number of rows in the real-number non-square array: ");
                num = s.nextInt();
                arr = new double[num][];

                for (int i = 0; i < arr.length; i++) {
                    arr[i] = new double[i + 1];
                    while (true) {
                        try {
                            System.out.print("Input " + (i + 1) + " real numbers in row " + (i + 1) + ": ");
                            for (int j = 0; j < arr[i].length; j++) {
                                double data = s.nextDouble();
                                arr[i][j] = data;
                            }
                            break;
                        }catch (InputMismatchException e) {
                            System.out.println("Input an integer or a real number!");
                            s.nextLine();
                        }
                    }
                }
                return arr;
            } catch (NegativeArraySizeException e) {
                System.out.println("Input a positive integer!");
            } catch (InputMismatchException e) {
                System.out.println("Input an integer!");
                s.nextLine();
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


