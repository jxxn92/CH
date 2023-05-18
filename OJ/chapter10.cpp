/******************************************************************/
// 이번 실습은 10장에 대한 라이브 코딩 연습이다.
// 아래 문제는 템플릿 클래스 구현, vector, map, algorithm, lambda를 사용할 수 있는 능력을 확인함.

// 먼저 아래 코드([문제 0] 앞까지)를 마킹하여 복사한 후 소스 파일에 삽입하라.
/******************************************************************/

#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * Class Rand
 ******************************************************************************/
// 난수를 발생하는 클래스임. 이해하려 하지말고 건너 뛰기 바람.

#include <random>

int seed = 0;

class Rand {
    // 난수를 생성하는 엔진
    default_random_engine re;
    // 발생된 난수 값들이 일정 범위의 균등 분포(unfiform)로 매핑
    uniform_int_distribution< int > dist;
public:
    // [low, high] 범위 내의 값이 발생하도록 dist 초기화
    Rand(int low, int high): dist(low, high) { }
    
    // [low, high] 범위 내의 난수 발생하는 함수
    int operator() () { return dist(re); }
    
    void setSeed() {
        cout << "seed for random number? ";
        cin >> seed;
        re.seed(seed);
    }
};

// [10, 29] 범위의 난수 발생기
Rand rnd(10, 29);

/******************************************************************************
 * template class
 ******************************************************************************/
template <typename T>
class Store {
    T value;
public:
    Store(const T& v={}) { value = v; }
    T get()              { return value; }
    void set(const T& v) { value = v; }
    T add(const T& v)  { value += v; return value;}
};

void templateClass() {
    Store<int> is;
    int i = is.get();
    cout << "is.get()   : " << i << endl;
    is.set(3);
    cout << "is.set(3)" << endl;
    i = is.add(4);
    cout << "is.add(4)  : " << i << endl;

    Store<string> ss("S1");
    string s = ss.get();
    cout << "ss.get()   : " << s << endl;
    ss.set("S3");
    cout << "ss.set(S3)" << endl;
    s = ss.add("S4");
    cout << "ss.add(S4) : " << s << endl;
}

/******************************************************************************
 * 컨테이너 클래스 map and vector, algorithm, lambda
 ******************************************************************************/
#include <map>
#include <vector>
#include <algorithm>

vector<int> iv;
map<int, string> mp;


// map의 모든 원소의 (키, 값) 쌍을 출력한다.
void printMap(string msg = {}) {
	if (!msg.empty())
        cout << msg << endl;
    cout << "map: ";
    for (auto p: mp)
        cout << "(" << p.first << "," << p.second << ") ";
        // p는 struct pair { int first; string second; } 형의 구조체 변수이며
        // p는 mp에 저장된 각 원소를 의미하며 p.first가 키, p.second가 value 값임
    cout << endl;
}

void printVector(string msg = {}) {
	if (!msg.empty()){
        cout << msg << endl;
    }
    cout << "vector: ";
    for(int i = 0; i < iv.size(); i++){
        cout << iv[i] << " " ;
    }

    cout << endl;
}

void vectorAppend() {
	rnd.setSeed(); // 지시가 있을 때까지 주석을 해제하지 마시오. 
    if (!iv.empty()) iv.clear(); // iv에 기존 원소가 있으면 모두 제거함

    for(int i = 0 ; i < 10 ; i++){
        iv.push_back(rnd());
    }
    // 난수 생성방법: rnd() 함수를 호출한 후 그 리턴 값을 벡터에 추가하면 됨 
    //            rnd()는 [10, 29] 범위의 난수 값을 발생시킴
}

// 벡터에 10개의 값을 삽입한 후 벡터 내용을 출력한다.
void vectorDisplay() {
    vectorAppend();
    printVector();
}

void vectorSort() {
    vectorAppend();
    printVector("before sort");

    //TODO: 벡터 iv 전체를 정렬하라.
    sort(iv.begin(),iv.end());

    printVector("after sort"); // 작은 수에서 큰 수 순서로 출력되어야 함
}

void vectorToMap() {
    vectorAppend();
    printVector();
    
    //TODO: mp에 기존 원소가 있다면, 모든 원소를 제거하라. vectorAppend() 참조
    if(!mp.empty()){
        mp.clear();
    }
    
    for(int i = 0 ; i < iv.size(); i++){
        mp.insert(make_pair(iv[i],"S"+to_string(iv[i] % 10)));
    }
    //TODO: 벡터의 각 원소 값 val에 대해, 키로 val을 사용하고, 값으로 "S"+"val%10" 문자열을 
    //TODO: 만들어 맵 mp에 삽입하라. 예) 원소가 25라면 (25, "S5") 쌍이 삽입됨.
    //TODO: 정수 25%10를 문자열로 변환하는 함수는 to_string(25%10)이다.
    //TODO: 이 함수의 원형은 string to_string(int v); 이다.

    printMap("vector => map");
}
void vectorLambda() {
    vectorAppend();
    printVector("before add");
    int start = seed + 1;

    auto lmd = [start](int& element){
        element = element + start;
    };
    // 람다함수는 매개변수로 넘어 온 벡터 원소에 캡처리스트 변수 start 값을 더해 준다.
    // 주의: 매개변수와 캡처리스트의 데이타 타입을 잘 지정해야 한다. call by value?, reference?, or pointer?

    start++;// 이 문장의 위치는 반드시 위 람다함수 선언 뒤에 있어야 한다.
    
    for_each(iv.begin(),iv.end(),lmd);

    printVector("after add"); 
}

void find_map() {
    int key = rnd();

    if(mp.find(key) == mp.end()){
        cout << "key(" << key << ") not found" << endl;
    }
    else{
        cout << "(" << key << ", " << mp.at(key) << ")" << endl;
    }
    // TODO: mp에서 key를 검색한 후,
    //       키가 존재하면 (키, 값) 쌍을 출력하고,
    //       키가 존재하진 않을 경우 "key(키) not found"를 출력한다.
}

void mapFind() {
    vectorToMap();
    find_map();
    find_map();
    find_map();
}
void mapToVector() {
    vectorToMap();

    iv.clear();
    //TODO: 벡터 iv의 모든 원소를 제거한다.


    for (auto p: mp)
        iv.push_back(p.first);
    // p는 struct pair { int first; string second; } 형의 구조체 변수이며
    // p는 mp에 저장된 각 원소를 의미하며 p.first가 키, p.second가 value 값임



    //TODO: 맵 mp의 모든 키 값을 순서적으로 벡터 iv에 추가하라.
    // 힌트: mp 내의 각 원소 키를 구하는 방법은 printMap()을 참조하라.
    // map은 tree를 이용하여 모든 원소를 키 값 순서로 관리하므로 키 순으로 자동 정렬된다.

    printVector("map => vector");
}

/******************************************************************************
 * menu_switch() 함수: 선택된 메인 메뉴 항목을 실행함
 ******************************************************************************/
string menuStr =
    "------------- Template and STL ------------\n"
    "  0.exit 1.template_class 2.vector 3.sort  \n"
    "  4.lambda 5.map 6.find 7.mapToVector      \n"
    "-------------------------------------------\n"
    "menu item? ";

void menu_switch(int menu)
{
    switch (menu) {
    case 1: templateClass(); break;
    case 2: vectorDisplay(); break;
    case 3: vectorSort();    break;
    case 4: vectorLambda();  break;
    case 5: vectorToMap();   break;
    case 6: mapFind();       break;
    case 7: mapToVector();   break;
    }
    cout << endl;
}

/******************************************************************************
 * main() 함수
 ******************************************************************************/
int main()
{
    while (true) {
        int menu;
        cout << menuStr;
        cin >> menu;
        if (menu == 0) break;
        menu_switch(menu);
    }
    cout << "\nGood bye!!" << endl;
}
