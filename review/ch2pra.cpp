#include <iostream>
using namespace std;


int main(void){

    string name,off,id;
    string find;
    double weight;
    bool married;
    
    cin >> boolalpha;
    cout << boolalpha;

    cout << "Hello world!!" << endl;
    cout << "name? " ;
    getline(cin,name);
    cout << "name: " << name << endl;
    cout << "id? ";
    cin >> id;
    cout << "id: "<< id << endl;
    cout << "weight? ";
    cin >> weight;
    cout << "weight: "<< weight << endl;
    cout << "married?";
    cin >> married;
    cout << "married:"<< married << endl;
    getline(cin,off);
    cout << "name to find? "<< endl;
    getline(cin,find);

    if(find == name){
        cout << "name:"<< name << ", " << "id:" << id << ", "<< "weight:" << weight << ", " << "married:" << married << endl;
    }
    else{
        cout << find << " not found" << endl;
    }

    return 0;
}