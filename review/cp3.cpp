//todo   �Ʒ��� class alu�� �ۼ��ؼ� 
//todo   main �Լ����� +, -, * ����� �����ϰ� �϶�
//todo   ��� ������ r1, r2�� unsigned int, oper�� char�̴�
//todo   ------------------------------------------------

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//���⿡ Ŭ���� �ڵ� �ۼ��� �� 
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
//�Ʒ� main �Լ��� ���� �Ұ�

int main() {
    alu machine; //������ �����Ͽ� �Ʒ� ��� ��� 1*3ó�� ��µǰ� �� ����� �ʱ�ȭ ��ų ��
    cout << machine.r1 << machine.oper << machine.r2 << endl; // ��� ���:1*3
    cin  >> machine.r1 >> machine.oper >> machine.r2;         // �Է� ����:7 + 7
    cout << machine.calc() << endl;                           // ��� ����:14
    cin  >> machine.r1 >> machine.oper >> machine.r2;         // �Է� ����:25 - 8
    cout << machine.calc() << endl;                           // ��� ����:17
    cin  >> machine.r1 >> machine.oper >> machine.r2;         // �Է� ����:9 * 25
    cout << machine.calc() << endl;                           // ��� ����:225
}