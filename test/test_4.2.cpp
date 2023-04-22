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

    //아래에 s크기의 동적 메모리 할당 코드 작성....
    ptr = new complex[s];
    //위에 s크기의 동적 메모리 할당 코드 작성....

    for (int i = 0; i < s; i++){
        ptr[i].a = i+s; // ptr[0].a = 3 , ptr[1].a = 4 , ptr[i].a = 5
        ptr[i].i = 7;
        cout << ptr[i].i << " " ;
    }
    cout << endl;
    complex a(s, s + 10);
    a.print(); // 출력 확인

    //아래에 ptr의 모든 요소 print
    for(int i=0;i < s; i++){
        ptr[i].print();
    }
    //위에 ptr의 모든 요소 print

    //아래에 메모리 반환 코드 작성
    delete [] ptr;
    //위에 메모리 반환 코드 작성

    return 0;
}
