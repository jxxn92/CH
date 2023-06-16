#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Line {
	int length;
public:
	Line(int n=1) { length = n; }
	friend istream& operator >> (istream& stream, Line& op2);
	friend ostream& operator << (ostream& stream, Line op2);
};

// 여기에 필요한 함수들을 모두 구현하시오.
istream& operator >> (istream& stream, Line& op2){
    cout << "길이는? ";
    stream >> op2.length;
}

ostream& operator << (ostream& stream, Line op2){
    for(int i = 0 ; i < op2.length; i++){
        stream << '*';
    }
    stream << "\n";
}

void getcall(){

    string str;
    cout << "cin.getline()으로 읽기 종료 할려면, z를 입력하세요."<< endl << endl;
    cout << "문자열 입력은? ";
    getline(cin,str);
    while(str != "z"){
        cout << "문자열 입력은? ";
        getline(cin,str);
    }
    cout << "프로그램을 종료합니다.";

}

int main() {
        //(1)
	Line a, b(10),c(1);
	cin >> a >> b;
	cout << a;
	cout << b;
	cout << c;

    cout << endl;
	cin.ignore(2, '\n'); // 입력 버퍼에 남아 있는 '\r'나 '\n' 문자들 제거

    //(2) 
	getcall();
}
