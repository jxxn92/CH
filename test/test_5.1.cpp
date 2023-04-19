#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Student {
    int  id;
    char *name;
    char *address;
public:
    Student(int id, const char* name, const char* address);  // ������ 
    Student(Student& student);                               // ������� 
    void set_id(int id);                                     // ������� id �� ����
    void set_name(const char* name);                         // ������� name �� ����
    void set_address(const char* address);                   // ������� address �� ����
    void show();                                             // ������� id, name,address �� ���
    ~Student();                                              // �Ҹ���
};
// ���� �ڵ�� ���� �Ұ�

// �Ʒ�  �ڵ� �ۼ�
Student::Student(int id, const char* name, const char* address)
{
    this -> id = id;
    this -> name = name;
}


Student::Student(Student& student)
{
  // �ڵ� �ۼ�
}

Student::~Student(){
  // �ڵ� �ۼ�
}

void Student::set_id(int id)
{
  // �ڵ� �ۼ�
}


void Student::set_name(const char* name)
{
  // �ڵ� �ۼ�
}


void Student::set_address(const char* address)
{
  // �ڵ� �ۼ�
}


void Student::show()
{
  // �ڵ� �ۼ�
}

// main ���� �Ұ�
int main() {
    Student kim(20211221, "Kim", "Gwang-Ju,Dong-Gu");   // �л� ��ü ����
    Student park(20211411, "Park", "Gwang-Ju,Nam-Gu");  // �л� ��ü ����
    
    Student lee = park;                   // �л� ��ü ����
    
    int id;                               //  �л� ���� �Է� �κ�
    string name, address;
    cout <<  "Enter ID : ";
    cin >> id;
    cout <<  "Enter name : ";
    cin >> name;
    cout <<  "Enter address : ";
    cin >> address;
    
    lee.set_id(id);                         // �л� id ���� ����
    lee.set_name(name.c_str());             // �л� name ���� ����
    lee.set_address(address.c_str());       // �л� address ���� ����
    
    kim.show();                             // �л� ���� ���
    park.show();                            // �л� ���� ���
    lee.show();                             // �л� ���� ���
}

/* ���α׷� ������

(���)Enter ID : (�Է�)202111111
(���)Enter name : (�Է�)LeeCheolSu
(���)Enter address : (�Է�)Gwang-Ju,NamGu
(���)ID : 20211221, Name : Kim, Address : Gwang-Ju,Dong-Gu
(���)ID : 20211411, Name : Park, Address : Gwang-Ju,Nam-Gu
(���)ID : 202111111, Name : LeeCheolSu, Address : Gwang-Ju,NamGu
(���)Destructor ID : 202111111
(���)Destructor ID : 20211411
(���)Destructor ID : 20211221

*/
