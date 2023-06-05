#include <iostream>
#include <string>
#include <map>
using namespace std;

/******************************************************************************
 * Class Rand
 ******************************************************************************/
// ������ �߻���Ű�� Ŭ����: �� Ŭ������ �����ϰ� �Ѿ� ������.
#include <random>

const int RAND_COUNT = 10;
int seed = 0;

class Rand {
    default_random_engine re;
    uniform_int_distribution< int > dist;
public:
    Rand(int low, int high): dist(low, high) { }
    int getInt() { return dist(re); }
    void setSeed(int s = 0) {
        seed = s;
        if (seed == 0) {
            cout << "seed for random number? ";
            cin >> seed;
        }
        re.seed(seed);
    }
};
Rand rnd(0, RAND_COUNT-1); // [0, RAND_COUNT-1] ������ ���� �߻���

/******************************************************************************
 * template class
 ******************************************************************************/
// ���ø� Ŭ������ ���� ���� Ŭ����: Ű(int)�� ��(string)�� ������ �� �ִ� ����
template <typename K,typename V>
class Dic {
    K keys[20];             // key ����
    V values[20];        // value ����
    int count;                // ������ ������ ����
    int getKeyIndex(K key); // key�� �˻��� �� ã�� Ű�� �ε����� ��ȯ

public:
    Dic();

    int size();                   // ������ ������ ����
    void clear();                 // ������ ��� ���� ����
    void insert(K key, V value);  // ������ (key, value) ���� ����
    bool search(K key, V &value); // �������� key�� �˻��Ͽ� �����ϴ� ���� ã����
    void display();               // ������ ��� ���Ҹ� �����
};

template <typename K,typename V>
Dic<K,V>::Dic() { count = 0; }

template <typename K,typename V>
int Dic<K,V>::size() { return count; }

template <typename K,typename V>
void Dic<K,V>::clear() { count = 0; }  // ������ ��� ���� ����

// key�� �˻��� �� ã�� Ű�� �ε����� ��ȯ; ã�� ���ϸ� -1 ��ȯ\template <typename K,typename V>
template <typename K,typename V>
int Dic<K,V>::getKeyIndex(K key) {
    for (int i = 0; i < count; ++i)
        if (keys[i] == key) return i;
    return -1;
}

template <typename K,typename V>
void Dic<K,V>::insert(K key, V value)  { // ������ (key, value) ���� ����
    int i = getKeyIndex(key);
    if (i < 0) {                // ������ Ű�� �������� ���� ��� �߰�
        keys[count]   = key;
        values[count] = value;
        count++;
    }
    else
        values[i] = value;      // ������ Ű�� ������ ��� ���� ����
}

// �������� key�� �˻��Ͽ� �����ϴ� ���� ã���ְ�  key�� �������� ���� ��� false ��ȯ
template <typename K,typename V>
bool Dic<K,V>::search(K key, V& value) {
    int i = getKeyIndex(key);
    if (i < 0) return false;
    value = values[i];
    return true;
}

template <typename K,typename V>
void Dic<K,V>::display() { // ������ ��� ���Ҹ� �����
    cout << "dic: size(" << count << ")" << endl;  // insert()�� Ƚ��
    for (int i = 0; i < count; ++i)
        cout << "(" << keys[i] << "," << values[i] << ") ";
    cout << endl;
}

/******************************************************************************
 * template function
 ******************************************************************************/
// ���ø� �Լ��� ���� ���� �Լ�: ���� dic���� key�� �˻��Ͽ� �����ϴ� ���� �����
template <typename K, typename V>
void find(Dic<K,V>& dic, K key) {
    V value;
    if (dic.search(key, value))
        cout << "found(key,value): (" << key << "," << value << ")" << endl;
    else
        cout << "not found(key)  : (" << key << ")" << endl;
}

/******************************************************************************
 * Test
 ******************************************************************************/
//DicIntStr dicS; // Ű�� int, ���� string�� ����
Dic<int,string> dicS; // Ű�� int, ���� string�� ����
Dic<string,int> dicI; // Ű�� string, ���� int�� ����

void templateClass() {
    cout << endl << "Dic< int, string >" << endl;
    dicS.clear(); // ������ ��� ���Ҹ� ������
    for (int i = 0, key = rnd.getInt(); i < RAND_COUNT; ++i, key = rnd.getInt())
        dicS.insert(key, "V"+to_string(key));
        // rnd.getInt(): [0, 9] ������ ���� �߻�
        // to_string(key): ���� key 50�� ���ڿ�(string) "50"���� ��ȯ�� �ִ� �Լ��̴�.
    dicS.display(); // ������ ������ ��� �����
        cout << endl << "Dic< string, int >" << endl;
    dicI.clear();
    for (int i = 0; i < RAND_COUNT; ++i) {
        int key = rnd.getInt();
        dicI.insert("K"+to_string(key), key);
    }
    dicI.display();
}

void templateFunction() {
    cout << endl << "find Dic< int, string >" << endl;
    find(dicS, rnd.getInt()); // rnd.getInt(): [0, 9] ������ ���� �߻�
    find(dicS, rnd.getInt());
    cout << endl << "find Dic< string, int >" << endl;
    find(dicI, "K"+to_string(rnd.getInt()));
    find(dicI, "K"+to_string(rnd.getInt()));
}

/******************************************************************************
 * main() �Լ�
 ******************************************************************************/
int main()
{
    string menuStr =
        "------------------- Template ------------------\n"
        "  0.exit 1.template_class 2.template_function  \n"
        "-----------------------------------------------\n"
        "menu item? ";

    rnd.setSeed(); // ���� �߻��� ���� seed �� ����

    while (true) {
        int menu;
        cout << menuStr;
        cin >> menu;
        if (menu == 0) break;

        switch (menu) {
            case 1: templateClass();    break;
            case 2: templateFunction(); break;
        }
        cout << endl;
    }
    cout << "\nGood bye!!" << endl;
}