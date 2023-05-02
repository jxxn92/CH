#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Container {
    string title;  // �����̳� Ÿ��Ʋ
    int    size;   // �����̳ʿ� ����� ���� �迭 arr�� ũ��
    int    *arr;   // size ���� ���Ҹ� ���� �迭 ���� �ּ�
public:
    Container();
    ~Container();
    void setTitle(string title);
    string getTitle();
    void newArray();
    void average();
    void rightRotateTitle();
    void findDeleteTitle();
    int newIntArray();
    void inputIntArray();
};

Container::Container(){
    arr = nullptr;
    size = 0;

    cout << "Container(): arr = nullptr; size = " << size << ";" << endl;
}

Container::~Container(){
    if(arr == nullptr){
        cout << "~Container(): " << title << endl;
    }
    else{
        cout << "~Container(): arr[" << size << "] deleted;" << endl;
    }

}

int Container::newIntArray(){

    cout << "element numbers of int array[]? ";
    cin >> size;
    arr = new int[size];

}

void Container::inputIntArray(){

    cout << "input " << size << " integers: ";

    for(int i = 0 ; i < size ; i++){
        cin >> arr[i]; 
    }

    cout << "arr[" << size << "]: ";

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

void Container::average(){
    double sum = 0;
    double avg = 0;

    for(int i = 0; i < size ; i++){
        sum += arr[i];
    }
    avg = sum / size;

    cout << "average: " << avg << endl;
}

void Container::setTitle(string title) {
    this -> title = title;
}

string Container::getTitle() {
    return title; 
}

/******************************************************************************
 * Global functions
 ******************************************************************************/

void constructor() {
    Container c;
    c.setTitle("constructor-title");
    cout << "c.getTitle(): " << c.getTitle() << endl;
}

void intArray() {
    Container c;
    c.newIntArray();
    c.inputIntArray();
    c.average();
}

Container *newObjectArray(int size) {
    Container *pArr = nullptr; // Container ��ü �迭 ���� �ּ�
    
    pArr = new Container[size];
    
    for(int i = 0; i < size; i++){
        
    }

    return pArr;
}

void printTitles(Container *pArr, int size) {
}

void objectArray() {
    Container *pArr; // Container ��ü �迭 ���� �ּ�
    int size;        // Container ��ü �迭 ���� ����
    cout << "element numbers of Container array[]? ";
    cin >> size;
    pArr = newObjectArray(size);
    printTitles(pArr, size);

    delete [] pArr;
}

void inputTitle(Container* cp) {
    string s;
    getline(cin, s); // �ռ� �Էµ� �޴��׸� ��ȣ ���� [����]�� ������
    /* ���⿡ �ڵ带 �����϶�. */
}

void rotateTitle() {
}

void findDelete() {
}

/******************************************************************************
 * main()
 ******************************************************************************/

string menuStr =
"******************************** Main Menu *********************************\n"
"* 0.Exit 1.constructor 2.intArray 3.objectArray 4.rotateTitle 5.findDelete *\n"
"****************************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: constructor(); break;
        case 2: intArray();    break;
        case 3: objectArray(); break;
        case 4: rotateTitle(); break;
        case 5: findDelete(); break;
        }
    }
    cout << "Good bye!!" << endl;
}

