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
    cout << msg;
    int num;
    cin >> num;
    return num;
}

void UI::println(string msg){
    cout << msg << endl;
}

void UI::print(string msg){
    cout << msg;
}

int UI::getMainMenu(){
    return printGetInt("����:0, ��κ���:1, �ڵ�����:2, ����̵�:3, ��λ���:4 >> ");
}

void getWidthHeight(int &width, int & height){
    cout << "X��� Y������ �̵��� ����(���� �ΰ� �Է�)? >> ";
    cin >> width >> height;
}

void UI::getWidthHeight(int &width, int &height) {
    cout << "X��� Y������ �̵��� ����(���� �� �� �Է�)? >> ";
    cin >> width >> height;
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
    this -> x = x;
    this -> y = y;
}

void Point::move(int width , int height){
    x += width;
    y += height;
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

Rect::Rect(const Point& p1, const Point& p2){
    this -> p1 = p1;
    this -> p2 = p2;
}

void Rect::draw(){
    UI::println("Rectangle " + p1.toString() + " " + p2.toString());
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

GraphicEditor::GraphicEditor(){
    pStart = pLast = nullptr;
}
void GraphicEditor::removeAllShapes(){
    for (Shape *p = pStart, *q; p != nullptr; p = q) {
        q = p->getNext();
        delete p;
    }
    pStart = pLast = nullptr;
}
GraphicEditor::~GraphicEditor(){
    removeAllShapes();
}

void GraphicEditor::add(Shape *p){ 
    if(pStart == nullptr){
        pStart = pLast = p;
    }
    else {
        // [�׸� 9-11] 16�� �κ� ����
        pLast = pLast -> add((Shape *)p);  
    }
}

bool GraphicEditor::empty(){
    if(pStart == nullptr) {
        UI::print("�׷��� ������ �����ϴ�.");
        return true;
    }
    else{
        return false;
    }
}

/* void GraphicEditor::allPaint(){ 
    Shape *p = pStart;
    for (int i = 0; p != nullptr; ++i, p = p->getNext()) {
       // �ε��� ���: ��), [1] �Ǵ� [4]
        cout << "[" + to_string(i) + "]: " << endl;
        p -> paint();
    }
} */

// ���Ե� ��� �׷��� ��ü���� ȭ�鿡 ���
void GraphicEditor::allPaint() { 
    // ó������ ������ linked list�� ���� ���鼭 ������ �׸���.
    // [�׸� 9-11] �߰��κ� ������ ��
    Shape* p = pStart;
    for (int i = 0; p != nullptr; ++i, p = p->getNext()) {
        // �ε��� ���: ��), [1] �Ǵ� [4]
        UI::print( "[" + to_string(i) + "]: " );
        p -> paint(); // ���� �׸��� public �Լ� ȣ��
    }
}

/* void GraphicEditor::allPaint() {
    // ó������ ������ linked list�� ���� ���鼭 ������ �׸���.
    // [�׸� 9-11] �߰��κ� ������ ��
    Shape* p = pStart;
    for (int i = 0; p != nullptr; ++i, p = p->getNext()) {
        cout << "[" + to_string(i) + "]: " << endl;
        p->paint(); // ���� �׸��� public �Լ� ȣ��
    }
} */


void GraphicEditor::autoInsert(){ 
    // �ڵ� ������ �׷��� ��ü�� ������ ��� ��(���� �߻�)
    //randShapeType();
    int size = Factory::getSize();
    for(int i = 0 ; i < size ; i++){
        add(Factory::create());
    }
    allPaint();
}

void GraphicEditor::allMove(){ 
    if(empty()){
        return;
    }
    int width, height;
    UI::getWidthHeight(width,height);
    Shape* p = pStart;
    
    for (int i = 0; p != nullptr; ++i, p = p->getNext()){
        p->move(width,height);
    }
    allPaint();
}

// ���� ������ ��� ��ü�� �����Ѵ�.
void GraphicEditor::allRemove(){ 
    if(empty()){
        return;
    }
    else{
        removeAllShapes();
    }
}

// ���� �޴��� ���� �ְ� ����ڰ� ������ �۾��� ������
void GraphicEditor::run(){
    // UI Ŭ������ �Լ����� ��� static �Լ���; �Լ� ȣ���� ���� 6-10 ����
    UI::println("�׷��� �������Դϴ�.");
    while(true) {
        int menu = UI::getMainMenu();
        switch(menu) {
        // ��κ����� ALL_PAINT�� enum �������̸� ���ó�� ��밡���ϸ�
        // GraphicEditor Ŭ������ ����Ǿ� ����
        case ALL_PAINT : 
            allPaint(); break;
        case AUTO_INSERT :
            autoInsert(); break;
        case ALL_MOVE :
            allMove(); break;
        case ALL_REMOVE :
            allRemove(); break;
        case EXIT :
            return;
        default:
            UI::println("��� ���� ����");
        }
    }
}

/******************************************************************************
 *
 * main() �Լ�
 *
 ******************************************************************************/

int main()
{
    GraphicEditor g;
    g.run();  // g�� ������ ������ �ƴ� �Ϲ� ��ü��
}
