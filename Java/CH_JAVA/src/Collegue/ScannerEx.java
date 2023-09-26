package Collegue;
import  java.util.Scanner;

public class ScannerEx {
    public static void main(String[] args) {

        System.out.println("이름, 도시, 나이, 체중, 독신 여부를 빈칸으로 분리하여 입력하세요.");
        Scanner sc = new Scanner(System.in);

        String name = sc.next();
        System.out.print("이름은 : " + name);

        String city = sc.next();
        System.out.print(" 도시는 : " + city);

        int age = sc.nextInt();
        System.out.print(" 나이는 : " + age);

        double weight = sc.nextDouble();
        System.out.print(" 몸무게는 : " + weight);

        boolean single = sc.nextBoolean();
        System.out.print(" 독신여부는 : " + single + "입니다.");
    }
}
