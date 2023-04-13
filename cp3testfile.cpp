/**************************************************
 �Ʒ��� Book Ŭ������ �����ϰ� ������ ���α׷��̴�.
 ���α׷��� �������� �����Ͽ� ������ �ڵ带 �����϶�.
 **************************************************/
 #include <iostream>
 #include <cstring>
 #include <string>
 using namespace std;

class Book {
    int price;    // ����
    int pages;    // ��������
    string title; // ����
public:
    Book();  // (1)�⺻������ ����
    ~Book(); // (2)�Ҹ��� ���� 
    Book(int s, int g, string c); // (3) �Ű������� �ִ� �����ڼ���
    void show();
    void set(int _price);
};

// ���� �ڵ�� ���� �Ұ�

// ���⿡ �ڵ� �ۼ�
Book::Book(){
    
    price = 0;
    pages = 1;
    title = "white";
    cout << "�⺻ ������ ȣ��:"<< price << "," << pages << "," << title << endl;
}
Book::~Book(){
    cout << "�Ҹ��� ȣ��" << endl;
}
Book::Book(int s, int g, string c){
    price = s;
    pages = g;
    title = c;
    cout << "�Ű������� �ִ� ������ ȣ��:" << s << "," << g << "," << c << endl;

}

void Book::show()
{
    cout << "==============" << endl;
    cout << "��   ��: " << price << endl;
    cout << "��������: " << pages << endl;
    cout << "��   ��: " << title << endl;
    cout << "==============" << endl << endl;
}

// (4) set() ��� �Լ� ����
void Book::set(int _price)
{
    // �Ű����� ���� �����ϴ� ��� ������ �����ϰ� ������ ������� ��°���� �����Ͽ� �����϶�.
    price  = _price;
    pages = 500;
    title = "JAVA";
    show();
}

// �Ʒ� main() �Լ��� ���� �Ұ�

int main()
{
    int price, page;
    string title;
    Book bk1;           // �⺻ ������ ȣ��

    cout << "���� �������� å���� : ";
    cin >> price >> page >> title;
    Book bk2(price, page, title); // �Ű������� �ִ� ������ ȣ��

    cout << "\nbk1.show() " << endl;
    bk1.show();

    cout << "����? ";
    cin >> price;
    cout << "bk1.set(price) " << endl;
    bk1.set(price);

    return 0;
}

/* ���α׷� ���� ���
(���)�⺻ ������ ȣ��:0,1,white
(�Է�)���� �������� å���� : 1000 200 C++
(���)�Ű������� �ִ� ������ ȣ��:1000,200,C++

(���)bk1.show()
(���)==============
(���)��   ��: 0
(���)��������: 1
(���)��   ��: white
(���)==============

(�Է�)����? 10000
(���)bk1.set(price)
(���)==============
(���)��   ��: 10000
(���)��������: 500
(���)��   ��: JAVA
(���)==============

(���)�Ҹ��� ȣ��
(���)�Ҹ��� ȣ��
*/

