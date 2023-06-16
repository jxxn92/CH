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
    if(choice == "Avante" || choice == "Sonata" || choice == "Grandeur"){
        return "car available";
    }
    else{
        return "car unavailable";
    }
}
//=============================================
class hyundai : public hyundai_kia{
public:
    string lineup() override;
    string find(string choice) override;
};

string hyundai::lineup(){
    return "Avante Sonata Grandeur";
}

string hyundai::find(string choice){
    if(choice == "Avante" || choice == "Sonata" || choice == "Grandeur"){
        return "car available";
    }
    else{
        return "car unavailable";
    }
}
//=============================================
class kia : public hyundai_kia{
public:
    string lineup() override;
    string find(string choice) override;
};

string kia::lineup(){
    return "Soul Niro Sportage Sorento Stinger";
}
string kia::find(string choice){
    if(choice == "Soul" || choice == "Niro" || choice == "Sportage" || choice == "Sorento" || choice == "Stinger"){
        return "car available";
    }
    else{
        return "car unavailable";
    }
}

//=============================================

class genesis : public hyundai_kia{
public:
    string lineup() override;
    string find(string choice) override;
};

string genesis::lineup(){
    return "g70 g80 g90 gv70 gv80";
}

string genesis::find(string choice){
    if(choice == "g70" || choice == "g80" || choice == "g90" || choice == "gv70" || choice == "gv80"){
        return "car available";
    }
    else{
        return "car unavailable";
    }
}

//============================================
//아래 main 함수는 수정 불가...
int main()
{
	//string test = "abc xyz"; //여기저기 힌트가 있다.
	//cout << test.find("abc") << " " << test.find("xyz") << " " <<  test.find("abcd") << endl;
	hyundai myhyundai;
	kia mykia;
	genesis mygenesis;
	cout << myhyundai.lineup() << endl; //"Avante Sonata Grandeur" 출력
	cout << mykia.lineup() << endl;     //"Soul Niro Sportage Sorento Stinger" 출력
	cout << mygenesis.lineup() << endl; //"g70 g80 g90 gv70 gv80" 출력
	cout << endl;

	string choice;
	hyundai_kia* ptr=0;
	cout << "hyundai kia or genesis? " << endl; //브랜드 choice에 따라서 동적 객체 생성 
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
		cout << ptr->lineup() << "?" << endl;//브랜드 choice에 따라서 생성된 클라스의 자동차 lineup
		cin >> choice; //차 choice
		cout << ptr->find(choice) << endl;
		//차 choice가 lineup에 있으면 "car available"출력, 없으면 "car unavailable" 출력
		//힌트: lineup() 반환 값을 string에 넣어서 사용할수 있다
	}

	delete ptr;
	return 0;
}