/* hyundai kia genesis���� �ϳ��� �����ϰ�, ������ �귣���� �� ���ξ����� ���� �����ϴ� �ڵ��.
hyundai, kia, genesis class�� ���� hyundai_kia class���� ��� �޾Ҵ�. 
����� ���ÿ� main �Լ��� ���� hyundai_kia class, hyundai class, kia class, genesis class�� �����϶�. */

//����� ���� 1
//(���)Avante Sonata Grandeur
//(���)Soul Niro Sportage Sorento Stinger
//(���)g70 g80 g90 gv70 gv80
//(���)
//(���)hyundai kia or genesis ?
//(�Է�)genesis
//(���)g70 g80 g90 gv70 gv80 ? 
//(�Է�)gv70
//(���)car available

//����� ���� 2
//(���)Avante Sonata Grandeur
//(���)Soul Niro Sportage Sorento Stinger
//(���)g70 g80 g90 gv70 gv80
//(���)
//(���)hyundai kia or genesis ?
//(�Է�)hyundai
//(���)Avante Sonata Grandeur ?
//(�Է�)Elantra
//(���)car unavailable

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class hyundai_kia{
public:
	virtual string lineup();
	virtual string find(string choice);
};

string hyundai_kia::lineup(){
	return "Avante Sonata Grandeur";
}

string hyundai_kia::find(string choice){
	if( choice == "Avante" || choice == "Sonata" || choice == "Grandeur"){
		return "car available";
	}
	else{
		return "car unavailable";
	}
}


class hyundai : public hyundai_kia{
public:
	string lineup() override;
	string find(string choice) override;
};

string hyundai::lineup(){
	return "Avante Sonata Grandeur";
}

string hyundai::find(string choice){
	if( choice == "Avante" || choice == "Sonata" || choice == "Grandeur"){
		return "car available";
	}
	else{
		return "car unavailable";
	}
}

class kia : public hyundai_kia{
public:
	string lineup() override;
	string find(string choice) override;

};

string kia::lineup(){
	return "Soul Niro Sportage Sorento Stinger";
}

string kia::find(string choice){
	if( choice == "Soul" || choice == "Niro" || choice == "Sportage" || choice == "Sorento" || choice == "Stinger"){
		return "car available";
	}
	else{
		return "car unavailable";
	}
}

class genesis:public hyundai_kia{
public:
	string lineup() override;
	string find(string choice) override;

};

string genesis::lineup(){
	return "g70 g80 g90 gv70 gv80";
}

string genesis::find(string choice){
	if( choice == "g70" || choice == "g80" || choice == "g90" || choice == "gv70" || choice == "gv80"){
		return "car available";
	}
	else{
		return "car unavailable";
	}
}

//�Ʒ� main �Լ��� ���� �Ұ�...
int main()
{
	//string test = "abc xyz"; //�������� ��Ʈ�� �ִ�.
	//cout << test.find("abc") << " " << test.find("xyz") << " " <<  test.find("abcd") << endl;
	hyundai myhyundai;
	kia mykia;
	genesis mygenesis;
	cout << myhyundai.lineup() << endl; //"Avante Sonata Grandeur" ���
	cout << mykia.lineup() << endl;     //"Soul Niro Sportage Sorento Stinger" ���
	cout << mygenesis.lineup() << endl; //"g70 g80 g90 gv70 gv80" ���
	cout << endl;

	string choice;
	hyundai_kia* ptr=0;
	cout << "hyundai kia or genesis? " << endl; //�귣�� choice�� ���� ���� ��ü ���� 
	cin >> choice;
	if ( choice == "hyundai") {
		ptr = new hyundai;
	}
	else if (choice == "kia") {
		ptr = new kia;
	}
	else if (choice == "genesis") {
		ptr = new genesis;
	}
	else {
		cout << "not found" << endl;
	}
	if (ptr != 0) {
		cout << ptr->lineup() << "?" << endl;//�귣�� choice�� ���� ������ Ŭ���� �ڵ��� lineup
		cin >> choice; //�� choice
		cout << ptr->find(choice) << endl;
		//�� choice�� lineup�� ������ "car available"���, ������ "car unavailable" ���
		//��Ʈ: lineup() ��ȯ ���� string�� �־ ����Ҽ� �ִ�
	}

	delete ptr;
	return 0;
}