/******************************************************************************

 �̹����� �� ��(10_1 ����)�� �ۼ��� Conatiner Ŭ������ Template Ŭ������ �ۼ��� ����.
 ���� Conatiner Ŭ������ ����(int) ���� ������ �� �־���.
 ���� ���� Conatiner Ŭ������ Template Ŭ������ �����Ͽ� ������, �Ǽ���, ���ڿ� �� 
 �پ��� ������ Ÿ���� ������ �� �ִ� ���ø� Ŭ������ �ǵ��� �϶�.

 ���α׷��� ��ü �������� �������� �Ʒ��� ����.

******************************************************************************/

// �뷮�� �����͸� ���������� �����ϰ� �ִ� ���ø� �����̳� Ŭ���� ����
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

template <typename T>
class Container {

    ���� int value�� �����ϴ� vector�� ��üȭ�� Ÿ�� int ��ſ� ���׸� Ÿ�� T�� �����϶�.  

    �� ��� �Լ��� �Ű����� value�� ������ Ÿ���� T�� �����϶�. ��, �Ű����� value�� ���� 
        �Լ��鸸 ã�Ƽ� �� ������ ����Ÿ Ÿ���� int ��ſ� ���׸� Ÿ�� T�� ���� �� �ָ� �ȴ�.

};


Container�� ��� ��� �Լ� �������� 
1. ��� �Լ� ���� �տ� template �� �߰��϶�.
2. �� �Լ� �̸� ���� Ŭ���� �̸��� ���׸� Ÿ�� T�� ���� �����϶�.
3. Container�� ��� �Լ��� �Ű����� value�� ������ Ÿ���� T�� �����϶�. 

Container�� remove(value)���� vector v�� iterator it ������ auto�� �����ϰ� 
v.begin()���� �ʱ�ȭ�ϰų� �Ǵ� typename vector::iterator it = v.begin()�� 
�ʱ�ȭ�Ѵ�.


// ������ 
void test_int(int size) {

    ù �����̾��� ������ Container c; ���
    �� ���ø� Ŭ������ Ȱ���Ͽ� int ������ ��üȭ�� Container Ŭ���� ��ü ���� c�� �Ʒ�ó�� �����϶�.
    Container c;
    
    �������� ������ ����
}

void test_string(int size) {

    �� ���ø� Ŭ������ Ȱ���Ͽ� string ������ ��üȭ�� Container Ŭ���� ��ü ���� c�� �����϶�.
    �� Ŭ������ ���ڿ��� ������ �� �ִ� container�̴�.

	int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size�� ��ŭ �ڵ����� ���Ҹ� �����Ѵ�.
	for (int i = 0; i < size; i++)
		c.push("abc"+to_string(min+i));
	cout << "push: ";
	c.print();

	string value;
	cout << boolalpha; // boolean ���� true, false�� ��µǰ� ��
	cout << "get(" << size/2 << "): " << c.get(size/2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	value = "abc" + to_string(max);
	cout << "find(\"" << value << "\"): " << c.find(value) << endl;
	value = "abc" + to_string(min-1);
	cout << "find(\"" << value << "\"): " << c.find(value) << endl << endl;

	value = "abc" + to_string(mid);
	cout << "remove(\"" << value << "\"): " << c.remove(value) << endl;
	c.print();

	value = "abc" + to_string(max+1);
	cout << "remove(\"" << value << "\"): " << c.remove(value) << endl;
	c.print();

	c.add("def");
	cout << "add(\"def\"): ";
	c.print();

}

int main()
{
	cout << "Enter the number of elements : " ;
	int size;
	cin >> size;
	cout << endl << "INTEGER Test" << endl << endl;
	test_int(size);
	cout << endl << "STRING Test" << endl << endl;
	test_string(size);
	return 0;
}

/******************************************************************************
  ���α׷� ���� ���
 ******************************************************************************
Enter the number of elements : 5

INTEGER Test

push: [0]105 [1]106 [2]107 [3]108 [4]109 

get(2): true : 107
get(5): false : 107
get(-1): false : 107

find(109): 4
find(104): -1

remove(107): true
[0]105 [1]106 [2]108 [3]109 

remove(110): false
[0]105 [1]106 [2]108 [3]109 

add(100): [0]205 [1]206 [2]208 [3]209 


STRING Test

push: [0]abc105 [1]abc106 [2]abc107 [3]abc108 [4]abc109 

get(2): true : abc107
get(5): false : abc107
get(-1): false : abc107

find("abc109"): 4
find("abc104"): -1

remove("abc107"): true
[0]abc105 [1]abc106 [2]abc108 [3]abc109 

remove("abc110"): false
[0]abc105 [1]abc106 [2]abc108 [3]abc109 

add("def"): [0]abc105def [1]abc106def [2]abc108def [3]abc109def 

******************************************************************************/