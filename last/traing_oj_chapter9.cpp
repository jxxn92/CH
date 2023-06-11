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
    virtual void print(ostream& out) const;
    Person(const Person& p);
    virtual void whatAreYouDoing() const;    // 현재하고 있는 일을 출력
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
    cout << "I am taking a rest." << endl;
}

Person* Person::clone() const {
    return new Person(*this);
}

Person::Person(const Person& p){

    name = new string(*p.name);
    id = p.id;
    hours = p.hours;

}

/******************************************************************************
 * Class Employee
 ******************************************************************************/
class Employee : public Person{
public:
    string company;  // 근무회사
    int payPerHour;  // 시간당임금
    int overtime;    // 초과근무시간 설정
    Employee(const string& name, int id, int hours,
            const string& company, int payPerHour, int overtime);
    ~Employee() { cout << "~Employee(): n:" << *name << "   "; }
    void print(ostream& out) const override;
    void whatAreYouDoing() const override;
    int  operator () () const;
    Employee* clone() const;
};
Employee::Employee(const string& name, int id, int hours,const string& company, int payPerHour, int overtime){
    this->id = id;
    this->name = new string(name);
    this->hours = hours;
    this->company = company;
    this->payPerHour = payPerHour;
    this->overtime = overtime;
}

void Employee::print(ostream& out) const {
    out << "n:" << *name << " i:" << id << " h:" << hours << " c:" << company << " p:" << payPerHour << " o:" << overtime;
}

void Employee::whatAreYouDoing() const {
    cout << "I am working." << endl;
}

int Employee::operator () () const {
    return ((hours * payPerHour)+(overtime * payPerHour * 1.5));
}

Employee* Employee::clone() const {
    return new Employee(*this);
}
/******************************************************************************
 * Class Student
 ******************************************************************************/
class Student : public Person{
public:
    string university; // 학생이 다니는 대학교 이름
    int year;          // 학년
    int tuition;       // 한 학기당 등록금 액수
    Student(const string& name, int id, int hours,
            const string& university, int year, int tuition);
    ~Student() { cout << "~Student() : n:" << *name << "   "; }
    void print(ostream& out) const override;
    void whatAreYouDoing() const override;
    int  operator () () const;
    Student* clone() const;
};

Student::Student(const string& name, int id, int hours,const string& university, int year, int tuition){
    this->id = id;
    this->name = new string(name);
    this->hours = hours;  
    this->university = university;
    this->year = year;
    this->tuition = tuition;
}

void Student::print(ostream& out) const {
    out << "n:" << *name << " i:" << id << " h:" << hours << " u:" << university << " y:" << year << " t:" << tuition;
}

void Student::whatAreYouDoing() const {
    cout << "I am studying." << endl;
}

int Student::operator () () const {
    return ((hours * 1000));
}

Student* Student::clone() const {
    return new Student(*this);
}
/******************************************************************************
 * menu_switch() 함수: 선택된 메인 메뉴 항목을 실행함
 ******************************************************************************/
string menuStr =
    "--------------- Virtual Functions -------------\n"
    "  0.exit 1.print 2.addHours 3.whatAreYouDoing  \n"
    "  4.whatIsYourPay 5.copyPerson 6.deletePerson  \n"
    "-----------------------------------------------\n"
    "menu item? ";

void printPerson(Person *p)     { p->println(); }
void addHours(Person *p)        { *p += 10; }
void whatAreYouDoing(Person *p) { p->whatAreYouDoing(); }
int  whatIsYourPay(Person *p)   { return (*p)(); } // return p->operator()();와 동일
Person* copyPerson(Person *p)   { return p->clone(); }
void deletePerson(Person *p)    { delete p; }

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
        case 4:
            cout << "(*e)()          : " << (*e)() << endl;
            cout << "whatIsYourPay(e): " << whatIsYourPay(e) << endl;
            cout << "s->operator()() : " << s->operator()() << endl; // (*s)()와 동일
            cout << "whatIsYourPay(s): " << whatIsYourPay(s) << endl;
        break;
        case 5:
            cout << "e->print(cout) : "; e->print(cout); cout << endl;
            cout << "printPerson(e) : "; printPerson(e);
            p = copyPerson(e);
            cout << "p=copyPerson(e): "; printPerson(p);
            cout << "((Employee*)e->clone())->print(cout): " << endl;
            cout << "               : "; ((Employee*)e->clone())->print(cout); cout << endl;
            cout << "s->print(cout) : "; s->print(cout); cout << endl;
            cout << "printPerson(s) : "; printPerson(s);
            p = copyPerson(s);
            cout << "p=copyPerson(s): "; printPerson(p);
            cout << "((Student*)s->clone())->print(cout): " << endl;
            cout << "               : "; ((Student*)s->clone())->print(cout); cout << endl;
        break;
        case 6:
            p = copyPerson(e);
            cout << "p=copyPerson(e): "; printPerson(p); p->setName("p");
            cout << "delete p       : "; delete p;
            cout << "deletePerson(e): "; deletePerson(e);
            p = copyPerson(s);
            cout << "p=copyPerson(s): "; printPerson(p); p->setName("p");
            cout << "deletePerson(p): "; deletePerson(p);
            cout << "delete s       : "; delete s;
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