#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/******************************************************************************
 * Person class
 ******************************************************************************/
class Person {
// TODO: ��� ����: ��ӹ��� �ڽ� Ŭ�������� ������ �� �ֵ��� ������ ���� �����ڸ� �����϶�. 
    string *name;  // ��� �̸�
    int id;        // ������ ID ��ȣ
    int hours;     // ���� �ð�

// TODO: ��� �Լ�: �ܺο��� ������ �� �־�� �Ѵ�.
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
// TODO: ��°���� ���� ������ ���ڿ��� ����϶�.
}

Person* Person::clone() const {
// TODO: �Ʒ� nullptr ��� �����϶�. �ڽ��� ������ ���ο� ��ü�� �����͸� ��ȯ�϶�. 
    return nullptr;
}

/******************************************************************************
 * Class Employee
 ******************************************************************************/
Person Ŭ������ ��ӹ��� Employee Ŭ���� ����

// ��� ����
    string company;  // �ٹ�ȸ��
    int payPerHour;  // �ð����ӱ�
    int overtime;    // �ʰ��ٹ��ð� ����

public:
    Employee(const string& name, int id, int hours,
             const string& company, int payPerHour, int overtime);
    ~Employee() { cout << "~Employee(): n:" << *name << "   "; }

/******************************************************************************
 * Class Student
 ******************************************************************************/
Person Ŭ������ ��ӹ��� Student Ŭ���� ����

// ��� ����
    string university; // �л��� �ٴϴ� ���б� �̸�
    int year;          // �г�
    int tuition;       // �� �б�� ��ϱ� �׼�

public:
    Student(const string& name, int id, int hours,
            const string& university, int year, int tuition);
    ~Student() { cout << "~Student() : n:" << *name << "   "; }

/******************************************************************************
 * menu_switch() �Լ�: ���õ� ���� �޴� �׸��� ������
 ******************************************************************************/
string menuStr =
    "------------------ Inheritance ----------------\n"
    "  0.exit 1.print 2.addHours 3.whatAreYouDoing  \n"
    "  4.whatIsYourPay 5.copyPerson 6.deletePerson  \n"
    "-----------------------------------------------\n"
    "menu item? ";

//void printPerson(Person *p)     { p->println(); }
//void addHours(Person *p)        { *p += 10; }
//void whatAreYouDoing(Person *p) { p->whatAreYouDoing(); }
//int  whatIsYourPay(Person *p)   { return (*p)(); } // return p->operator()();�� ����
//Person* copyPerson(Person *p)   { return p->clone(); }
//void deletePerson(Person *p)    { delete p; }

void menu_switch(int menu)
{
    Employee *e = new Employee("e", 10001, 50, "Samsung", 30000, 10);
    Student  *s = new Student ("s", 10002, 10, "Chosun",  4, 4000000);
    Person   *p;

    switch (menu) {
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
