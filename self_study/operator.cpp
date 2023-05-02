#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Point{
    int x;
    int y;
public:
    Point(int i , int j){x = i; y=j;}
    int getX() {return x;}
    int getY() {return y;}
    void upPrint() {
        ++x;
        ++y;
        cout << x << " " << y << endl;
    }
    Point operator++()
    {
        ++x;
        ++y;
        return *this;
    }
};

int main(void){
    Point p1(3,4);
    p1.upPrint();
    ++p1;

    cout << p1.getX() << ",";
    cout << p1.getY();

    return 0;
}