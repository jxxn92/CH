package Collegue;

import java.util.Scanner;

class Rectangle {
    int width;
    int height;

    public int getArea() {
        return width * height;
    }
}

public class ClassRect {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle();
        Scanner sc = new Scanner(System.in);

        System.out.print(">>");
        rect.width = sc.nextInt();
        rect.height = sc.nextInt();

        System.out.println("사각형 크기는 :" + rect.getArea());
        sc.close();
    }

}
