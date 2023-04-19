/**************************************************
아래는 Book 클래스를 선언하고 구현한 프로그램이다.
프로그램의 실행결과를 참고하여 나머지 코드를 구현하셔요.
 **************************************************/
#include <iostream>
#include <string>
using namespace std;

class Book {
    int price;    // 가격
    int pages;    // 페이지수
    string title; // 제목

public:
    Book();  // (1)기본생성자 선언
    ~Book(); // (2)소멸자 선언 
    Book(int s, int g, string c); // (3) 매개변수가 있는 생성자선언
    void show();
    void set(int price, int pages, string title);
    //(4) 출력 결과를 보고 set() 함수를 적절히 선언할 것 (하나의 set 함수만 선언할 것)
};

// 위에 코드는 수정 불가

// 여기에 코드 작성

// (1) 기본생성자 구현
Book::Book(){
    price = 10;
    pages = 20;
    title = "html";
    cout << "기본 생성자 호출:" << price << "," << pages << "," << title << endl;
}
// (2) 소멸자 구현 
Book::~Book(){
    cout << "소멸자 호출" << endl;
}
// (3) 매개변수가 있는 생성자 구현
Book::Book(int s, int g, string c){
    price = s;
    pages = g;
    title = c;
}
void Book::show()
{
    cout << "==============" << endl;
    cout << "가   격: " << price << endl;
    cout << "페이지수: " << pages << endl;
    cout << "제   목: " << title << endl;
    cout << "==============" << endl << endl;
}

// (4) 아래 set() 함수 외에 또 다른 set() 함수를 중복하여 구현하지 말 것.
void Book::set(int price, int pages, string title)
{
   // 매개변수 값을 상응하는 멤버 변수에 저장
    this -> price = price;
    this -> pages = pages;
    this -> title = title;
    show();
}

// 아래 main() 함수는 수정 불가

int main()
{
    int price, page;
    string title;
    Book bk1;           // 기본 생성자 호출

    cout << "가격 페이지수 책제목 : ";
    cin >> price >> page >> title;
    Book bk2(price, page, title); // 매개변수가 있는 생성자 호출

    cout << "\nbk1.show() " << endl;
    bk1.show();

    cout << "가격 페이지수 책제목? ";
    cin >> price >> page >> title;
    cout << "bk1.set(price, page, title) " << endl;
    bk1.set(price, page, title);

    return 0;
}
