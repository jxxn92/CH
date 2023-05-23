#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Container {
private:
	vector<int> v;
public:
	void push(int value);	// value�� �����̳ʿ� ����
	void add(int inc);		// �����̳ʿ� ���Ե� ��� ���ҿ� inc�� ����
	bool get(int index, int &value);// �����̳��� index(�迭ó�� 0���� ����) ��ġ�� �ִ� ���� ���� ��ȯ
	int  find(int value);	// value ���� ���� ������ �ε����� ������
	bool remove(int value);	// value ���� ���� ���Ҹ� �����ϰ� true ����, �������� ������ false
	void print();			// �����̳ʿ� ���Ե� ��� ���Ҹ� ���������� ���
};

void Container::push(int value){
	v.push_back(value);
}

void Container::add(int inc) {
	for(int i = 0; i < v.size(); i++){
		v.at(i) += inc;
	}
}

bool Container::get(int index, int &value) {
	if(index < 0 || index >= v.size()){
		return false;
	}
	else{
		value = v.at(index);
		return true;
	}
	    // �����̳��� index�� ������ index�� ������ �ǹ̸� ������.
}

int Container::find(int value) {
	for(int i = 0 ; i < v.size(); i++){
		if(v.at(i) == value ){
			return i;
		}
	}
	return -1;
}

bool Container::remove(int value) {
    // ������ Ư�� ���Ҹ� �����ϱ� ���ؼ� iterator�� �̿��ؾ� �Ѵ�.
	vector<int>::iterator it;
	for(it = v.begin();it != v.end(); it++){
		if(*it == value){
			v.erase(it);
			return true;
		}
	}
	return false;
}

void Container::print() {
	for (int i = 0; i < (int)v.size(); i++)
		cout << "[" << i << "]" << v[i] << " ";
	cout << endl << endl;
}

void test_int(int size) {
	Container c;

	int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size�� ��ŭ �ڵ����� ���Ҹ� �����Ѵ�.
	for (int i = 0; i < size; i++)
		c.push(min+i);
	cout << "push: ";
	c.print();

	int value;
	cout << boolalpha; // boolean ���� true, false�� ��µǰ� ��
	cout << "get(" << size/2 << "): " << c.get(size/2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	cout << "find(" << max << "): " << c.find(max) << endl;
	cout << "find(" << min-1 << "): " << c.find(min-1) << endl << endl;

	cout << "remove(" << mid << "): " << c.remove(mid) << endl;
	c.print();

	cout << "remove(" << max+1 << "): " << c.remove(max+1) << endl;
	c.print();

	c.add(100);
	cout << "add(100): ";
	c.print();
}

int main()
{
	cout << "Enter the number of elements : " ;
	int size;
	cin >> size;
	cout << endl << "INTEGER Test" << endl << endl;
	test_int(size);
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
******************************************************************************/