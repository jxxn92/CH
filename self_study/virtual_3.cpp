#include <iostream>
using namespace std;

class Shape{
public:
    void paint(){
        draw();
    }
    virtual void draw(){
        cout << "Shape::draw() called" << endl; 
    }
};

class Circle : public Shape{
public:
    void draw() override{
        cout << "Circle::draw() called" << endl;
    }

    void repaint(){
        draw();
    }
};

class Manager{
public:
    void display(Shape *p){
        p -> draw();
    }
};

int main(){
    Shape *pShape = new Circle;
    pShape -> draw();
    pShape -> paint();
    Manager m;
    m.display(pShape);
    ((Circle *)pShape)->repaint();
}