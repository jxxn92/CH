#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * Person Container
 ******************************************************************************/

class Container {
    string title;  // �����̳� Ÿ��Ʋ
    int    size;   // �����̳ʿ� ����� ���� �迭 arr�� ũ��
    int    *arr;   // size ���� ���Ҹ� ���� �迭 ���� �ּ�
public:
    Container();
    Container(string title);
    Container(string title, int size);
    Container(const Container& con);
    ~Container();


    void setTitle(string title);
    string getTitle();
    void printIntArray();
    Container& newIntArray(){
        if (arr != nullptr){
            delete [] arr;
        }
        cout << "element numbers of int array[]? ";
        cin >> size;
        arr = new int[size];
        return *this;
    }
    Container& inputIntArray(){ 
    cout << "input " << size << " integers: ";
    for (int i = 0; i < size; ++i){
        cin >> arr[i];
        }
    return *this;
    }
};

Container::Container():Container("no-title") { }

Container::Container(string title):Container(title,0) { }

Container::Container(string title, int size) {
    this -> title = title;
    this->size = size;
    if(size > 0){
        arr = new int[size];
    }
    else{
        arr = nullptr;
    }
    for(int i = 0 ; i < size ; i++){
        arr[i] = 0;
    }
    cout << "Container(): "; printIntArray();
}

Container::~Container() {
    cout << "~Container(): "; printIntArray();
    if (arr != nullptr)
        delete [] arr;
}

void Container::setTitle(string title) {
    this->title = title;
}

string Container::getTitle() {
    return title;
}

void Container::printIntArray() {
    cout << title << ": arr[" << size << "]: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
Container::Container(const Container& con){
    
    this -> title = con.title;
    this -> size = con.size;
    if(size > 0){
        this->arr = new int[size];
        for(int i = 0 ; i < size ; i++){
            this ->  arr[i] = con.arr[i];
        }
    }
    else{
        arr = nullptr;
    }
    cout << "Container(Container& c): "; printIntArray();

}


/******************************************************************************
 * Global functions
 ******************************************************************************/
void skipEnter() {
    string s;
    getline(cin, s); // �޴��׸� ��ȣ ���� [����]�� ������
}
void inputTitle(Container& str){
    string title;
    cout << "input title: ";
    getline(cin,title);
    str.setTitle(title);
}
void refParam() {
    Container c("C", 3);
    Container b("B");
    Container a;
    Container d;
    skipEnter();
    inputTitle(d);
}
Container& changeTitle(Container& rc) {
    string s;
    cout << "title to change: ";
    getline(cin, s);
    rc.setTitle(s);
    return rc;       // rc�� ���� ��ü�� ������ ������
}

void refRet1() {
    skipEnter();
    Container c("C");
    Container& rc = changeTitle(c); // rc�� ���� ��ü c�� ����Ÿ�� �����ϴ� ����������
    cout << " c.getTitle(): " <<  c.getTitle() << endl;
    cout << "rc.getTitle(): " << rc.getTitle() << endl;
    cout << "---" << endl;
    cout << "appendTitle(c).getTitle(): " << changeTitle(rc).getTitle() << endl;
    cout << "             c.getTitle(): " <<               c.getTitle() << endl;
    cout << "            rc.getTitle(): " <<              rc.getTitle() << endl;
}

void refRet2() {
    Container c("C");
    c.newIntArray().inputIntArray().printIntArray();
}

void explicitCopy() {
    Container c1("c1", 4);
    c1.inputIntArray().printIntArray();
    cout << "---" << endl;
    Container c2(c1);
    c2.setTitle("c2");
    c2.printIntArray();
    cout << "---" << endl;
    c2.inputIntArray().printIntArray();
    c1.printIntArray();
}
void callByValue(Container v) {
    cout << "callByValue" << endl;
    v.setTitle("V");
    v.inputIntArray().printIntArray();
}

Container returnValue(Container& r) {
    cout << "returnValue" << endl;
    return r;  // �ڵ����� ��������� ȣ��
}

void implicitCopy() {
    Container a("A", 2);
    a.inputIntArray().printIntArray();
    cout << "---" << endl;
    Container b = a; // �ڵ����� ��������� ȣ��
    b.setTitle("B");
    b.inputIntArray().printIntArray();
    cout << "---" << endl;
    callByValue(a); // �ڵ����� ��������� ȣ��
    cout << "---" << endl;
    Container c = returnValue(a);
    c.setTitle("C");
    c.inputIntArray().printIntArray();
    cout << "---" << endl;
}



string menuStr =
"****************************** Main Menu ******************************\n"
"* 0.Exit 1.refParam 2.refRet1 3.refRet2 4.explicitCopy 5.implicitCopy *\n"
"***********************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: refParam();     break;
        case 2: refRet1();      break;
        case 3: refRet2();      break;
        case 4: explicitCopy(); break;
        case 5: implicitCopy(); break;
        }
    }
    cout << "Good bye!!" << endl;
}
