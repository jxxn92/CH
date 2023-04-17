/**************************************************
    �Ʒ��� Book Ŭ������ �����ϰ� ������ ���α׷��̴�.  
    ���α׷��� �������� �����Ͽ� ������ �ڵ带 �����϶�.
 **************************************************/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/******************************************************************************
 * class Book declaration
 ******************************************************************************/
class Book {
    string *pTitle; // ����
    int *pPrice;    // ����
    int *pPages;    // ��������
    static int totalcount;
    static int currentcount;
public:
    // �����ڴ� ���� �ϳ��� �ۼ��϶�. (��������ڴ� ����)
    // �ʿ��� ��� ��°���� �����Ͽ� �Ű������� ������ �����϶�.
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

// ��������ڸ� ������ �ٸ� �����ڴ� �ۼ����� ����.
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
== ���� 1
=============================================================================== 
// �Ʒ� [������ 1]ó�� ��µǰ� �� Ŭ������ �����ڿ� �Ҹ��ڸ� �����϶�.
// �������� ��� �̹� ������� ������ ������ �Լ� ����κи� �����ϸ� �ȴ�.

===============================================================================
== ������ 1
=============================================================================== 

*************** Main Menu ****************
* 0.Exit 1.defParam 2.copyConst 3.static *
******************************************
menu? 1
title: no_tile, price: 0, pages: 1
title: A, price: 0, pages: 1
title: B, price: 10000, pages: 1
title: C++ Programming, price: 30000, pages: 696

... // ���� �޴��� �׻� ����


===============================================================================
== ���� 2
=============================================================================== 
// �Ʒ� [������ 2]ó�� ��µǰ� �� Ŭ������ ������ ������ �Ǵ� ��� �Լ��� �����϶�.

===============================================================================
== ������ 2
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
== ���� 3
=============================================================================== 
// staticMembers() �Լ� ���� �ּ��� Ǯ���.
// �Ʒ� [������ 3]ó�� ��µǰ� �� Ŭ������ ��� ������ �߰��ϰ� ��� �Լ��� �����϶�.
// totalBooks: ���ݱ��� ������ Book ��ü�� �� �� (���� �����ڿ� ���� ������ ��ü ���� �����ؾ� ��)
// currentBooks: ���ݱ��� ������ �� Book ��ü �߿��� ���� �Ҹ���� �ʰ� ��� ��� ���� ��ü�� ��

// �Ʒ� �������� ���α׷� ���� �� �ٷ� 3�� �޴��� �������� ����� ����̴�.
// �ٸ� �޴��� ������ �� �Ǵ� 3�� �޴��� ��� �ݺ��ϸ� ����� �ٸ��� ���� ���̴�.

===============================================================================
== ������ 3
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