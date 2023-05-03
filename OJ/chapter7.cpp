#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person {
    string *name;  // ��� �̸�
    int id;        // ������ ID ��ȣ
    int hours;     // ���� �ð�

public:
    Person(const string& name={}, int id=0, int hour=0); // ������
    ~Person();                                           // �Ҹ���
    void print(ostream& out) const;
    friend ostream& operator << (ostream& out, const Person &p);
    Person& operator+=(const int& hor);
    Person operator=(const Person& ob);
    Person& operator+(const Person& op);
    int operator()(){
        int wage = this -> hours * 8600;
        return wage;
    }

};

Person::Person(const string& name, int id, int hours) {
    this->id = id;
    this->name = new string(name);
    this->hours = hours;
}

Person::~Person() {
    delete name;
}

void Person::print(ostream& out) const {
    out << "name(" << *name << ") ID(" << id << ") hours(" << hours << ")";
}

Person& Person::operator+=(const int& hor){
    this -> hours += hor;
    return *this;
}

Person Person::operator=(const Person& ob){
    cout << ""
}

Person& Person::operator+(const Person& op){
    Person tmp;
}

ostream& operator << (ostream& out, const Person &p) {
    p.print(out);
    return out;
}

/******************************************************************************
 * menu_switch() �Լ�: ���õ� ���� �޴� �׸��� ������
 ******************************************************************************/
string menuStr =
    "---------------------- Operator ---------------------\n"
    "  0.exit  1. cout <<  2. +=  3. ()  4. =  5. +(int)  \n"
    "  6. +(int,Person)  7. ==  8. ++p  9. p++  10. p <<  \n"
    "-----------------------------------------------------\n"
    "menu item? ";

void menu_switch(int menu)
{
    Person p1("HongGD",    1, 10);
    Person p2("anonymous", 2);

    switch (menu) {
    case 1:
        cout << "p1: " << p1 << endl;
        break;
    case 2:
        cout << "p1            : " << p1 << endl;
        cout << "(p1 += 1) += 2: " << ((p1 += 1) += 2) << endl;
        cout << "p1            : " << p1 << endl;
        break;
    case 3:
        cout << "p1  : " << p1   << endl;
        cout << "p1(): " << p1() << endl;
        break;
    case 4:
        cout << "p1     : " << p1 << endl;
        cout << "p2 = p1: " << (p2 = p1) << endl;
        cout << "p2     : " << p2 << endl;
        break;

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

