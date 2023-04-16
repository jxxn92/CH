//  id, name���� ���� �л��� �����ϴ� ���α׷��� �ۼ�
//  student Ŭ��������  id, name�� �迭�� ������
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class student {   // �л� Ŭ����
	int  size;     // �л� Ŭ������ ���� �ִ� �л���
	int* id;       // �л��� �й��� ������ ����
	string* name;  // �л��� �̸��� ������ ����
public:
	student(int n);                                   // �л��� n�� �Է� �޾Ƽ� ������ ���� ����
	student(const student & std);                     // ���������
    ~student();                                       // �Ҹ���   delete [] id   delete [] name  ���
	void set_data(int idx, int id, string name);      // �Ű� ���� id�� name��  Ŭ������ ���� �ִ� �迭 id, name�� idx ��° �ε����� ���� ����
	void get_data(int idx, int& id, string& name);    // Ŭ������ ���� �ִ� �迭 id, name�� idx ��° ���� �Ű� ���� id�� name�� ���� ��ȯ
	void print_student();                             // Ŭ������ ���� �ִ� �迭 id, name �� ��� ���
    string& get_name(int idx);                        // Ŭ������ ���� �迭 name�� idx ��° ���� ��ȯ
};

//���� �ڵ�� ���� �Ұ�

student::student(int n){
    size = n;
    id = new int[n];
    name = new string[n];
}
student::~student(){
    delete [] id;
    delete [] name;
    cout << "delete [] id" << endl;
    cout << "delete [] name" << endl;
}
void student::set_data(int idx, int id, string name){
    this -> id[idx] = id;
    this -> name[idx] = name;
}
void student::get_data(int idx, int& id, string& name){

    id = this -> id[idx];
    name =  this -> name[idx];

}
void student::print_student(){
    for(int i = 0 ; i < size; i++){
        cout << "ID : " << id[i] << " Name : " << name[i] << endl;
    }

}
string& student::get_name(int idx){
    return name[idx];
}

student::student(const student& std){
    this -> size = std.size;
    this -> id = new int[size];
    this -> name = new string[size];

    for(int i = 0; i < std.size; i++){
		id[i] = std.id[i];
		name[i] = std.name[i];
	}
}
//�Ʒ� �ڵ�� ���� �Ұ�


int main()
{
	int nSize;

	cout << "������ �л� ���� �Է��� �ּ���." << endl;
	cin >> nSize;          // �л��� �Է�

	if (nSize<=0 ) {
		cout << "0���� ū ���ڸ� �Է����ּ���" << endl;
		return -1;
	}

	student stdA(nSize);
	int nID;
	string strName;

	cout << "�й� �̸��� �Է����ּ���." << endl;
	for (int i=0; i < nSize; i++ ) {
		cin >> nID >> strName;
		stdA.set_data(i, nID, strName);
	}

	cout << " �л� ���� ����Ʈ" << endl;
	stdA.print_student();


	student stdB(stdA);

	cout << " �л� ���� ����Ʈ" << endl;
	stdB.print_student();


	stdB.get_data(nSize-1, nID, strName);
	cout << nSize <<" ��° �л��� ID : " <<  nID << " �̸� : " << strName << endl;

	cout << nSize <<" ��° �л��� ������ �̸� �Է� " << endl;
	cin >> strName;
	stdB.get_name(nSize-1)  = strName;

	stdB.get_data(nSize-1, nID, strName);
	cout << nSize <<" ��° �л��� ID : " <<  nID << " �̸� : " << strName << endl;

}

//!(���)������ �л� ���� �Է��� �ּ���.
//!(�Է�)5
//!(���)�й� �̸��� �Է����ּ���.
//!(�Է�)1111 �̼���
//!(�Է�)3333 ������
//!(�Է�)2222 ��ö��
//!(�Է�)4444 ȫ�浿
//!(�Է�)5555 Ȳ����
//!(���) �л� ���� ����Ʈ
//!(���)ID : 1111 Name : �̼���
//!(���)ID : 3333 Name : ������
//!(���)ID : 2222 Name : ��ö��
//!(���)ID : 4444 Name : ȫ�浿
//!(���)ID : 5555 Name : Ȳ����
//!(���) �л� ���� ����Ʈ
//!(���)ID : 1111 Name : �̼���
//!(���)ID : 3333 Name : ������
//!(���)ID : 2222 Name : ��ö��
//!(���)ID : 4444 Name : ȫ�浿
//!(���)ID : 5555 Name : Ȳ����
//!(���)5 ��° �л��� ID : 5555 �̸� : Ȳ����
//!(���)5 ��° �л��� ������ �̸� �Է� 
//!(�Է�)���߳�
//!(���)5 ��° �л��� ID : 5555 �̸� : ���߳�
//!(���)delete [] id
//!(���)delete [] name
//!(���)delete [] id
//!(���)delete [] name