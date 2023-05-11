#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class UI{
public:
    static void println(string msg);
    static void print(string msg);
    static int printGetInt(string msg);
    static int getMainMenu();
    
    //사용자로부터 x,y 축으로 이동할 량 width 와 height를 받음
    static void getWidthHeight(int &width, int & height);
};

int UI::printGetInt(string msg){
}

void UI::println(string msg){
}

void UI::print(string msg){
}

int UI::getMainMenu(){

}


class Point{
    int x;
    int y;
public:
    Point(int x = 0,int y = 0);
    void move(int width , int height);
    string toString();
};

Point::Point(int x, int y){

}

void Point::move(int width , int height){

}

string Point::toString(){
    return "(" + to_string(x) + "," + to_string(y) + ")";
}

class Shape{
    Shape* next;
protected:
    virtual void draw() = 0;
public:
    Shape() { next = NULL;}
    virtual ~Shape(){}
    void paint();
    Shape* add(Shape* p);
    Shape* getNext() {return next;}
    virtual void move(int width, int height) = 0;
};

void Shape::paint(){
    draw();
}

void Shape::draw(){
    cout << "--Shape--" << endl;
}

Shape* Shape::add(Shape *p){
    this -> next = p;
    return p;
}

class Line : public Shape {
    Point p1;
    Point p2;
protected:
    virtual void draw();
public:
    Line(const Point &p1,const Point& p2);
    void move(int width, int height) override;
};

Line::Line(const Point &p1 , const Point& p2){
    this -> p1 = p1;
    this -> p2 = p2;
}
void Line::draw(){
    cout << "Line" << endl;
}
void Line::draw(){
    UI::println("Line " + p1.toString() + " " + p2.toString());
}

void Line::move(int width, int height){
    p1.move(width,height);
    p2.move(width,height);
}

class Rect : public Shape{
    Point p1;
    Point p2;
protected:
    virtual void draw();
public:
    Rect(const Point& p1, const Point& p2);
    void move(int width, int height) override;
};

void Rect::draw(){
    cout << "Rectangle" << endl;
}

Rect::Rect(const Point& p1, const Point& p2){
    this -> p1 = p1;
    this -> p2 = p2;
}

void Rect::draw(){
    UI::println("Rectangler " + p1.toString() + " " + p2.toString());
}

void Rect::move(int width,int height){
    p1.move(width,height);
    p2.move(width,height);
}

class Circle : public Shape {
    Point center;
    int radius;
protected:
    virtual void draw();
public:
    Circle(int radius, const Point& er);
    void move(int width, int height) override;
};

Circle::Circle(int radius,const Point& center){
    this -> radius = radius;
    this -> center = center;
}

void Circle::draw(){
    UI::println("Circle " + to_string(radius) + " " + center.toString());
}

void Circle::move(int width,int height){
    center.move(width,height);
}

class Factory {
public:
    enum { LINE = 0, CIRCLE = 1, RECT = 2};
    static Shape *create();
    static Shape *create(int shapeType);
    static int getSize();
};

class Rand{
    int low, max, cur;
public:
    Rand(int low,int high){
        this -> low = low;
        this -> max = high - low + 1;
        this -> cur = (high - low + 1) / 2;
    }
    int operator()(){
        cur = (cur + 1) % max;
        return low+cur;
        }
};
enum { MAX_XY = 99, MIN_SIZE = 5, MID_SIZE = 10, MAX_SIZE = 20 };
static Rand randShapeType(Factory::LINE, Factory::RECT);
static Rand randXY(0, MAX_XY);
static Rand randRadius(MIN_SIZE, MAX_SIZE);
static Rand randSize(MIN_SIZE, MID_SIZE);
static Point newPoint()        { return Point(randXY(), randXY()); }

Shape* Factory::create(int shapeType) {
    switch (shapeType) {
    case LINE: // 라인
        return new Line(newPoint(), newPoint());
    case CIRCLE: // 원
        // randRadius()는 위에서 선언된 randRadius 객체의 멤버 함수 operator()를 호출하는 것임
        return new Circle(randRadius(), newPoint());
    case RECT: // 사각형
        return new Rect(newPoint(), newPoint());
    }
    return nullptr;
}
Shape* Factory::create() {
    // randShapeType(): [LINE, RECT] 범위의 난수를 발생
    // randShapeType()는 위에서 선언된 randShapeType 객체의 멤버 함수 operator()를 호출하는 것임
    return create(randShapeType());
}

// 자동 생성할 그래픽 객체의 개수를 난수로 생성
int Factory::getSize() {
    return randSize(); // [5, 10] 범위의 난수 생성
}
class GraphicEditor {
    enum { EXIT=0, ALL_PAINT=1, AUTO_INSERT=2, ALL_MOVE=3, ALL_REMOVE=4};

    Shape* pStart; // 삽입된 그래픽 객체들의 linked 리스트의 맨 처음을 가리킴
    Shape* pLast;  // 삽입된 그래픽 객체들의 linked 리스트의 맨 마지막을 가리킴

    void add(Shape* p);     // 새로운 그래픽 객체 p를 맨 마지막인 pLast 다음에 추가
    bool empty();           // 객체가 하나도 없는지 체크
    void removeAllShapes(); // 모든 그래픽 객체 삭제

protected:
    void autoInsert();// 임의의 개수의 그래픽 객체를 자동으로 삽입함
    void allRemove(); // 모든 그래픽 객체들을 삭제
    void allPaint();  // 삽입된 모든 그래픽 객체들을 화면에 출력
    void allMove();   // 모든 객체들을 사용자가 입력한 width, height 이동량만큼 좌표 이동

public:
    GraphicEditor();
    ~GraphicEditor();
    void run();   // 메인 메뉴를 보여 주고 사용자가 선택한 작업을 실행함 
};