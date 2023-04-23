#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Book {
    string title;         // 책 제목
    int    price;         // 책 가격
    bool   isBestSeller;  // 베스트 셀러 책인가?
public:
    static int TotalSoldCount;
    Book(string title ="no-title", int price=10000, bool isBestSeller = 0);
    void show();
    void set(string title);
    void set(int price);
    void set(bool isBestSeller);
    void set(string title,int price,bool isBesetSeller);
    void sell(int count); 
    static int getSoldCount();
    
};

int Book::TotalSoldCount = 0;

int Book::getSoldCount(){
    return TotalSoldCount;
}

void Book::show() {
    cout << "t:" << title << ", p:" << price << ", b:" << isBestSeller << endl;
}

Book::Book(string title, int price, bool isBestSeller) {
    this -> title = title;
    this -> price = price;
    this -> isBestSeller = isBestSeller;
    cout << "Book(...): "; show();
}
void Book::set(string title){
    this -> title = title;
}
void Book::set(int price){
    this -> price = price;
}
void Book::set(bool isBestSeller){
    this -> isBestSeller = isBestSeller;
}
void Book::set(string title,int price,bool isBesetSeller){
    this -> title = title;
    this -> price = price;
    this -> isBestSeller = isBesetSeller;
}
void Book::sell(int count){
    TotalSoldCount += count;
}



// 디폴트 매개변수를 활용한 생성자
void test_1(string& title, int price, bool isBestSeller) {
    Book b1;
    Book b2("b2-title");
    Book b3("b3-title", 30000);
    Book b4(title, price, isBestSeller);
}

// 함수 중복
void test_2(string& title, int price, bool isBestSeller) {
    Book b;
    b.set(title);
    cout << "b.set(title): "; b.show();

    b.set(price);
    cout << "b.set(price): "; b.show();

    b.set(isBestSeller);
    cout << "b.set(isBestSeller): "; b.show();

    b.set("no-title", 10000, false);
    cout << "b.set(\"no-title\", 10000, false): "; b.show();

    b.set(title, price, isBestSeller);
    cout << "b.set(title, price, isBestSeller): "; b.show();
}

// static 멤버 변수 및 함수
void test_3() {
    Book b1, b2, b3, b4;
    b1.sell(1);
    b2.sell(2);
    b3.sell(3);
    int count = 4;
    cout << "count to sell b4 book? "; // b4가 팔린 책의 개수를 입력 받음
    cin >> count;
    b4.sell(count);
}

// 키보드로부터 책 제목, 가격, 베스트셀러 둥의 정보를 입력 받음
// isBestSeller: 1을 입력하면 true, 0을 입력하면 false로 설정된다.
void input_book(string& title, int& price, bool& isBestSeller) {
    cout << "input title, price, isBestSeller: ";
    cin >> title >> price >> isBestSeller;
}

int main() {
    string title("b4-title");
    int price = 40000;
    bool isBestSeller = true;
    int idx;

    input_book(title, price, isBestSeller);   // 다음을 입력하라. B4-TITLE 4444 1
    while (true) {
            cout << "test number? ";
            cin >> idx;
            if (idx == 1)
                test_1(title, price, isBestSeller);
            else if (idx == 2)
                test_2(title, price, isBestSeller);
            else if (idx == 3) {
                test_3();
                cout << "total number of sold books: " << Book::getSoldCount() << endl;
            }
            else break;
    }
}

