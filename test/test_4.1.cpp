#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class hobbit{
public:
    string name;
    int age;
    //���⿡ �ڵ� �ۼ� 
    hobbit();
    ~hobbit();
    void set_name();
    void set_age();
    void print();
    hobbit* pointer(){return this;}
};

//���⿡ �Լ� �ۼ�...

hobbit::hobbit(){
}

hobbit::~hobbit(){
}
void hobbit::set_name(){
}
void hobbit::set_age(){
}

void hobbit::print(){
    cout << name << " age " << age << endl; 
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
    set_age(&frodo, a);  //frodo�� age ���� 
    set_name(&frodo, n); //frodo�� name ���� 
    print(frodo); //��� ���� Ȯ��
    print(bilbo); //��� ���� Ȯ�� 
    
    hobbit* ptr;
    ptr = frodo.pointer(); // frodo�� ������ ��ȯ(return)
    set_age(ptr, a + 1); // ptr�� age ���� 
    print(*ptr); //��� ���� Ȯ��
    
    return 0;
}
