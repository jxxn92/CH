// ������� first last �̸��� �Է��ϴ� �ڵ带 �ۼ��϶�.
// �Ʒ� �ڵ�� �ּ��� �����ϰ� �ʿ��� ������ �ڵ���.

/*-----------------------------------------------------
 *  �Ʒ� main �Լ� ����� ���, �Է� ����: �Ʒ� (�Է�)(���)�� ������ ��
 *-----------------------------------------------------*/
//TODO (���)Enter number of people.
//TODO (�Է�)3
//TODO (���)Enter 3 first and last names.
//TODO (�Է�)Mike Tyson
//TODO (�Է�)Tyson Fury
//TODO (�Է�)Ernie Shaver
//TODO (���)Mike Tyson
//TODO (���)Tyson Fury
//TODO (���)Ernie Shaver
//TODO (���)Enter search name.
//TODO (�Է�)Tyson
//TODO (���)2
//TODO (���)delete [] p;

/*-----------------------------------------------------
 *  ���α׷� �ҽ� �ڵ�
 *-----------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

class Name{
    string first, last;
public:
    string get_first() { return first; }
    string get_last()  { return last; }
    void set_name(string f, string l);  // ��� first�� last�� ���� f�� l�� ����
};

class PersonManager{
    Name *p;
    int nofp; //Name�� ��, p�� ũ��
public:
    PersonManager(int n);    // �����ڿ��� n���� ���Ҹ� ������ Name �迭�� ���� �޸� �Ҵ� ���� �� p�� ���� ��
                             // n���� Name(first last)�� �Է� �޾� p �迭�� �� ���ҿ� ����
    void show();             // ��� n���� �̸��� first name�� last name�� ��� 
    int serarch(string str); // str�� ���� first �Ǵ� last �̸��� ���� ��ȯ
    ~PersonManager();        // �޸� ��ȯ �� "delete [] p;" ���
};
// ���� �ڵ�� ���� �Ұ�

// ���⿡ �ڵ� �ۼ�

// �Ʒ� main �Լ��� ���� �Ұ�
int main() {
    int n;
    cout << "Enter number of people." << endl;
    cin >> n;

    PersonManager people(n);

    people.show();

    cout << "Enter search name." << endl;
    string str;
    cin >> str;
    cout << people.serarch(str) << endl;

    return 0;
}