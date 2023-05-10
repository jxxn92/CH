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