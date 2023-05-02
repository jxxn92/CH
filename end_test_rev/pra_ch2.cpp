#include <iostream>
using namespace std;

int main(){

    string name,id,find,text;
    double weight;
    bool married;

    cin >> boolalpha;
    cout << boolalpha;


    cout << "Hello world!!" << endl;

    cout << "name? " ;
    getline(cin,name);
    cout << "name : " << name << endl;

    cout << "id? " ;
    cin >> id;
    cout << "id : " << id << endl;

    cout << "weight? " ;
    cin >> weight;
    cout << "weight : " << weight << endl;

    cout << "married? " ;
    cin >> married;
    cout << "married : " << married << endl;

    getline(cin,text);

    cout << "name to find? ";
    getline(cin,find);

    if(name == find){
        cout << "name:" << name << ", id:" << id << ", weight:" << weight << ", married:" << married;
    }
    else{
        cout << find << ": not found" << endl;
    }

    return 0;
}