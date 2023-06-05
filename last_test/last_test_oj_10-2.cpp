#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

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
Rand rnd(0, RAND_COUNT-1); 


/******************************************************************************
 * Test
 ******************************************************************************/

void displayVector(vector< int >& v) {
    cout << "vector[size=" << v.size() << "]: ";

    for(int i = 0; i < v.size(); i++){
        printf("%d ",v.at(i));
    }
    cout << endl;
}

void createVector(vector< int >& v) { 
    const int RAND_COUNT = 10;

    for(int i = 0 ; i < RAND_COUNT; i++){
        v.push_back(rnd.getInt());
    }
    displayVector(v);
}

void createVector() {
    vector< int > v;
    createVector(v);
}

void sortVector() {
    vector< int > v;
    createVector(v);
    
    sort(v.begin(),v.begin()+5);
    sort(v.end()-5,v.end());
    
    displayVector(v);
}

void displayMap(map< int, int >& m) {
    cout << "map[size=" << m.size() << "]: ";
    for (auto p : m)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
}

void createMap(map<int,int>& m) {   
    const int RAND_COUNT = 10;

    for(int i = 0 ; i < RAND_COUNT ; i++){
        int key = rnd.getInt();
        int value =rnd.getInt();
        m[key] = value;
    }
    displayMap(m);
}

void createMap() {
    map<int, int> m;
    createMap(m);
}

void findMap() {
    map< int, int > m;
    createMap(m);
    int key = rnd.getInt();

    if(m.find(key) == m.end()){
        cout << "not found(key)  : (" << key << ")" << endl;

    }
    else{
        cout << "found(key,value): (" << key << "," << m[key] << ")" << endl;
    }
}

void lambda_1() {
    vector< int > v;
    createVector(v);
    int value = rnd.getInt();
    cout << "added value: (" << value << ")" << endl;
    auto lmd = [value](int& element){
        element = element + value;
    };
    for_each(v.begin(),v.end(),lmd);

    displayVector(v);
}

void lambda_2() {
    vector< int > v;
    createVector(v);
    int sum = 0;
    
    for_each(v.begin(),v.end(),[&sum](int& element){
        sum += element;
    });

    cout << "average: " << (double)sum / v.size() << endl; 
}

int main()
{
    string menuStr =
    "--------------- STL and Lambda -------------\n"
    "  0.exit 1.createVector 2.sort 3.createMap  \n"
    "  4.findMap 5.lambda-1 6.lambda-2           \n"
    "--------------------------------------------\n"
    "menu item? ";

    rnd.setSeed();
    
    while (true) {
        int menu;
        cout << menuStr;
        cin >> menu;
        if (menu == 0) break;

        switch (menu) {
        case 1: createVector(); break;
        case 2: sortVector();     break;
        case 3: createMap(); break;
        case 4: findMap(); break;
        case 5: lambda_1(); break;
        case 6: lambda_2(); break;
        }
        cout << endl;
    }
    cout << "\nGood bye!!" << endl;
}