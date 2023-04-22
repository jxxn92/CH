#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class complex{
public:
    int a;
    int i;

    complex();
    complex(int a,int b);
    ~complex();
    void print();
};

complex::complex(){
    
}

complex::complex(int _a,int _i){
    a = _a;
    i = _i;

}

complex::~complex(){

}

void complex::print(){
    cout << "complex " << a << " " << i << endl;
}



int main()
{
    int s;
    cout << "Enter size" << endl;
    cin >> s;
    complex* ptr;

    //�Ʒ��� sũ���� ���� �޸� �Ҵ� �ڵ� �ۼ�....
    ptr = new complex[s];
    //���� sũ���� ���� �޸� �Ҵ� �ڵ� �ۼ�....

    for (int i = 0; i < s; i++){
        ptr[i].a = i+s; // ptr[0].a = 3 , ptr[1].a = 4 , ptr[i].a = 5
        ptr[i].i = 7;
        cout << ptr[i].i << " " ;
    }
    cout << endl;
    complex a(s, s + 10);
    a.print(); // ��� Ȯ��

    //�Ʒ��� ptr�� ��� ��� print
    for(int i=0;i < s; i++){
        ptr[i].print();
    }
    //���� ptr�� ��� ��� print

    //�Ʒ��� �޸� ��ȯ �ڵ� �ۼ�
    delete [] ptr;
    //���� �޸� ��ȯ �ڵ� �ۼ�

    return 0;
}
