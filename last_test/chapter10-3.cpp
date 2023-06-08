/*************************************************************************
 * 아래 MyStack 클래스는 정수형 데이터를 push(), pop()할 수 있는 스택이다.
 *************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class MyStack {
    vector<T> v;
public:
    void push(T e);
    bool pop(T &e);
};
template <typename T>
void MyStack<T>::push(T e)    {
    v.push_back(e);
}

template <typename T>
bool MyStack<T>::pop(T &e) {
    if (v.size() == 0)
        return false;        // 스택이 비었을 경우
    int last = v.size() - 1; // 벡터의 마지막 원소에 대한 인덱스
    e = v[last];             // 마지막 원소 저장
    v.resize(last);          // 벡터의 크기를 last로 줄임 (마지가 원소 삭제)
    return true;             // pop한 원소가 있을 경우 true
}

/*********************************************************************
 * 임의의 데이터 타입의 데이터를 push() pop()할 수 있도록 
 * 위 클래스를 템플릿 클래스로 수정하라.
 * 수정 시 아래 main() 함수와 프로그램의 실행 결과를 참조하라. 
 *********************************************************************/


/*********************************************************************
 * 아래 main() 함수는 수정된 template MyStack을 활용하는 함수이며, 
 * 정수형 스택과 문자열 스택을 운영하는 것을 보여 준다.
 * 아래 코드는 절대 수정하지 마시오. 
 *********************************************************************/

int main() 
{
    // [정수형] 스택을 선언하고 5개의 정수를 입력 받아 
    // 스택에 push한 후 이들 모두를 pop하여 화면에 출력한다. 
    MyStack< int > is;                 // 정수형 스택을 선언
    int ie;
    cout << "5개의 [정수]를 연속으로 입력하시오.: ";
    for (int i = 0; i < 5; ++i) {    // 5개의 정수를 입력 받아 스택에 push
        cin >> ie;
        is.push(ie);
    }
    cout << "int pop: ";
    while ( is.pop(ie) )             // 스택의 모든 원소를 pop하여 화면에 출력한다.
        cout << ie << " ";
    cout << endl;

    // [문자열] 스택을 선언하고 5개의 문자열를 입력 받아 
    // 스택에 push한 후 이들 모두를 pop하여 화면에 출력한다. 
    MyStack< string > ss;              // 문자열 스택을 선언
    string se;
    cout << "5개의 [문자열]을 연속으로 입력하시오.: ";
    for (int i = 0; i < 5; ++i) {    // 5개의 문자열를 입력 받아 스택에 push
        cin >> se;
        ss.push(se);
    }
    cout << "string pop: ";
    while ( ss.pop(se) )             // 스택의 모든 원소를 pop하여 화면에 출력한다.
        cout << se << " ";
    cout << endl;
}


/*********************************************************************
 * 프로그램 실행 결과
 *********************************************************************/
/* (출력)5개의 [정수]를 연속으로 입력하시오.: (입력)1 22 333 4444 55555
(출력)int pop: 55555 4444 333 22 1
(출력)5개의 [문자열]을 연속으로 입력하시오.: (입력)s ss sss ssss sssss
(출력)string pop: sssss ssss sss ss s */