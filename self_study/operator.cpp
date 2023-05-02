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
    Point operator++();
    Point operator--(int);
};
Point Point::operator++() //안에 int 라고 적혀있으면
                        // 후치임을 알려주는 표식임.
                        // 반드시 int 라고만 적어야함.
    {
        ++x;
        ++y;
        return *this;
    }
Point Point::operator--(int)                     
    {
        x--;
        y--;
        return *this;
    }
int main(void){
    Point p1(3,4);
    ++p1;
    cout << p1.getX() << ",";
    cout << p1.getY();
    cout << endl;
    p1--;
    cout << p1.getX() << ",";
    cout << p1.getY();
    return 0;
}