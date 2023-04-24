#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Student {
    int  id;
    char *name;
    char *address;
public  :
    Student(int id, const char* name, const char* address);  // 생성자 
    Student(Student& student);                               // 복사상성자 
    void set_id(int id);                                     // 멤버변수 id 값 변경
    void set_name(const char* name);                         // 멤버변수 name 값 변경
    void set_address(const char* address);                   // 멤버변수 address 값 변경
    void show();                                             // 멤버변수 id, name,address 값 출력
    ~Student();                                              // 소멸자
};
// 위에 코드는 수정 불가

// 아래  코드 작성
Student::Student(int id, const char* name, const char* address)
{
    this -> id = id;
    this -> name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this -> address = new char[strlen(address)+1];
    strcpy(this->address,address);

}


Student::Student(Student& student)
{
    this -> id = student.id;
    this -> name = new char[strlen(student.name)+1];
    strcpy(this->name,student.name);
    this -> address = new char[strlen(student.address)+1];
    strcpy(this->address,student.address);
}

Student::~Student(){
    cout << "Destructor ID : " << id << endl;
    delete [] name;
    delete [] address;
}

void Student::set_id(int id)
{
    this -> id = id;
}


void Student::set_name(const char* name)
{
    strcpy(this->name,name);
}


void Student::set_address(const char* address)
{
    strcpy(this->address,address);
}


void Student::show()
{
    cout << "ID : " << id << ", Name : " << name << ", Address : " << address << endl;
}

// main 수정 불가
int main() {
    Student kim(20211221, "Kim", "Gwang-Ju,Dong-Gu");   // 학생 객체 생성
    Student park(20211411, "Park", "Gwang-Ju,Nam-Gu");  // 학생 객체 생성
    
    Student lee = park;                   // 학생 객체 생성
    
    int id;                               //  학생 정보 입력 부분
    string name, address;
    cout <<  "Enter ID : ";
    cin >> id;
    cout <<  "Enter name : ";
    cin >> name;
    cout <<  "Enter address : ";
    cin >> address;
    
    lee.set_id(id);                         // 학생 id 정보 변경
    lee.set_name(name.c_str());             // 학생 name 정보 변경
    lee.set_address(address.c_str());       // 학생 address 정보 변경
    
    kim.show();                             // 학생 정보 출력
    park.show();                            // 학생 정보 출력
    lee.show();                             // 학생 정보 출력
}

/* 프로그램 실행결과

(출력)Enter ID : (입력)202111111
(출력)Enter name : (입력)LeeCheolSu
(출력)Enter address : (입력)Gwang-Ju,NamGu
(출력)ID : 20211221, Name : Kim, Address : Gwang-Ju,Dong-Gu
(출력)ID : 20211411, Name : Park, Address : Gwang-Ju,Nam-Gu
(출력)ID : 202111111, Name : LeeCheolSu, Address : Gwang-Ju,NamGu
(출력)Destructor ID : 202111111
(출력)Destructor ID : 20211411
(출력)Destructor ID : 20211221

*/

