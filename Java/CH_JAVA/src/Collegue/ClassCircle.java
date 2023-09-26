package Collegue;

import javax.swing.*;
import java.awt.*;
import java.sql.PseudoColumnUsage;
import java.util.Objects;

public class Circle {
    int radius;
    String name;

    public Circle() {
    }



    public double getArea() {
        return 3.14 * radius * radius;
    }
}
public class ClassCircle {

    public static void main(String[] args) {
        Circle pizza = new Circle();
        pizza.radius = 10;
        pizza.name = "java pizza";

        double area = pizza.getArea();

        System.out.println(area);

        Circle donut = new Circle();
        donut.radius = 2;
        donut.name = "java donut";
        double ar = donut.getArea();
        System.out.println(ar);


    }


}
