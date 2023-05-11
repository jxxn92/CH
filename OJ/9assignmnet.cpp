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
    
    //����ڷκ��� x,y ������ �̵��� �� width �� height�� ����
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
    case LINE: // ����
        return new Line(newPoint(), newPoint());
    case CIRCLE: // ��
        // randRadius()�� ������ ����� randRadius ��ü�� ��� �Լ� operator()�� ȣ���ϴ� ����
        return new Circle(randRadius(), newPoint());
    case RECT: // �簢��
        return new Rect(newPoint(), newPoint());
    }
    return nullptr;
}
Shape* Factory::create() {
    // randShapeType(): [LINE, RECT] ������ ������ �߻�
    // randShapeType()�� ������ ����� randShapeType ��ü�� ��� �Լ� operator()�� ȣ���ϴ� ����
    return create(randShapeType());
}

// �ڵ� ������ �׷��� ��ü�� ������ ������ ����
int Factory::getSize() {
    return randSize(); // [5, 10] ������ ���� ����
}
class GraphicEditor {
    enum { EXIT=0, ALL_PAINT=1, AUTO_INSERT=2, ALL_MOVE=3, ALL_REMOVE=4};

    Shape* pStart; // ���Ե� �׷��� ��ü���� linked ����Ʈ�� �� ó���� ����Ŵ
    Shape* pLast;  // ���Ե� �׷��� ��ü���� linked ����Ʈ�� �� �������� ����Ŵ

    void add(Shape* p);     // ���ο� �׷��� ��ü p�� �� �������� pLast ������ �߰�
    bool empty();           // ��ü�� �ϳ��� ������ üũ
    void removeAllShapes(); // ��� �׷��� ��ü ����

protected:
    void autoInsert();// ������ ������ �׷��� ��ü�� �ڵ����� ������
    void allRemove(); // ��� �׷��� ��ü���� ����
    void allPaint();  // ���Ե� ��� �׷��� ��ü���� ȭ�鿡 ���
    void allMove();   // ��� ��ü���� ����ڰ� �Է��� width, height �̵�����ŭ ��ǥ �̵�

public:
    GraphicEditor();
    ~GraphicEditor();
    void run();   // ���� �޴��� ���� �ְ� ����ڰ� ������ �۾��� ������ 
};