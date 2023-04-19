#include <iostream>
#include <string>
using namespace std;

//여기에 class 정의
class complex{
public:
    int size;
    int *a;
    complex();
    complex(int size, int newsize);
    ~complex();
    void print();
};

int main()
{
    int s;
    cout << "Enter size" << endl;
    cin >> s;
    complex* ptr;

    //아래에 s크기의 동적 메모리 할당 코드 작성....
    int *ptr = new int[s];
    //위에 s크기의 동적 메모리 할당 코드 작성....

    for (int i = 0; i < s; i++) {
        ptr[i].a = i+s;
        cout << ptr[i].i << " ";
    }
    cout << endl;
    complex a(s, s + 10);
    a.print(); // 출력 확인

    //아래에 ptr의 모든 요소 print
   ...
    //위에 ptr의 모든 요소 print

    //아래에 메모리 반환 코드 작성
  ...
    //위에 메모리 반환 코드 작성

    return 0;
}
