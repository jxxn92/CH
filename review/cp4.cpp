// 사람들의 first last 이름을 입력하는 코드를 작성하라.
// 아래 코드와 주석을 이해하고 필요한 내용을 코딩함.

/*-----------------------------------------------------
 *  아래 main 함수 실행시 출력, 입력 예시: 아래 (입력)(출력)은 무시할 것
 *-----------------------------------------------------*/
//TODO (출력)Enter number of people.
//TODO (입력)3
//TODO (출력)Enter 3 first and last names.
//TODO (입력)Mike Tyson
//TODO (입력)Tyson Fury
//TODO (입력)Ernie Shaver
//TODO (출력)Mike Tyson
//TODO (출력)Tyson Fury
//TODO (출력)Ernie Shaver
//TODO (출력)Enter search name.
//TODO (입력)Tyson
//TODO (출력)2
//TODO (출력)delete [] p;

/*-----------------------------------------------------
 *  프로그램 소스 코드
 *-----------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

class Name{
    string first, last;
public:
    string get_first() { return first; }
    string get_last()  { return last; }
    void set_name(string f, string l);  // 멤버 first와 last에 각각 f와 l을 저장
};

class PersonManager{
    Name *p;
    int nofp; //Name의 수, p의 크기
public:
    PersonManager(int n);    // 생성자에서 n개의 원소를 가지는 Name 배열을 동적 메모리 할당 받은 후 p에 저장 후
                             // n개의 Name(first last)을 입력 받아 p 배열의 각 원소에 저장
    void show();             // 모든 n개의 이름의 first name과 last name을 출력 
    int serarch(string str); // str과 같은 first 또는 last 이름의 수를 반환
    ~PersonManager();        // 메모리 반환 및 "delete [] p;" 출력
};
// 위에 코드는 수정 불가

// 여기에 코드 작성

// 아래 main 함수는 수정 불가
int main() {
    int n;
    cout << "Enter number of people." << endl;
    cin >> n;

    PersonManager people(n);

    people.show();

    cout << "Enter search name." << endl;
    string str;
    cin >> str;
    cout << people.serarch(str) << endl;

    return 0;
}