package Collegue;

import java.util.Scanner;

public class BreakExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("exit를 입력하면 종료합니다.");

        while (true) {
            System.out.print(">>");
            String text = sc.nextLine();
            if (text.equals("exit")){
                break;
            }
        }
        System.out.println("종료합니다....");
        sc.close();
    }
}
