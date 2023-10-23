
import java.util.*;

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
    // msg를 출력한 후 정수 값 하나를 입력 받아 리턴
    // MAIN_MENU 선택을 위한 메소드
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

        int nShape = scanner.nextInt();

        return nShape;

    }

    static public Point getWidthHeight(Scanner scanner, String msg) {
        System.out.print(msg);
        // width, height 변수 선언
        int width;
        int height;

        width = scanner.nextInt();
        height = scanner.nextInt();

        Point point = new Point(width, height);

        return point;
    }

    static public int getRadius(Scanner scanner, String msg) {
        System.out.print(msg);
        int radius;

        radius = scanner.nextInt();

        return radius;

    }
}

/*****************************************************************************
    Circle 객체의  중심점
        Line   객체의 두 점
        Rectangle 객체의 두 꼭지점의 정보를 저장할 자료형
*****************************************************************************/

class Point {
    int x; // 점의 x 좌표 값
    int y; // 점의 y 좌표 값

    // 객체 초기화: x, y 좌표 초기화
    public Point(int x, int y) {
        this.x = x;	this.y = y;
    }

    // x, y 좌표를 각각 width, height만큼 이동시킨다.
    public void move(int width, int height) {
        this.x += width;
        this.y += height;
    }

    // (x,y) 좌표 문자열을 리턴, 예) "(10, 15)"
    // 메소드 오버라이딩, Object 클래스의 public String toString()을 오버라이딩
    @Override
    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }
}



//*****************************************************************************
// Shape의 추상 클래스 선언 
abstract class Shape {
    public abstract String draw();                       // 정보 출력
    public abstract void move(int width, int height);    // 좌표 이동
};


/*****************************************************************************
Line 클래스 선언 및 구현
*****************************************************************************/

class Line extends Shape {
    private Point p1;	// 사각형의 왼쪽 위쪽 좌표
    private Point p2;	// 사각형의 오른쪽 아래쪽 좌표

    // 생성자 작성
    public Line(Point p1, Point p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    // Shape 의 draw 메소드 오버라이딩
    // 실질적인 자료를 리턴하는 함수는 toString
    // 함수 내부에서 toString() 메소드 호출
    @Override
    public String draw() { return toString(); }

    // 화면에 라인의 좌표 값을 출력, 예) "Line (10,15) (20,30)"
    // 메소드 오버라이딩, Object 클래스의 public String toString()을 오버라이딩
    @Override
    public String toString() {
        return ( "Line " + p1 + " " + p2 );
    }

    //기존 객체의 위치를 width, height만큼 옮긴다.
    public void move(int width, int height) {
        //기존 p1의 위치를 width, height만큼 옮긴다.
        p1.move(width, height);
        //기존 p2의 위치를 width, height만큼 옮긴다.
        p2.move(width, height);
    }
}


/*****************************************************************************
    Rect 클래스 선언 및 구현
        Line 클래스를 참고하여 작성
*****************************************************************************/
class Rect extends Shape {
    private Point p1;
    private Point p2;

    //생성자: 멤버 초기화
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
        return ( "Rectangle " + p1 + " " + p2 );
    }

    public void move(int width, int height) {
        p1.move(width, height);
        p2.move(width, height);
    }
}


/*****************************************************************************
    Rect 클래스 선언 및 구현
        Line 클래스를 참고하여 작성
*****************************************************************************/
class Circle extends Shape {
    private Point center;	// 원의 중심 좌표
    private int   radius;       	// 반지름의 길이

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

        return ( "Circle " + radius + " " + center );

    }

    public void move(int width, int height) {
        center.move(width, height);
    }
}


//*****************************************************************************
// linked list에서 자료 및 링크를 관리할 node 선언
class Node  {
    public Node next;
    public Node prev;

    private Object value;   // 데이터 (업캐스팅을 통해서 관리 함, 모든 클래스의 최상위 클래스인 Object 클래스로 업캐스팅)

    public Node(Object value) {  next = null; prev = null; this.value = value; }  // 생성자
    public Object  getValue() { return value; }     // 현재 Node의 데이터 리턴
};


//*****************************************************************************
//double linked list를 위한 인터페이스 선언
interface LinkedList{
    public abstract void add_front(Object value);   // 리스트 맨 앞에 삽입
    public abstract void add_rear(Object value);    // 리스트 맨 뒤에 삽입
    public abstract boolean isEmpty(); ;            // 리스트가 empty인지 확인
    public abstract Object remove_front();          // 리스트 맨 앞에서 삭제
    public abstract Object remove_rear();           // 리스트 맨 뒤에서 삭제
}


//*****************************************************************************
// Shape을 이용한 double linked list 작성
class ShapeList implements LinkedList{

    private Node head;	// double linked 리스트의 맨 처음 노드를 가리키는 포인터
    private Node tail;		// double linked 리스트의 맨 마지막 노드를 가리키는 포인터

    ShapeList() { head= null; tail = null;} // 생성자: 멤버 초기화

    // 리스트의 맨 앞의 노드를 리턴
    public Object get_frontValue() {
        if(isEmpty()) {
            return null;
        } else {
            return head.getValue();
        }
    }

    // 리스트의 맨 뒤의 노드를 리턴
    public Object get_rearValue() {
        if(isEmpty()) {
            return null;
        } else {
            return tail.getValue();
        }
    }

    // 리스트 맨 앞에 노드 삽입
    //  인터페이스 메소드 구현
    public void add_front(Object value) {
        Node newNode = new Node(value);
        newNode.next = head;

        if(!isEmpty()) {
            head.prev = newNode;
        }
        // 기존에 노드가 있었다면
        //  현재 헤드의 이전 노드로 새로운 노드를 지정
        head = newNode;
        // 헤드로 새로운 노드를 지정

        if(head.next == null) {
            tail = head;
        }
        // 노드가 하나인지 확인
        // tail 에 head 대입

    }

    // 리스트 맨 뒤에 노드 삽입
    //  인터페이스 메소드 구현
    public void add_rear(Object value) {
        if (isEmpty()) {   // 리스트의 노드가 없다면 첫번째 노드를 추가하는 메소드를 사용합니다.
            add_front(value);
        } else {
            Node newNode = new Node(value); 			// 노드를 생성합니다.
            tail.next = newNode; 	    	// tail의 다음 노드로 생성한 노드를 지정합니다.
            newNode.prev = tail;  	        // 새로운 노드의 이전 노드로 tail을 지정합니다.
            tail = newNode;  	        // 마지막 노드를 갱신합니다.
        }
    }


    // list 가 empty인지 확인
    //  인터페이스 메소드 구현
    public boolean isEmpty() {
        if(head == null && tail == null) {
            return true;
        } else {
            return false;
        }
        // head 와  tail 이 모두 null 이면
        // true 리턴
        // 그렇지 않으면
        // false 리턴
    }

    // 리스트 맨 앞에서 삭제
    //  인터페이스 메소드 구현
    //  remove_rear 참고
    public Object remove_front() {
        if(isEmpty()) {
            return null;
        }
        Node temp = head;
        head = head.next;

        Object obj = temp;
        temp = null;

        if(head != null) {
            head.prev = null;
        }

        return obj;

    }

    // 리스트 맨 뒤에서 삭제
    //  인터페이스 메소드 구현
    public Object remove_rear() {
        if (isEmpty())       // list가 empty인지 확인
            return null;     //  empty 이면  null 리턴

        Node temp = tail;         // tail의 값을 임시변수(temp)에 저장
        tail = null;              // tail 지우기 (tail = null) 자바에서는 없어도 되는 부분
        tail = temp.prev;         // tail에 임시변수의 prev 넣기
        if (tail!= null)
            tail.next = null;      // tail의 next에 null 넣기
        else
            head=null;

        Object returnData = temp.getValue();  	 // temp로부터 리턴할 값을 임시 변수(Object 타입)에 넣기
        return returnData;              // 데이터 리턴 (Object 타입)
    }

    // 메소드 오버라이딩, Object 클래스의 public String toString()을 오버라이딩
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
                    Object data = list.get_frontValue();
                    if(data != null) {
                        p1 = UI.getWidthHeight(scanner, msgpoint);
                        ((Shape) data).move(p1.x, p1.y);
                    }
                    break;
                case Move_rear:	// 리스트 마지막 객체 이동
                    data = list.get_rearValue();
                    if(data != null) {
                        p1 = UI.getWidthHeight(scanner, msgpoint);
                        ((Shape) data).move(p1.x, p1.y);
                    }
                    //  get_rearValue메소드를 이용해서 마지막 shape 정보 가지고 오기
                    //  shape 이 널이 아니면
                    //     이동을 위한 정보 받기, UI.getWidthHeight 이용
                    //      좌표이동
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

public class test5 {

    public static void main(String[] args) {

        GraphicEditor g = new GraphicEditor();  		// GraphicEditor  생성
        g.run();                                                                // 실행 함수 호출

        System.out.println("Good Bye");
    }
}




// 프로그램의 전체 구성도와 실행결과는 아래와 같다.
/*************************************************************************************
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 1
 Select one Shape
 Rectangle:0, Circle:1, Line:2 >> 1
 Enter point coordinates (enter two integers) >> 10 20
 Enter the radius (enter one integer) >>
 5
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 [Circle 5 (10, 20)]
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 0
 Select one Shape
 Rectangle:0, Circle:1, Line:2 >> 0
 Enter point coordinates (enter two integers) >> 10 20
 Enter point coordinates (enter two integers) >> 30 40
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 [Rectangle  (10, 20) (30, 40)], [Circle 5 (10, 20)]
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 1
 Select one Shape
 Rectangle:0, Circle:1, Line:2 >> 2
 Enter point coordinates (enter two integers) >> 40 50
 Enter point coordinates (enter two integers) >> 40 70
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 [Rectangle  (10, 20) (30, 40)], [Circle 5 (10, 20)], [Line (40, 50) (40, 70)]
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 4
 The two integers to move along the X and Y axes (enter two integers) >> 5 10
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 [Rectangle  (15, 30) (35, 50)], [Circle 5 (10, 20)], [Line (40, 50) (40, 70)]
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 5
 The two integers to move along the X and Y axes (enter two integers) >> 3 7
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 [Rectangle  (15, 30) (35, 50)], [Circle 5 (10, 20)], [Line (43, 57) (43, 77)]
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 3
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 [Rectangle  (15, 30) (35, 50)], [Circle 5 (10, 20)]
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 4
 The two integers to move along the X and Y axes (enter two integers) >> 6 5
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 [Rectangle  (21, 35) (41, 55)], [Circle 5 (10, 20)]
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 2
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 [Circle 5 (10, 20)]
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 2
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 6
 Select one operation
 Insert(Front):0, Insert(Rear):1, Remove(Front):2, Remove(Rear):3, Move(Front):4, Move(Rear):5, Print List:6, Exit:7 >> 7
 Good Bye

 *************************************************************************************/