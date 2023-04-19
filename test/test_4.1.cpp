#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class hobbit{
public:
    string name;
    int age;
    //여기에 코드 작성 
    hobbit();
    ~hobbit();
    void set_name();
    void set_age();
    void print();
    hobbit* pointer(){return this;}
};

//여기에 함수 작성...

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
    set_age(&frodo, a);  //frodo의 age 변경 
    set_name(&frodo, n); //frodo의 name 변경 
    print(frodo); //출력 내용 확인
    print(bilbo); //출력 내용 확인 
    
    hobbit* ptr;
    ptr = frodo.pointer(); // frodo의 포인터 반환(return)
    set_age(ptr, a + 1); // ptr의 age 변경 
    print(*ptr); //출력 내용 확인
    
    return 0;
}
