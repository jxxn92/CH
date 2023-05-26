// �̹� �ǽ��� 11�忡 ���� ���̺� �ڵ� �����̴�.
// �Ʒ� ������ ����� ��Ʈ�� �� ������ Ȱ�� �ɷ°� 
// <<, >> ���� ����� �����ڿ� ������ ���� �ɷ� ���� Ȯ����.
//
// ���� �Ʒ� �ڵ�([���� 0] �ձ���)�� ��ŷ�Ͽ� ������ �� �ҽ� ���Ͽ� �����϶�.
/******************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

/******************************************************************************
 * Class Point
 ******************************************************************************/
class Point {
    int x, y;  // ���� x, y ��ǥ ��
public:
    Point() { x = 31; y = 15; }

    friend ostream& operator << (ostream& stream, const Point& a);
    friend istream& operator >> (istream& ins, Point& a); 
};


// ���⿡ �ʿ��� ������, ������ ���� �Լ��� �����Ͻÿ�.
ostream& operator<<(ostream& stream, const Point& a) {

    stream << hex << showbase;
    stream << setfill('*') << setw(7) << a.x << ", ";
    stream << oct << showbase;
    stream << setfill('.') << setw(6) << left << a.y << ", ";
    stream << dec << noshowbase;
    stream << boolalpha << (a.x == a.y);
    stream << noboolalpha;

    stream << setfill(' ') << setw(6) << right;
    return stream;
}


ostream& leftp(ostream& outs){
    return outs << "( ";
}

ostream& rightp(ostream& outs){
    return outs << " )";
}

istream& inmsg(istream& outs){
    cout << "x, y coordinate? ";
    return outs;
}

istream& operator >> (istream& ins, Point& a){
    ins >> a.x >> a.y;
    return ins;
} 


/******************************************************************************
 * ���õ� ���� �޴� �׸��� �����ϴ� �Լ���
 ******************************************************************************/
//------------------------------------------------------
// ���: �Ʒ� �� ���� �Լ��� �ּ��� �����ϴ� �� �ܴ� �������� ���ÿ�.
//      ���� ������ ���Ǵ�� �Ʒ� �Լ��� ������ ��� 0�� ó����.
//------------------------------------------------------

Point p;

void outPoint() {
    cout << setw(3) << 1 << 2 << 3 << true << endl;
    cout << p << endl;
    cout << setw(3) << 1 << 2 << 3 << true << endl;
}

void outMnpPoint() {
    cout << leftp << p << rightp << endl;
}

void inPoint() {
    cout << "input x and y: ";
    cin >> p;
    outMnpPoint();
}

void inMnpPoint() {
    cin >> inmsg >> p;
    outMnpPoint();
}

/******************************************************************************
 * menu_switch() �Լ�: ���õ� ���� �޴� �׸��� ������
 ******************************************************************************/
string menuStr =
    "----------------------- I/O Stream -----------------------\n"
    "  0.exit 1.outPoint 2.outMnpPoint 3.inPoint 4.inMnpPoint  \n"
    "----------------------------------------------------------\n"
    "menu item? ";

void menu_switch(int menu)
{
    switch (menu) {
    case 1: outPoint();    break;
    case 2: outMnpPoint(); break;
    case 3: inPoint();     break;
    case 4: inMnpPoint();  break;
    }
    cout << endl;
}

/******************************************************************************
 * main() �Լ�
 ******************************************************************************/
int main()
{
    while (true) {
        int menu;
        cout << menuStr;
        cin >> menu;
        if (menu == 0) break;
        menu_switch(menu);
    }
    cout << "\nGood bye!!" << endl;
}