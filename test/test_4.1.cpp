#include <iostream>
#include <string>
using namespace std;

class hobbit {
public:
    string name;
    int age;

    hobbit();
    hobbit(string name,int age);
    ~hobbit();
    void set_age(int age);
    void set_name(string name);
    void print();
    hobbit* pointer();
};

hobbit::hobbit(){
    name = "Baggins";
    age = 100;
}
hobbit::hobbit(string name,int aage){
    this -> name = name;
    this -> age = age;
}
hobbit::~hobbit(){

}
void hobbit::set_age(int age){
    this -> age = age;
}
void hobbit::set_name(string name){
    this -> name = name;
}
void hobbit::print(){
    cout << name << " age " << age << endl;
}

hobbit* hobbit::pointer(){
    return this;
}

int main()
{
    string n;
    int a;
    cout << "Enter name" << endl;
    cin >> n;
    cout << "Enter age" << endl;
    cin >> a;

    hobbit frodo, bilbo;
    frodo.set_age(a);  //frodo�� age ���� 
    frodo.set_name(n); //frodo�� name ���� 
    frodo.print(); //��� ���� Ȯ��
    bilbo.print(); //��� ���� Ȯ�� 

    hobbit* ptr;
    ptr = frodo.pointer(); // frodo�� ������ ��ȯ(return)
    ptr -> set_age(a + 1); // ptr�� age ���� 
    ptr -> print();

    return 0;
}
