#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Person
{
    string name;
    int    id;
    double weight;
    bool   married;

public:
    Person();
    ~Person();
    Person(string _name, int _id, double _weight, bool _married);
    void setName(string _name);
    void setId(int _id);
    void setWeight(double _weight);
    void setMarried(bool _married);
    void println();
    string getName();
    int getId();
    double getWeight();
    bool getMarried();
};

Person::Person(){
    name = "no-name";
    id = 0;
    weight = 0;
    married = false;
    cout << "Person::Person():name:" << name << ", " << "id:" << id << ", " << "weight:" << weight << ", " << "married:" << married << endl; 
}

Person::Person(string _name, int _id, double _weight, bool _married){
    name = _name;
    id = _id;
    weight = _weight;
    married = _married;
    cout << "Person::Person():name:" << name << ", " << "id:" << id << ", " << "weight:" << weight << ", " << "married:" << married << endl;
}

Person::~Person(){
    cout << "Person::~Person():name:" << name << ", " << "id:" << id << ", " << "weight:" << weight << ", " << "married:" << married << endl;
}

string Person::getName(){
    return name;
}

int Person::getId(){
    return id;
}
double Person::getWeight(){
    return weight;
}

bool Person::getMarried(){
    return married;
}

void Person::setName(string _name)   {
    name = _name;
}

void Person::setId(int _id){
    id = _id;
}

void Person::setWeight(double _weight){
    weight = _weight;
}
void Person::setMarried(bool _married){
    married = _married;
}
void Person::println()   {
    cout << "name:"<< name << ", " << "id: " << id << ", " << "weight: " << weight << ", " << "married: " << married << endl;
}

void set(string name, int id, double weight, bool married) {
    Person p1;
    p1.setName(name);
    p1.setId(id);
    p1.setWeight(weight);
    p1.setMarried(married);
    p1.println();
}

void creator() {
    cout << "creator() begin" << endl;
    Person p2("p2", 1002, 60.5, false);
    cout << "creator() return" << endl;
}

int main() {
    cin >> boolalpha;
    cout << boolalpha;
    // married의 값을 1, 0이 아닌 true, false로 입력 받고 출력하기 위함 

    string name = "p1";
    int id = 1001;
    double weight = 72.5;
    bool married = true;

    set(name, id, weight, married);

    cout << endl;
    creator();

    cout << endl;

    cout << "name id weight married? ";
    cin >> name >> id >> weight >> married;
    Person p3(name, id, weight, married);

    cout << "output name:" << p3.getName() << ", id:" << p3.getId() << ", weight:" <<
    p3.getWeight() << ", married:" << p3.getMarried() << endl;

}
