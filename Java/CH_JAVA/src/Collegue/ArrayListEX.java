package Collegue;

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListEX {
    public static void main(String[] args) {
        ArrayList<String> a = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);

        for(int i = 0; i < 4; i++) {
            System.out.println("이름을 입력하세요 >>");
            String s = scanner.next();
            a.add(s);
        }
        for(int i = 0 ; i < a.size(); i++) {
            String name = a.get(i);
            System.out.println(name + " ");
        }

        int longestindex = 0;
        for(int i = 1; i < a.size(); i++) {
            if(a.get(longestindex).length() < a.get(i).length())
                longestindex = i;
        }
        System.out.println("가장 긴 이름은 : " + a.get(longestindex));
        scanner.close();
    }
}
