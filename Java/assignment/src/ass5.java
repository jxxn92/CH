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
        System.out.println(id + ": " + name + " [" + price/1000.0 + "]");
    }
}

class Menuboard {

    String[] menus = {"Americano", "Latte", "Mocca", "Cappuccino", "Milk Tea", "Chi Tea", "Lemon Sweet", "Jamong Honey"};
    int[] prices = {4100, 4300, 4300, 4800, 5100, 5300, 5800, 6100};
    Menu[] menuArr;

    private Menuboard() {
    }

    public static Menuboard makeBoard() {
        Menuboard menuboard = new Menuboard();
        menuboard.menuArr = new Menu[menuboard.menus.length];
        for (int i = 0; i < menuboard.menus.length; i++) {
            menuboard.menuArr[i] = new Menu(i + 1, menuboard.menus[i], menuboard.prices[i]);
        }
        return menuboard;
    }

    public void print() {
        System.out.println("***** Best Coffee *****");
        for(int i = 0; i < menuArr.length; i++){
            menuArr[i].print();
        }
        System.out.println("***********************");
    }


}

public class ass5 {
    public static void main(String[] args) {

        Menuboard mboard = Menuboard.makeBoard();
        mboard.print();
    }
}

