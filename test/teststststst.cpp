#include <iostream>
#include <string>
using namespace std;

class hobbit {
public:
    string name;
    int age;

    hobbit* pointer(){return this;}
};

//���⿡ �Լ� �ۼ�...
int main()
{
    string n;
    int a;
    cout << "Enter name" << endl;
    cin >> n;
    cout << "Enter age" << endl;
    cin >> a;
    hobbit frodo, bilbo;
    set_age(&frodo, a);  //frodo�� age ���� 
    set_name(&frodo, n); //frodo�� name ���� 
    print(frodo); //��� ���� Ȯ��
    print(bilbo); //��� ���� Ȯ�� 
    hobbit* ptr;
    ptr = frodo.pointer(); // frodo�� ������ ��ȯ(return)
    set_age(ptr, a + 1); // ptr�� age ���� 
    print(*ptr); //��� ���� Ȯ��
    return 0;
}
