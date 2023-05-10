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
    cout << msg;
    int num;
    cin >> num;
    return num;
}

void UI::println(string msg){
    cout << msg;
    cout << endl;
}

void UI::print(string msg){
    cout << msg;
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

void Line::draw(){
    cout << "Line" << endl;
}