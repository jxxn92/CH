/* 수정: 2023.4.3 15:40 
    [프로그램 실행 결과]에서 한글 출력 제거
    [프로그램 실행 결과]에서 "~MyStack()" 의 마지막 () 추가
 */
//===============================================
// string 데이터를 처리할 수 있는 스택 코드를 작성하라.
// 아래 코드와 주석을 이해하고 필요한 내용을 코딩하라.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class MyStack {
private:
	string *element; // 스택의 메모리로 사용할 포인터
	int size;           // 스택의 최대 크기
	int tos;            // 스택의 top을 가리키는 인덱스
public:
	MyStack(int size);    // 생성자 스택의 최대 크기를 입력 받아서 element 객체 배열을 생성해줌.
	MyStack(const MyStack& s);  // 깊은 복사 생성자
	~MyStack();           // 소멸자

	bool push(string item); // item을 스택에 삽입
			// 스택이 가득 차 있으면 false를, 아니면 true 리턴
	bool pop(string &item); // 스택의 탑에 있는 값을 item에 반환  그리고 top에 있는 자료 삭제
	bool peek(string &item); // 스택의 탑에 있는 값을 item에 반환
	void print_stack();  // 스택 내용 출력

};

// 위에 코드는 수정 불가

// 여기에 MyStack의 모든 멤버 함수들을 작성하라.
MyStack::MyStack(int size){
	this -> size = size;
	this -> tos = 0;
	cout << "MyStack(" << size << ")" << endl;
	element = new string[size];

}
MyStack::MyStack(const MyStack& s){
	this -> size = s.size;
	this -> tos = s.tos;
	this -> element = new string[size];
}
MyStack::~MyStack(){
	delete [] element;
}
bool MyStack::push(string item){
	if(tos >= size){
		return false;
		}
	else{
		element[tos] = item;
		tos++;
		return true;
	}
}
bool MyStack::pop(string &item){

}
bool MyStack::peek(string &item){

}
void MyStack::print_stack(){

}
// 아래 코드는 수정 불가

int main() {

	int stack_size;

	// 스택이 저장할수 있는 최대 크기를 입력 받는다
	cout << "Enter stack size : ";
	cin >> stack_size;

	// 스택을 생성해 줌
	MyStack first_stack(stack_size);

	// 입력할 데이터의 수를 입력 받는다
	// 데이터를 숫자 만큼 입력 받고 stack에 푸시한다.
	int  input_size;
	string  item;
	cout << "Enter number of input string : " ;
	cin >> input_size;
	for (int i=0; i < input_size; i++ ) {
		cout <<"Enter string : " ;
		cin >> item;
		first_stack.push(item);
	}

	// 스택의 자료를 출력
	cout << "first stack : " ;
	first_stack.print_stack();

	// 스택을 생성해 줌
	MyStack second_stack(first_stack);

	// 스택의 자료를 출력

	cout << "second stack : " ;
	second_stack.print_stack();

	first_stack.pop(item);
	cout << "first stack pop: " << item << endl ;
	second_stack.peek(item);
	cout << "second stack peek: " << item << endl ;

	// 스택의 자료를 출력
	cout << "first stack : " ;
	first_stack.print_stack();

	cout << "second stack : " ;
	second_stack.print_stack();

	cout << "second stack all pop: " << endl;
	while (second_stack.pop(item))
		cout << item << endl;

	return 0;
}

/***************** 
 * 프로그램 실행 결과
 *****************/
/* Enter stack size : 5
MyStack(5)
Enter number of input string : 7
Enter string : kim
Enter string : yang
Enter string : park
Enter string : shin
Enter string : chung
Enter string : jung
stack is full
Enter string : lee
stack is full
first stack : kim yang park shin chung 
MyStack(MyStack& s): tos+1 = 5
second stack : kim yang park shin chung 
first stack pop: chung
second stack peek: chung
first stack : kim yang park shin 
second stack : kim yang park shin chung 
second stack all pop: 
chung
shin
park
yang
kim
stack is empty
~MyStack(): tos+1 = 0
~MyStack(): tos+1 = 4 */