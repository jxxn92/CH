/******************************************************************************

 이번 프로젝트는 정수형 벡터 클래스 vector를 이용하여 대량의 정수형 값을 저장하고 있다가
 검색, 삭제, 추가 등의 기능을 수행하는 Conatiner 클래스를 작성하는 것이다.

 프로그램의 전체 구성도와 실행결과는 아래와 같다.

******************************************************************************/

// 대량의 데이터를 순서적으로 저장하고 있는 컨테이너 클래스
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Container {
private:
	vector<int> v;
public:
	void push(int value);	// value를 컨테이너에 삽입
	void add(int inc);		// 컨테이너에 삽입된 모든 원소에 inc를 더함
	bool get(int index, int &value);// 컨테이너의 index(배열처럼 0부터 시작) 위치에 있는 원소 값을 반환
	int  find(int value);	// value 값을 가진 원소의 인덱스를 리턴함
	bool remove(int value);	// value 값을 가진 원소를 삭제하고 true 리턴, 존재하지 않으면 false
	void print();			// 컨테이너에 삽입된 모든 원소를 순서적으로 출력
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
	if(index < 0 || index == v.size()){
		return false;
	}
	else{
		value = v.at(index);
		return true;
	}
	    // 컨테이너의 index는 벡터의 index와 동일한 의미를 가진다.
}

int Container::find(int value) {
	for(int i = 0 ; i < v.size(); i++){
		if(v.at(i) == value ){
			return i;
		}
		else{
			return -1;
		}
	}
}

bool Container::remove(int value) {
    // 벡터의 특정 원소를 삭제하기 위해선 iterator을 이용해야 한다.
	vector<int>::iterator it;
    따라서 vector v의 iterator it 변수를 선언하고 
    for 문을 이용하여 loop 돌면서 각각의 it에 대해
        *it와 value가 같은 값인 it를 찾아서 
            v.erase(it)를 호출하여 해당 원소를 삭제하고,
            바로 true 리턴
    동일한 값을 하나도 찾지 못할 경우 false 반환 
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

	// size개 만큼 자동으로 원소를 삽입한다.
	for (int i = 0; i < size; i++)
		c.push(min+i);
	cout << "push: ";
	c.print();

	int value;
	cout << boolalpha; // boolean 값이 true, false로 출력되게 함
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
    프로그램 실행 결과
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