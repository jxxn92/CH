#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/******************************************************************************
 * Person class
 ******************************************************************************/
class Person {
    string *name;  // 사람 이름
    int id;        // 고유한 ID 번호
    int hours;     // 일한 시간

public:
    Person(const string& name={}, int id=0, int hour=0); // 생성자
    ~Person();                                           // 소멸자
    void print(ostream& out) const;
    friend ostream& operator << (ostream& out, const Person &p);
    Person (const Person& copy);
    Person& operator +=(const int& tmp);
    int operator()();
    Person& operator =(const Person& p);
    Person operator+ (const int& cnt);
    friend Person operator+(int cnt,const Person& p);
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

ostream& operator << (ostream& out, const Person &p) {
    p.print(out);
    return out;
}

Person::Person(const Person& copy){
    this -> name = new string(*copy.name);
    this -> id = copy.id;
    this -> hours = copy.hours;
}


Person& Person::operator +=(const int& tmp){
    this -> hours += tmp;
    return *this;
}
int Person::operator()(){
    return this -> hours * 8600;
}

Person& Person::operator=(const Person& p){
    
    name = new string (*p.name);
    id = p.id;
    hours = p.hours;
    return *this;
}

Person Person::operator+(const int& cnt) {

    Person tmp = *this;
    tmp.hours += cnt;
    return tmp;
}

Person operator+(int cnt,const Person& p){
    Person tmp = p;

    tmp.hours += cnt;
    return tmp;


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
    cout << endl;
    case 4:
        cout << "p1     : " << p1 << endl;
        cout << "p2 = p1: " << (p2 = p1) << endl;
        cout << "p2     : " << p2 << endl;
        break;
    case 5:
        cout << "p1        : " << p1 << endl;
        cout << "p1 + 3 + 4: " << p1 + 3 + 4 << endl;
        cout << "p1        : " << p1 << endl;
    break;

    }   
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

