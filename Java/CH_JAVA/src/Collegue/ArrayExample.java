package Collegue;

import java.util.Scanner;

public class ArrayExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int intArray[] = new int[5];

        int max = 0;
        System.out.println("5개의 양수를 입력하세요.");

        for(int i = 0; i < intArray.length; i++) {
            intArray[i] = sc.nextInt();
            if ( intArray[i] > max) {
                max = intArray[i];
            }
        }
        System.out.println("가장 큰 수는 "+ max + "입니다.");
        sc.close();
    }
}
