/******************************************************************/
// �̹� �ǽ��� 10�忡 ���� ���̺� �ڵ� �����̴�.
// �Ʒ� ������ ���ø� Ŭ���� ����, vector, map, algorithm, lambda�� ����� �� �ִ� �ɷ��� Ȯ����.

// ���� �Ʒ� �ڵ�([���� 0] �ձ���)�� ��ŷ�Ͽ� ������ �� �ҽ� ���Ͽ� �����϶�.
/******************************************************************/

#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * Class Rand
 ******************************************************************************/
// ������ �߻��ϴ� Ŭ������. �����Ϸ� �������� �ǳ� �ٱ� �ٶ�.

#include <random>

int seed = 0;

class Rand {
    // ������ �����ϴ� ����
    default_random_engine re;
    // �߻��� ���� ������ ���� ������ �յ� ����(unfiform)�� ����
    uniform_int_distribution< int > dist;
public:
    // [low, high] ���� ���� ���� �߻��ϵ��� dist �ʱ�ȭ
    Rand(int low, int high): dist(low, high) { }
    
    // [low, high] ���� ���� ���� �߻��ϴ� �Լ�
    int operator() () { return dist(re); }
    
    void setSeed() {
        cout << "seed for random number? ";
        cin >> seed;
        re.seed(seed);
    }
};

// [10, 29] ������ ���� �߻���
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
 * �����̳� Ŭ���� map and vector, algorithm, lambda
 ******************************************************************************/
#include <map>
#include <vector>
#include <algorithm>

vector<int> iv;
map<int, string> mp;

void vectorLambda() {}

// map�� ��� ������ (Ű, ��) ���� ����Ѵ�.
void printMap(string msg = {}) {
	if (!msg.empty())
        cout << msg << endl;
    cout << "map: ";
    for (auto p: mp)
        cout << "(" << p.first << "," << p.second << ") ";
        // p�� struct pair { int first; string second; } ���� ����ü �����̸�
        // p�� mp�� ����� �� ���Ҹ� �ǹ��ϸ� p.first�� Ű, p.second�� value ����
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
	//rnd.setSeed(); // ���ð� ���� ������ �ּ��� �������� ���ÿ�. 
    if (!iv.empty()) iv.clear(); // iv�� ���� ���Ұ� ������ ��� ������

    for(int i = 0 ; i < 10 ; i++){
        iv.push_back(rnd());
    }
    // ���� �������: rnd() �Լ��� ȣ���� �� �� ���� ���� ���Ϳ� �߰��ϸ� �� 
    //            rnd()�� [10, 29] ������ ���� ���� �߻���Ŵ
}

// ���Ϳ� 10���� ���� ������ �� ���� ������ ����Ѵ�.
void vectorDisplay() {
    vectorAppend();
    printVector();
}

void vectorSort() {
    vectorAppend();
    printVector("before sort");

    //TODO: ���� iv ��ü�� �����϶�.
    sort(iv.begin(),iv.end());

    printVector("after sort"); // ���� ������ ū �� ������ ��µǾ�� ��
}

void vectorToMap() {
    vectorAppend();
    printVector();
    
    //TODO: mp�� ���� ���Ұ� �ִٸ�, ��� ���Ҹ� �����϶�. vectorAppend() ����
    if(!mp.empty()){
        mp.clear();
    }
    //TODO: ������ �� ���� �� val�� ����, Ű�� val�� ����ϰ�, ������ "S"+"val%10" ���ڿ��� 
    //TODO: ����� �� mp�� �����϶�. ��) ���Ұ� 25��� (25, "S5") ���� ���Ե�.
    //TODO: ���� 25%10�� ���ڿ��� ��ȯ�ϴ� �Լ��� to_string(25%10)�̴�.
    //TODO: �� �Լ��� ������ string to_string(int v); �̴�.

    printMap("vector => map");
}void find_map() {}
void mapFind() {}
void mapToVector() {}

/******************************************************************************
 * menu_switch() �Լ�: ���õ� ���� �޴� �׸��� ������
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
 * main() �Լ�
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
