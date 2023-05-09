#include <iostream>
using namespace std;

class Base{
public:
    void f(){cout << "Base::f() called" << endl; }
};

class Derived : public Base{
public:
    void f(){ cout << "Derived::f() called" << endl; }
};

int main(void){
    Derived d;
    Derived *pDer;

    pDer = &d;
    pDer -> f();

    Base *pBer;
    pBer = &d;
    pBer -> f();

    return 0;
}