import java.util.*;

interface LinkedList{
    public abstract void add_front(Object value);
    public abstract void add_rear(Object value);
    public abstract boolean isEmpty(); ;
    public abstract Object remove_front();
    public abstract Object remove_rear();
}

class Point {
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;	this.y = y;
    }

    public void move(int width, int height) {
        this.x += width;
        this.y += height;
    }

    @Override
    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }
}

class Node  {
    public Node next;
    public Node prev;

    private Object value;

    public Node(Object value) {
        next = null;
        prev = null;
        this.value = value;
    }
    public Object  getValue() {
        return value;
    }     // 현재 Node의 데이터 리턴
}

abstract class Shape {
    public abstract String draw();
    public abstract void move(int width, int height);
};


class ShapeList implements LinkedList{

    private Node head;
    private Node tail;

    ShapeList() {
        head= null; tail = null;
    }

    public Object get_frontValue() {
        if (head == null)
            return null;
        else
            return head.getValue();
    }

    public Object get_rearValue() {
        if (tail == null)
            return null;
        else
            return tail.getValue();
    }

    public void add_front(Object value) {

        // 노드를 생성합니다.
        // 새로운 노드의 다음 노드로 헤드를 지정합니다.
        Node newNode = new Node(value);
        newNode.next = head;

        // 기존에 노드가 있었다면
        //  현재 헤드의 이전 노드로 새로운 노드를 지정
        if(!isEmpty()) {
            head.prev = newNode;
        }
        // 헤드로 새로운 노드를 지정
        head = newNode;
        // 노드가 하나인지 확인
        // tail 에 head 대입
         if(tail == null) {
             tail = head;
         }

    }

    public void add_rear(Object value) {
        if (isEmpty()) {
            add_front(value);
        } else {
            Node newNode = new Node(value);
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public boolean isEmpty() {

        if(head == null && tail == null) {
            return true;
        } else {
            return false;
        }
    }

    public Object remove_front() {

        if (isEmpty())
            return null;

        Node temp = head;
        head = head.next;

        Object returnTmp = temp.getValue();
        temp = null;
        if (head!= null)
            head.prev = null;

        return returnTmp;
    }

    public Object remove_rear() {
        if (isEmpty())
            return null;

        Node temp = tail;
        tail = null;
        tail = temp.prev;
        if (tail!= null)
            tail.next = null;
        else
            head=null;

        Object returnData = temp.getValue();
        return returnData;
    }

    @Override
    public String toString() {
        StringBuffer result = new StringBuffer("");          // 가변형 String 변수 result 선언
        if (!isEmpty()) {                                            // 리스가 empty가 아니면
            Node node = head;                          // head를 새로운 변수 node에 넣기

            while (node != null) {                          // node가 null 이 아닌 동안
                result.append("[");                     //  result에 "[" 붙이기
                result.append(node.getValue());         //  result에  node.getValue() 호출해서 결과 붙이기
                result.append("]");                     //  result에 "]" 붙이기
                if (node.next==null)                    //  node.next 가 null 이면
                    result.append("\r\n");              //  result에 "\r\n" 붙이기
                else
                    result.append(", ");                 //  result에 ", " 붙이기
                node = node.next;                         //  node = node.next 로 다음 노드로 이동
            }
        }

        return result.toString();
    }
}


class Rect extends Shape {
    private Point p1;	// 사각형의 왼쪽 위쪽 좌표
    private Point p2;	// 사각형의 오른쪽 아래쪽 좌표


    public Rect(Point p1, Point p2) {
        this.p1 = p1;
        this.p2 = p2;
    }


    @Override
    public String draw() {
        return toString();
    }


    @Override
    public String toString() {
        return "Rectangle  " + this.p1 + " " + this.p2;
    }

    public void move(int width, int height) {
        p1.move(width, height);
        p2.move(width, height);
    }
}


class Line extends Shape {
    private Point p1;
    private Point p2;

    // 생성자 작성
    public Line(Point p1, Point p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    @Override
    public String draw() { return toString(); }

    @Override
    public String toString() {
        return ( "Line " + p1 + " " + p2 );
    }

    public void move(int width, int height) {
        p1.move(width, height);
        p2.move(width, height);
    }
}

class Circle extends Shape {
    private Point center;
    private int   radius;

    public Circle(int radius, Point center) {
        this.radius = radius;
        this.center = center;
    }


    @Override
    public String draw() {
        return toString();
    }

    @Override
    public String toString() {
        //화면에 반지름과 중심 좌표 값을 출력, 예) "Circle 5 (20,30)"
        return "Circle " + radius + " " + center;
    }

    public void move(int width, int height) {
        center.move(width, height);
    }
}

enum MAIN_MENU {
    Insert_front(0), Insert_rear(1), Remove_front(2), Remove_rear(3),
    Move_front(4), Move_rear(5), list_all(6), Exit(7);

    MAIN_MENU(int value) { this.value = value; }

    private final int value;
    public int value() { return value; }
}

enum SHAPE_TYPE {
    Shape_Rect(0), Shape_Circle(1), Shape_Line(2);

    SHAPE_TYPE(int value) { this.value = value; }

    private final int value;
    public int value() { return value; }
}

class UI {
    static int getMainMenu(Scanner scanner) {
        System.out.println("Select one operation  ");   // 안내 문자 출력
        System.out.print("Insert(Front):" + MAIN_MENU.Insert_front.value() + ", "
                + "Insert(Rear):" + MAIN_MENU.Insert_rear.value() + ", "
                + "Remove(Front):" + MAIN_MENU.Remove_front.value() + ", "
                + "Remove(Rear):" + MAIN_MENU.Remove_rear.value() + ", "
                + "Move(Front):" + MAIN_MENU.Move_front.value() + ", "
                + "Move(Rear):" + MAIN_MENU.Move_rear.value() + ", "
                + "Print List:" + MAIN_MENU.list_all.value() + ", "
                + "Exit:" + MAIN_MENU.Exit.value() + " >> ");  // 연산 종류 출력

        int nMenu = scanner.nextInt();                                // 사용자가 선택한 연산 입력

        return nMenu;                                                 // 사용자가 선택한 연산 리턴
    }

    static int getShape(Scanner scanner) {
        System.out.println("Select one Shape  ");
        System.out.print("Rectangle:" + SHAPE_TYPE.Shape_Rect.value() + ", "
                + "Circle:" + SHAPE_TYPE.Shape_Circle.value() + ", "
                + "Line:" + SHAPE_TYPE.Shape_Line.value() + " >> ");

        int sType = scanner.nextInt();
        return sType;
        }

    static public Point getWidthHeight(Scanner scanner, String msg) {
        // msg 출력
        System.out.print(msg);
        // width, height 변수 선언
        int width;
        int height;
        // width 입력
        width = scanner.nextInt();
        // height 입력
        height = scanner.nextInt();

        // 포인트 객체 생성
        Point point = new Point(width, height);
        //포인트 객체 리턴
        return point;
    }

    // 안내 msg를 매개 변수로 받아 출력하고
    // Circle 객체의 반지름 하나를 입력 받아 리턴
    static public int getRadius(Scanner scanner, String msg) {
        System.out.println(msg);
        int radius;
        // radius 변수 선언
        radius = scanner.nextInt();
        // radius 입력
        return radius;
        // radius 리턴
    }
}

class GraphicEditor {
    private Shape createShape(Scanner scanner) {

        SHAPE_TYPE shapeType;
        Point p1, p2;
        int radius;

        int type = UI.getShape(scanner);

        shapeType = SHAPE_TYPE.values()[type] ;
        Shape shape = null;

        String msgpoint = "Enter point coordinates (enter two integers) >> ";
        String msgradius = "Enter the radius (enter one integer) >> ";

        switch (shapeType) {
            case Shape_Rect : // 사각형
                p1 = UI.getWidthHeight(scanner, msgpoint);
                p2 = UI.getWidthHeight(scanner, msgpoint);
                shape = new Rect(p1, p2);
                break;
            case Shape_Circle : // 원
                p1 = UI.getWidthHeight(scanner, msgpoint);
                radius = UI.getRadius(scanner, msgradius);
                shape = new Circle(radius, p1);
                break;
            case Shape_Line : // 라인
                p1 = UI.getWidthHeight(scanner, msgpoint);
                p2 = UI.getWidthHeight(scanner, msgpoint);
                shape = new Line(p1, p2);
                break;

        }
        return shape;
    }


    public void run() {
        ShapeList list = new ShapeList();             // shape 리스트를 관리할 객체 생성

        Scanner scanner = new Scanner(System.in);     // 사용자 입력을 위한 스캐너 객체 생성

        Shape shape = null;			  // 임시로 사용할 Shape 레퍼런스 변수 선언
        boolean  bLoop = true;                         // 반복문 관리용 부울린 변수
        Point p1;
        String msgpoint = "The two integers to move along the X and Y axes (enter two integers) >> ";

        while (bLoop) {
            int n = UI.getMainMenu(scanner);           // 메뉴 정보 읽어 오기
            MAIN_MENU menu = MAIN_MENU.values()[n] ;   // 열겨형의 정보로 변환

            switch (menu)
            {
                case Insert_front:	 // 리스트 앞에 삽입
                    shape = createShape(scanner);
                    list.add_front(shape);

                    break;
                case Insert_rear:  // 리스트 뒤에 삽입
                    shape = createShape(scanner);
                    list.add_rear(shape);

                    break;
                case Remove_front:	// 리스트 앞에서 삭제
                    shape = (Shape) list.remove_front();
                    break;
                case Remove_rear: // 리스트 뒤에서 삭제
                    shape = (Shape) list.remove_rear();
                    break;
                case Move_front: // 리스트 첫번째 객체 이동
                    Object val = list.get_frontValue();
                    if(val != null ) {
                        p1 = UI.getWidthHeight(scanner, msgpoint);
                        ((Shape) val).move(p1.x, p1.y);
                    }

                    break;
                case Move_rear:	// 리스트 마지막 객체 이동
                    val = list.get_rearValue();
                    if (val != null) {
                        p1 = UI.getWidthHeight(scanner, msgpoint);
                        ((Shape) val).move(p1.x, p1.y);
                    }
                    break;
                case list_all:	// 리스트 정보 출력
                    System.out.print(list.toString());
                    break;
                case Exit:
                    bLoop= false;  // 끝내기
            }
        }
        scanner.close();
    }
}

public class Main {

    public static void main(String[] args) {

        GraphicEditor g = new GraphicEditor();
        g.run();

        System.out.println("Good Bye");
    }
}
