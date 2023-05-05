#include <iostream>
#include <string> 
#include <cstring>
using namespace std;

class Person {
protected:
    string *name;  // 사람 이름
    int id;        // 고유한 ID 번호
    int hours;     // 일한 시간
public:
    Person(const string& name="", int id=0, int hour=0); // 생성자
    ~Person();                                           // 소멸자

    void print(ostream& out) const;
    void whatAreYouDoing() const;    // 현재하고 있는 일을 출력
    int  operator () () const;       // 임금 계산
    Person* clone() const;           // 자기 자신을 복제

    void println() const { print(cout); cout << endl; }
    Person& operator += (int hours); // 매개변수(일한 시간) hours을 멤버 hours에 더함
    void setName(const string& name) { *this->name = name; }
};

Person::Person(const string& name, int id, int hours) {
    this->id = id;
    this->name = new string(name);
    this->hours = hours;
}

Person::~Person() {
    cout << "~Person(): delete " << *name << endl;
    delete name;
}

void Person::print(ostream& out) const {
    out << "n:" << *name << " i:" << id << " h:" << hours;
}

int Person::operator () () const {
    return 8600 * hours;
}

Person & Person::operator += (int hours) {
    this->hours += hours;
    return *this;
}

void Person::whatAreYouDoing() const {

}

Person* Person::clone() const {
// TODO: 아래 nullptr 대신 구현하라. 자신을 복제한 새로운 객체의 포인터를 반환하라. 
    return nullptr;
}

/******************************************************************************
 * Class Employee
 ******************************************************************************/
class Employee : public Person{
    string company;  // 근무회사
    int payPerHour;  // 시간당임금
    int overtime;    // 초과근무시간 설정
public:
    Employee(const string& name, int id, int hours,
        const string& company, int payPerHour, int overtime);
    ~Employee() { cout << "~Employee(): n:" << *name << "   "; }
    void print(ostream& out) const;
};

Employee::Employee(const string& name, int id, int hours,
        const string& company, int payPerHour, int overtime){
            this->id = id;
            this->name = new string(name);
            this->hours = hours;
            this -> company = company;
            this -> payPerHour = payPerHour;
            this -> overtime = overtime;
        }
void Employee::print(ostream& out) const{
    out << "n:" << *name << " i:" << id << " h:" << hours 
    << " c:" << company << " p:" << payPerHour << " o:" << overtime;
}



/******************************************************************************
 * Class Student
 ******************************************************************************/
class Student : public Person{
// 멤버 변수
    string university; // 학생이 다니는 대학교 이름
    int year;          // 학년
    int tuition;       // 한 학기당 등록금 액수
public:
    void print(ostream& out) const;
    Student(const string& name, int id, int hours,
        const string& university, int year, int tuition);
    ~Student() { cout << "~Student() : n:" << *name << "   "; }
};

Student::Student(const string& name, int id, int hours,
        const string& university, int year, int tuition){
            this->id = id;
            this->name = new string(name);
            this->hours = hours;
            this -> university = university;
            this -> year = year;
            this -> tuition = tuition;
        }
void Student::print(ostream& out) const{
    out << "n:" << *name << " i:" << id << " h:" << hours 
    << " u:" << university << " y:" << year << " t:" << tuition;
}


/******************************************************************************
 * menu_switch() 함수: 선택된 메인 메뉴 항목을 실행함
 ******************************************************************************/
string menuStr =
    "------------------ Inheritance ----------------\n"
    "  0.exit 1.print 2.addHours 3.whatAreYouDoing  \n"
    "  4.whatIsYourPay 5.copyPerson 6.deletePerson  \n"
    "-----------------------------------------------\n"
    "menu item? ";

void printPerson(Person *p)     { p->println(); }
void addHours(Person *p)        { *p += 10; }
void whatAreYouDoing(Person *p) { p->whatAreYouDoing(); }
//int  whatIsYourPay(Person *p)   { return (*p)(); } // return p->operator()();와 동일
//Person* copyPerson(Person *p)   { return p->clone(); }
//void deletePerson(Person *p)    { delete p; }

void menu_switch(int menu)
{
    Employee *e = new Employee("e", 10001, 50, "Samsung", 30000, 10);
    Student  *s = new Student ("s", 10002, 10, "Chosun",  4, 4000000);
    Person   *p;

    switch (menu) {
        case 1:
            cout << "e->print(cout): "; e->print(cout); cout << endl;
            cout << "e->println()  : "; e->println();
            cout << "printPerson(e): "; printPerson(e);
            cout << "s->print(cout): "; s->print(cout); cout << endl;
            cout << "s->println()  : "; s->println();
            cout << "printPerson(s): "; printPerson(s);
            break;
        case 2:
            cout << "e += 10    : "; (*e += 10).println();
            addHours(e);
            cout << "addHours(e): "; printPerson(e);
            cout << "s += 10    : "; (*s += 10).println();
            addHours(s);
            cout << "addHours(s): "; printPerson(s);
            break;
        case 3:
            cout << "e->whatAreYouDoing()          : "; e->whatAreYouDoing();
            cout << "whatAreYouDoing(e)            : "; whatAreYouDoing(e);
            cout << "e->Person::whatAreYouDoing()  : "; e->Person::whatAreYouDoing();
            cout << "s->whatAreYouDoing()          : "; s->whatAreYouDoing();
            cout << "whatAreYouDoing(s)            : "; whatAreYouDoing(s);
            cout << "(*s).Person::whatAreYouDoing(): "; (*s).Person::whatAreYouDoing();
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