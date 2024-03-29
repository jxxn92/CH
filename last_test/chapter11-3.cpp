#include <iostream>
#include <cstring>
using namespace std;

class Line {
	int length;
public:
	Line(int n=1) { length = n; }
	friend istream& operator >> (istream& stream, Line& op2);
	friend ostream& operator << (ostream& stream, Line op2);
};

istream& operator >> (istream& stream, Line& op2){
    stream >> op2.length >> op2.length;
}

ostream& operator << (ostream& stream, Line op2){
    if(op2.length == 3){
        stream << "***" << endl;
    }
    else if(op2.length == 2){
        stream << "**" << endl;
    }
    else{
        stream << "*" << endl;
    }
    return stream;
}

void getcall(){
    
}

// 여기에 필요한 함수들을 모두 구현하시오.

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

// 위의 코드는 수정 불가

/*********************************************************************
    C++ 입출력시스템에서 다음 main()함수에 필요한 코드를 완성하시오.
*********************************************************************/
/* (1) main() 함수가 잘 실행되도록 Line 객체를 위한 >>, << 연산자를 구현하라.

(2) main()에서 호출하는 getcall() 전역함수를 구현하라. 
    getcall()은 처음에 필요한 메시지를 출력한다.
    그리고 "문자열 입력은? " 문자열을 출력한 후 
    istream의 getline() 멤버함수를 이용하여 한 줄을 읽는다.
    만약 입력된 문자열이 "z" 이면 종료 메시지를 출력하고 함수에서 리턴하고, 
    "z"가 아니면 그냥 무시한다.
    위의 과정을 반복한다. */

/*********************************************************************
    아래는 프로그램의 실행 결과이다.
*********************************************************************/
/* (출력)길이는? 3
(출력)길이는? 2
(출력)***
(출력)**
(출력)*
(출력)
(출력)cin.getline()으로 읽기 종료 할려면, z를 입력하세요.
(출력)
(출력)문자열 입력은? (입력)apple
(출력)문자열 입력은? (입력)banana
(출력)문자열 입력은? (입력)z
(출력)프로그램을 종료합니다. */