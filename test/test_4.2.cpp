#include <iostream>
#include <string>
using namespace std;

//���⿡ class ����
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

    //�Ʒ��� sũ���� ���� �޸� �Ҵ� �ڵ� �ۼ�....
    int *ptr = new int[s];
    //���� sũ���� ���� �޸� �Ҵ� �ڵ� �ۼ�....

    for (int i = 0; i < s; i++) {
        ptr[i].a = i+s;
        cout << ptr[i].i << " ";
    }
    cout << endl;
    complex a(s, s + 10);
    a.print(); // ��� Ȯ��

    //�Ʒ��� ptr�� ��� ��� print
   ...
    //���� ptr�� ��� ��� print

    //�Ʒ��� �޸� ��ȯ �ڵ� �ۼ�
  ...
    //���� �޸� ��ȯ �ڵ� �ۼ�

    return 0;
}
