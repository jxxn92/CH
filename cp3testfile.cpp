/**************************************************
 아래는 Book 클래스를 선언하고 구현한 프로그램이다.
 프로그램의 실행결과를 참고하여 나머지 코드를 구현하라.
 **************************************************/
 #include <iostream>
 #include <cstring>
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
    void set(int _price);
};

// 위에 코드는 수정 불가

// 여기에 코드 작성
Book::Book(){
    
    price = 0;
    pages = 1;
    title = "white";
    cout << "기본 생성자 호출:"<< price << "," << pages << "," << title << endl;
}
Book::~Book(){
    cout << "소멸자 호출" << endl;
}
Book::Book(int s, int g, string c){
    price = s;
    pages = g;
    title = c;
    cout << "매개변수가 있는 생성자 호출:" << s << "," << g << "," << c << endl;

}

void Book::show()
{
    cout << "==============" << endl;
    cout << "가   격: " << price << endl;
    cout << "페이지수: " << pages << endl;
    cout << "제   목: " << title << endl;
    cout << "==============" << endl << endl;
}

// (4) set() 멤버 함수 구현
void Book::set(int _price)
{
    // 매개변수 값을 상응하는 멤버 변수에 저장하고 나머지 멤버들은 출력결과를 참고하여 설정하라.
    price  = _price;
    pages = 500;
    title = "JAVA";
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

    cout << "가격? ";
    cin >> price;
    cout << "bk1.set(price) " << endl;
    bk1.set(price);

    return 0;
}

/* 프로그램 실행 결과
(출력)기본 생성자 호출:0,1,white
(입력)가격 페이지수 책제목 : 1000 200 C++
(출력)매개변수가 있는 생성자 호출:1000,200,C++

(출력)bk1.show()
(출력)==============
(출력)가   격: 0
(출력)페이지수: 1
(출력)제   목: white
(출력)==============

(입력)가격? 10000
(출력)bk1.set(price)
(출력)==============
(출력)가   격: 10000
(출력)페이지수: 500
(출력)제   목: JAVA
(출력)==============

(출력)소멸자 호출
(출력)소멸자 호출
*/

