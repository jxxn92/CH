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
Point Point::operator++() //�ȿ� int ��� ����������
                        // ��ġ���� �˷��ִ� ǥ����.
                        // �ݵ�� int ��� �������.
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