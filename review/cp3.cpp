//todo   아래에 class alu를 작성해서 
//todo   main 함수에서 +, -, * 계산이 가능하게 하라
//todo   멤버 변수인 r1, r2는 unsigned int, oper은 char이다
//todo   ------------------------------------------------

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//여기에 클래스 코드 작성할 것 
class alu{
public:
    int r1;
    int r2;
    char oper;
    alu();
    //~alu();
    unsigned int calc(); 
};

alu::alu(){
    r1 = 1;
    r2 = 3;
    oper = '*';
}
unsigned int alu::calc(){
    switch (oper)
    {
    case '+':
        return r1 + r2;
        break;
    case '-':
        return r1 - r2;
        break;
    case '*':
        return r1 * r2;
        break;
    case '/':
        return r1 / r2;
        break;
    }
}
//아래 main 함수는 수정 불가

int main() {
    alu machine; //생성자 구현하여 아래 출력 결과 1*3처럼 출력되게 각 멤버를 초기화 시킬 것
    cout << machine.r1 << machine.oper << machine.r2 << endl; // 출력 결과:1*3
    cin  >> machine.r1 >> machine.oper >> machine.r2;         // 입력 예시:7 + 7
    cout << machine.calc() << endl;                           // 출력 예시:14
    cin  >> machine.r1 >> machine.oper >> machine.r2;         // 입력 예시:25 - 8
    cout << machine.calc() << endl;                           // 출력 예시:17
    cin  >> machine.r1 >> machine.oper >> machine.r2;         // 입력 예시:9 * 25
    cout << machine.calc() << endl;                           // 출력 예시:225
}