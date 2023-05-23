#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

template <typename T>
class Container {
private:
	vector<T> v;
public:
	void push(T value);	// value�� �����̳ʿ� ����
	void add(T inc);		// �����̳ʿ� ���Ե� ��� ���ҿ� inc�� ����
	bool get(int index, T &value);// �����̳��� index(�迭ó�� 0���� ����) ��ġ�� �ִ� ���� ���� ��ȯ
	T  find(T value);	// value ���� ���� ������ �ε����� ������
	bool remove(T value);	// value ���� ���� ���Ҹ� �����ϰ� true ����, �������� ������ false
	void print();			// �����̳ʿ� ���Ե� ��� ���Ҹ� ���������� ���
};

template <typename T>
void Container<T>::push(T value){
	v.push_back(value);
}

template <typename T>
void Container<T>::add(T inc) {
	for(int i = 0; i < v.size(); i++){
		v.at(i) += inc;
	}
}

template <typename T>
bool Container<T>::get(int index, T &value) {
	if(index < 0 || index >= v.size()){
		return false;
	}
	else{
		value = v.at(index);
		return true;
	}
	    // �����̳��� index�� ������ index�� ������ �ǹ̸� ������.
}
template <typename T>
T Container<T>::find(T value) {
	for(int i = 0 ; i < v.size(); i++){
		if(v.at(i) == value ){
			return i;
		}
	}
	return -1;
}
template <typename T>
bool Container<T>::remove(T value) {
    // ������ Ư�� ���Ҹ� �����ϱ� ���ؼ� iterator�� �̿��ؾ� �Ѵ�.
    auto it = v.begin();
	for(;it != v.end(); it++){
		if(*it == value){
			v.erase(it);
			return true;
		}
	}
	return false;
}

template <typename T>
void Container<T>::print() {
	for (int i = 0; i < (int)v.size(); i++)
		cout << "[" << i << "]" << v[i] << " ";
	cout << endl << endl;
}


// ������ 
void test_int(int size) {
	Container<int> c;

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

void test_string(int size) {
    
	Container<string> c;

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