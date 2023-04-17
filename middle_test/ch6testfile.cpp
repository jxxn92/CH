/**************************************************
    아래는 Book 클래스를 선언하고 구현한 프로그램이다.  
    프로그램의 실행결과를 참고하여 나머지 코드를 구현하라.
 **************************************************/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/******************************************************************************
 * class Book declaration
 ******************************************************************************/
class Book {
    string *pTitle; // 제목
    int *pPrice;    // 가격
    int *pPages;    // 페이지수
    static int totalcount;
    static int currentcount;
public:
    // 생성자는 오직 하나만 작성하라. (복사생성자는 예외)
    // 필요한 경우 출력결과를 참조하여 매개변수를 적절히 수정하라.
    Book(string title = "no_title", int price = 0, int pages = 1);
    Book(const Book& b);
    Book& show();
    Book& set(const string& title);
    ~Book();
    static void printBookCount();
};

/******************************************************************************
 * class Book implementation
 ******************************************************************************/

// 복사생성자를 제외한 다른 생성자는 작성하지 마라.
Book::Book(string title, int price, int pages) {
    pTitle = new string(title);
    pPrice = new int(price);
    pPages = new int(pages);
    totalcount++;
    currentcount++;
}

Book::~Book(){
    delete pTitle;
    delete pPrice;
    delete pPages;
    currentcount--;
}

Book& Book::show() {
    cout << "title: " << *pTitle << ", price: " << *pPrice << ", pages: " << *pPages << endl;
    return *this;
}

Book& Book::set(const string& title) {
    *pTitle = title;
    *pPrice += 100;
    *pPages += 1;
    return *this;
}

Book::Book(const Book& b){

    pTitle = new string;
    pPrice = new int;
    pPages = new int;

    *pTitle = *b.pTitle;
    *pPrice = *b.pPrice;
    *pPages = *b.pPages;
    cout <<"Book(const Book& b): title: "<< *pTitle <<", price: "<< *pPrice <<", pages: "<< *pPages << endl;
    currentcount++;
    totalcount++;
}
int Book::totalcount = 0;
int Book::currentcount = 0;
void Book::printBookCount(){
    cout << "talBooks: " << totalcount << ", currentBooks: "<< currentcount << endl;
}

/******************************************************************************
 * Global functions
 ******************************************************************************/
void defParam() {
    Book no_title;
    Book a("A");
    Book b("B", 10000);
    Book c("C++ Programming", 30000, 696);
    no_title.show();
    a.show();
    b.show();
    c.show();
}

void copyConst() {
    Book a("A");
    a.show();
    Book b = a;
    b.set("B").show();
    a.show();
}

void staticMembers() {
    Book::printBookCount();
    Book *books = new Book[10];
    Book::printBookCount();

    delete[] books;
    Book::printBookCount();

    books = new Book[5];
    Book::printBookCount();

    delete[] books;
    Book::printBookCount();
}

/******************************************************************************
 * main function
 ******************************************************************************/

string menuStr =
"*************** Main Menu ****************\n"
"* 0.Exit 1.defParam 2.copyConst 3.static *\n"
"******************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: defParam();      break;
        case 2: copyConst();     break;
        case 3: staticMembers(); break;
        }
    }
    cout << "Good bye!!" << endl;
}

/* 
===============================================================================
== 문제 1
=============================================================================== 
// 아래 [실행결과 1]처럼 출력되게 이 클래스의 생성자와 소멸자를 구현하라.
// 생성자의 경우 이미 만들어져 있으며 생성자 함수 선언부분만 수정하면 된다.

===============================================================================
== 실행결과 1
=============================================================================== 

*************** Main Menu ****************
* 0.Exit 1.defParam 2.copyConst 3.static *
******************************************
menu? 1
title: no_tile, price: 0, pages: 1
title: A, price: 0, pages: 1
title: B, price: 10000, pages: 1
title: C++ Programming, price: 30000, pages: 696

... // 이하 메뉴는 항상 생략


===============================================================================
== 문제 2
=============================================================================== 
// 아래 [실행결과 2]처럼 출력되게 이 클래스의 적절한 생성자 또는 멤버 함수를 구현하라.

===============================================================================
== 실행결과 2
=============================================================================== 

*************** Main Menu ****************
* 0.Exit 1.defParam 2.copyConst 3.static *
******************************************
menu? 2
title: A, price: 0, pages: 1
Book(const Book& b): title: A, price: 0, pages: 1
title: B, price: 100, pages: 2
title: A, price: 0, pages: 1


===============================================================================
== 문제 3
=============================================================================== 
// staticMembers() 함수 내의 주석을 풀어라.
// 아래 [실행결과 3]처럼 출력되게 이 클래스의 멤버 변수를 추가하고 멤버 함수를 구현하라.
// totalBooks: 지금까지 생성된 Book 객체의 총 수 (복사 생성자에 의해 생성된 객체 수도 포함해야 함)
// currentBooks: 지금까지 생성된 총 Book 객체 중에서 아직 소멸되지 않고 계속 사용 중인 객체의 수

// 아래 실행결과는 프로그램 실행 후 바로 3번 메뉴를 선택했을 경우의 결과이다.
// 다른 메뉴를 선택한 후 또는 3번 메뉴를 계속 반복하면 결과는 다르게 나올 것이다.

===============================================================================
== 실행결과 3
=============================================================================== 

*************** Main Menu ****************
* 0.Exit 1.defParam 2.copyConst 3.static *
******************************************
menu? 3
totalBooks: 0, currentBooks: 0
--------------------------
totalBooks: 10, currentBooks: 10
--------------------------
totalBooks: 10, currentBooks: 0
--------------------------
totalBooks: 15, currentBooks: 5
--------------------------
totalBooks: 15, currentBooks: 0
--------------------------
 */