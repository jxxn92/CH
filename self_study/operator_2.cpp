#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Point{
    int x;
    int y;
public:
    Point(){x=0;y=0;}
    Point(int xx,int yy){x = xx; y = yy;}
    int getX() {return x;}
    int getY() {return y;}
    Point operator+(Point ob)
    {
        Point temp;
        temp.x = x + ob.x;
        temp.y = y + ob.y;
        return temp;
    }
    Point operator-(Point ob)
    {
        Point temp;
        temp.x = x - ob.x;
        temp.y = y - ob.y;
        return temp;
    }
    Point operator*(Point ob)
    {
        Point temp;
        temp.x = x * ob.x;
        temp.y = y * ob.y;
        return temp;
    }
    Point operator/(const Point& ob)
    {
        Point temp;
        temp.x = x / ob.x;
        temp.y = y / ob.y;
        return temp;
    }
};

int main(void){
    
    Point ob1(3,5);
    Point ob2(1,2);
    Point ob3;

    cout << ob3.getX() << "," << ob3.getY() << " ";
    cout << endl;
    ob3 = ob1 + ob2;
    cout << ob3.getX() << "," << ob3.getY();
    cout << endl;
    ob3 = ob1 - ob2;
    cout << ob3.getX() << "," << ob3.getY();
    cout << endl;
    ob3 = ob1 * ob2;
    cout << ob3.getX() << "," << ob3.getY();
    cout << endl;
    ob3 = ob1 / ob2;
    cout << ob3.getX() << "," << ob3.getY();

    return 0;

}