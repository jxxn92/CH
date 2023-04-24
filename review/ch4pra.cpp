#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/******************************************************************************
 * class Container
 ******************************************************************************/

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
    void newIntArray();
    void inputIntArray();
    
};

Container::Container(){
    size = 0;
    arr = nullptr;
    cout << "Container(): arr = nullptr; size = 0;" << endl;
}
Container::~Container(){
    if(arr == nullptr){
        cout<< "~Container(): "<< title << endl;
    }
    else{
        cout << "~Container(): arr[" << size << "] deleted;" << endl;
    }
}
void Container::setTitle(string title) {
    this -> title = title;
}

string Container::getTitle() {
    return title;
}
void Container::newIntArray(){
    cout << "element numbers of int array[]? ";
    cin >> size;
    arr = new int[size];
}
void Container::inputIntArray(){
    int num;
    cout << "input "<< size <<" integers: " ;
    for(int i = 0 ; i <size ; i++){
        cin >> num;
        arr[i] = num;
    }
    cout << "arr[" << size <<"]: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}
void Container::average(){
    double sum = 0;
    for (int i = 0 ; i < size; i++){
        sum += arr[i];
    }
    sum /= size ;
    cout << "average: " << sum << endl;
}

void Container::rightRotateTitle(){
    string str;
    str = title;
    int len = str.length();

    for(int i = 0 ; i < len ; i++){
        string front = str.substr(0,len-1);
        string last = str.substr(len-1,1);
        str = last + front;
        cout << str << endl;
    }   
}

void Container::findDeleteTitle(){
    string find;
    cout << "word to delete? ";
    cin >> find;

    int startindex = 0;

    while(true){
        int findex = title.find(find,startindex);
        if(findex == -1){
            break;
        }
        title.erase(findex,find.length());
        startindex = 0;
    }

    cout << title << endl;
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
    cout << "input " << size << " words: ";

    for(int i = 0 ; i <size ; i++){
        string str;
        cin >> str;
        pArr[i].setTitle(str);
    }
    return pArr;
}

void printTitles(Container *pArr, int size) {
    cout << "words: " ;
    string str;
    for(int i = 0; i < size; i++){
        str = pArr[i].getTitle();
        cout << str << " ";
    }
    cout << endl;
}

void objectArray() {
    Container *pArr; // Container ��ü �迭 ���� �ּ�
    int size;        // Container ��ü �迭 ���� ����
    cout << "element numbers of Container array[]? ";
    cin >> size;
    pArr = newObjectArray(size);
    printTitles(pArr, size);
    /* ���⼭ pArr�� ������ �ϴ� �޸𸮸� �ݳ��Ͻÿ�. */
    delete [] pArr;
}

void inputTitle(Container* cp) {
    string s;
    string str;
    getline(cin, s); // �ռ� �Էµ� �޴��׸� ��ȣ ���� [����]�� ������
    cout << "input title: ";
    getline(cin,str);
    cp->setTitle(str);
}

void rotateTitle() {
    Container c;
    inputTitle(&c);
    cout << "c.getTitle(): " << c.getTitle() << endl;
    c.rightRotateTitle();
}

void findDelete() {
    Container c;
    inputTitle(&c);      // This AAis aAA AAtest AAtitle.
    c.findDeleteTitle();
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