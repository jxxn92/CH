#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person {
    string *name;  
    int id;        
    int hours;     

public:
    Person(const string& name={}, int id=0, int hour=0); // 생성자
    ~Person();                                           // 소멸자
    void print(ostream& out) const;
    Person(const Person& copy);
    friend ostream& operator << (ostream& out, const Person &p);
    Person& operator+=(const int& hor);
    Person& operator<<(const int& hor);
    Person& operator=(const Person& com);
    Person operator+(const int& cnt);
    friend bool operator==(const Person& op1,const Person &op2);
    Person operator++();
    Person operator++(int);
    int operator()();
    friend Person operator+(int op1,const Person& op2);
};

Person::Person(const string& name, int id, int hours) {
    this->id = id;
    this->name = new string(name);
    this->hours = hours;
}

Person::~Person() {
    delete name;
}

Person::Person(const Person& copy){
    this->name = new string(*copy.name);
    this -> id = copy.id;
    this -> hours = copy.hours;
}

void Person::print(ostream& out) const {
    out << "name(" << *name << ") ID(" << id << ") hours(" << hours << ")";
}

Person& Person::operator+=(const int& hor){
    this -> hours += hor;
    return *this;
}

Person& Person::operator<<(const int& hor){
    this -> hours += hor;
    return *this;
}

Person& Person::operator=(const Person& com){

    name = new string(*com.name);
    id = com.id;
    hours = com.hours;
    return *this;

}

Person Person::operator+(const int& cnt) {
    Person tmp = *this;
    tmp.hours += cnt;
    return tmp;
}

Person operator+(int op1,const Person& op2){
    Person tmp = op2;
    tmp.hours = op1 + op2.hours;
    return tmp;
}

int Person::operator()(){
    return this -> hours * 8600;
}

Person Person::operator++(){
    ++hours;
    return *this;
}

Person Person::operator++(int){
    Person tmp = *this;
    (this -> hours)++;
    return tmp;
}

bool operator==(const Person& op1,const Person& op2){
    return (*op1.name == *op2.name && op1.id == op2.id);
}

ostream& operator << (ostream& out, const Person &p) {
    p.print(out);
    return out;
}

/******************************************************************************
 * menu_switch() 함수: 선택된 메인 메뉴 항목을 실행함
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
    case 5:
        cout << "p1        : " << p1 << endl;
        cout << "p1 + 3 + 4: " << (p1 + 3 + 4) << endl;
        cout << "p1        : " << p1 << endl;
        break;
    case 6:
        cout << "p1          : " << p1 << endl;
        cout << "5 + (2 + p1): " << 5 + (2 + p1) << endl;
        cout << "p1          : " << p1 << endl;
        break;
    case 7:
        cin >> boolalpha;
        cout << boolalpha;
        cout << "p1      : " << p1 << endl;
        cout << "p2      : " << p2 << endl;
        cout << "p1 == p2: " << (p1 == p2) << endl;
        cout << "(p2 = p1) == p1: " << ((p2 = p1) == p1) << endl;
        cout << "p2      : " << p2 << endl;
        break;
    case 8:
        cout << "p1  : " << p1   << endl;
        cout << "++p1: " << ++p1 << endl;
        cout << "p1  : " << p1   << endl;
        break;
    case 9:
        cout << "p1  : " << p1   << endl;
        cout << "p1++: " << p1++ << endl;
        cout << "p1  : " << p1   << endl;
        break;
    case 10:
        cout << "p1      : " << p1 << endl;
        cout << "p1 << 10: " << (p1 << 10) << endl;
        cout << "p1      : " << p1 << endl;
        break;
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

