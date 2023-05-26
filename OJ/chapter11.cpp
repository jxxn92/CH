// 이번 실습은 11장에 대한 라이브 코딩 연습이다.
// 아래 문제는 입출력 스트림 및 조작자 활용 능력과 
// <<, >> 등의 입출력 연산자와 조작자 구현 능력 등을 확인함.
//
// 먼저 아래 코드([문제 0] 앞까지)를 마킹하여 복사한 후 소스 파일에 삽입하라.
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
    int x, y;  // 점의 x, y 좌표 값
public:
    Point() { x = 31; y = 15; }

    friend ostream& operator << (ostream& stream, const Point& a);
    friend istream& operator >> (istream& ins, Point& a); 
};


// 여기에 필요한 연산자, 조작자 등의 함수를 구현하시오.
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
 * 선택된 메인 메뉴 항목을 실행하는 함수들
 ******************************************************************************/
//------------------------------------------------------
// 경고: 아래 네 개의 함수는 주석을 제거하는 것 외는 수정하지 마시오.
//      만약 본인의 임의대로 아래 함수를 수정할 경우 0점 처리함.
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
 * menu_switch() 함수: 선택된 메인 메뉴 항목을 실행함
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
 * main() 함수
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