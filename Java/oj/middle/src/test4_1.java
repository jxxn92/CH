import java.util.Scanner;

class Menu {
    private int id;
    private String name;
    private double price;

    public Menu(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void print() {
        System.out.println(id + ": " + name + " [" + price + "]");
    }
}

class Menuboard {

    static String[] menus = {"Americano", "Latte", "Mocca", "Cappuccino", "Milk Tea", "Chi Tea", "Lemon Sweet", "Jamong Honey"};
    static int[] prices = {4100, 4300, 4300, 4800, 5100, 5300, 5800, 6100};
    static Menu[] menuArr;

    private Menuboard() {};

    public static Menuboard makeBoard() {
        menuArr = new Menu[menus.length];
        for(int i = 0; i < menus.length; i++) {
            menuArr[i] = new Menu(i + 1, menus[i], (prices[i] / 1000.0));
        }
        return new Menuboard();
    }

    public void print() {
        System.out.println("***** Best Coffee *****");
        for(int i = 0; i < menus.length; i++) {
            menuArr[i].print();
        }
        System.out.println("***********************");
    }
}

class Order {
    int[] no;
    int[] qty;

    public Order(int num) {
        no = new int[num];
        qty = new int[num];
    }

    public void addMenu(int num, int menuNo, int menuQty) {
        int i = num;
        no[i] = menuNo;
        qty[i] = menuQty;
    }

    public void print() {
        System.out.println("** Order details **");
        for(int i = 0; i < no.length; i++) {
            System.out.println("Menu: " + Menuboard.menus[no[i]-1] + " Qty: "+  qty[i] + " Price: " + Menuboard.prices[no[i]-1] * qty[i]);
        }
    }
}

class MenuOrder {

    public static void makeOrder() {
        Menuboard menuboard = Menuboard.makeBoard();
        menuboard.print();

        Scanner sc = new Scanner(System.in);
        System.out.print("How many kinds of drinks? ");
        int num = sc.nextInt();
        Order order = new Order(num);

        for(int i = 0; i < num; i++) {
            System.out.print("Menu no? ");
            int menuNo = sc.nextInt();
            if( menuNo >= 1 && menuNo <= menuboard.menus.length) {
                System.out.print("Quantity? ");
                int menuQty = sc.nextInt();
                order.addMenu(i, menuNo, menuQty);
                System.out.println("Your selected menu is added to the order");
            } else {
                System.out.print("Quantity? ");
                int menuQty = sc.nextInt();
                System.out.println("Menu id " + menuNo + " doesn't exist in our menuboard");
                i--;
                sc.nextLine();
            }
        }

        order.print();

    }

}

public class test4_1 {
    public static void main(String[] args) {
        MenuOrder.makeOrder();
    }
}


























