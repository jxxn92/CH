#include <iostream>
#include <string> 
#include <cstring>
using namespace std;

class Person {
protected:
    string *name;  // ��� �̸�
    int id;        // ������ ID ��ȣ
    int hours;     // ���� �ð�
public:
    Person(const string& name="", int id=0, int hour=0); // ������
    ~Person();                                           // �Ҹ���

    void print(ostream& out) const;
    void whatAreYouDoing() const;    // �����ϰ� �ִ� ���� ���
    int  operator () () const;       // �ӱ� ���
    Person* clone() const;           // �ڱ� �ڽ��� ����

    void println() const { print(cout); cout << endl; }
    Person& operator += (int hours); // �Ű�����(���� �ð�) hours�� ��� hours�� ����
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
// TODO: �Ʒ� nullptr ��� �����϶�. �ڽ��� ������ ���ο� ��ü�� �����͸� ��ȯ�϶�. 
    return nullptr;
}

/******************************************************************************
 * Class Employee
 ******************************************************************************/
class Employee : public Person{
    string company;  // �ٹ�ȸ��
    int payPerHour;  // �ð����ӱ�
    int overtime;    // �ʰ��ٹ��ð� ����
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
// ��� ����
    string university; // �л��� �ٴϴ� ���б� �̸�
    int year;          // �г�
    int tuition;       // �� �б�� ��ϱ� �׼�
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
 * menu_switch() �Լ�: ���õ� ���� �޴� �׸��� ������
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
//int  whatIsYourPay(Person *p)   { return (*p)(); } // return p->operator()();�� ����
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