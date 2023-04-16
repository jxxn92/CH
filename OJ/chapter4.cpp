// iostream string head 파일 include할 것
 #include <iostream>
 #include <string>
 using namespace std;

/******************************************************************************
 * class Container
 ******************************************************************************/

class Container {
    string title;  // 컨테이너 타이틀
    int    size;   // 컨테이너에 저장된 정수 배열 arr의 크기
    int    *arr;   // size 개의 원소를 가진 배열 시작 주소
public:
    void setTitle(string title);
    string getTitle();
    void newArray();
    void average();
    void rightRotateTitle();
    void findDeleteTitle();
    void inputTitle(Container* cp);
    int inputIntArray();
    int newIntArray();
    Container();
    ~Container();

};
Container::Container(){
    arr = nullptr;
    size = 0;
    cout << "Container(): arr = nullptr; size = 0;" << endl;
}
Container::~Container(){
    if(arr == nullptr)
        {cout<< "~Container(): "<< title << endl;}
    else
        {cout << "~Container(): arr[" << size << "] deleted;"<<endl;}
}
void Container::setTitle(string title) {
    this -> title = title;
    /* 매개변수 title 값을 멤버 변수 title에 저장한다. */ //매개변수 title 과 멤버 변수 title의 이름이 같으므로 this 를 사용해서 구분해 줘야 한다.
}

string Container::getTitle() {
    return title;
    return "";  /* 멤버변수 title을 반환하라. */
}
int Container::newIntArray(){
    cout << "element numbers of int array[]? ";
    cin >> size;
    arr = new int[size];

}
int Container::inputIntArray(){
    cout << "input "<<size<<" integers: ";
    for(int i = 0; i < size ; i++){
        cin >> arr[i];
    }
    cout << "arr["<<size<<"]:";
    for(int i = 0; i < size ; i++){
        cout << " "<<arr[i];
    }
    cout << endl;
    
}
void Container::average(){
    
    double sum;
    for(int i = 0; i < size ; i++){
        sum += arr[i];
    }
    sum /= size;
    cout << "average: "<< sum << endl;
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
    Container *pArr = nullptr; // Container 객체 배열 시작 주소
    /* 여기에 코드를 구현하라. */
    pArr = new Container[size];
    cout << "input "<<size<<" "<<"words: ";

    
    for(int i = 0; i < size; i++){
        string title;
        cin >> title;
        pArr[i].setTitle(title);
    }
    return pArr;
}

void printTitles(Container *pArr, int size) {
    cout << "words: ";
    string title;
    for(int i = 0; i < size ; i++){
        title = pArr[i].getTitle();
        cout << title << " ";
    }
    cout << endl;

}

void objectArray() {
    Container *pArr; // Container 객체 배열 시작 주소
    int size;        // Container 객체 배열 원소 개수
    cout << "element numbers of Container array[]? ";
    cin >> size;
    pArr = newObjectArray(size);
    printTitles(pArr, size);
    /* 여기서 pArr이 포인터 하는 메모리를 반납하시오. */
    delete [] pArr;
}

void inputTitle(Container* cp) {
    string s;
    getline(cin, s); // 앞서 입력된 메뉴항목 번호 뒤의 [엔터]를 제거함
    /* 여기에 코드를 구현하라. */
    cout << "input title: ";
    string s1;
    getline(cin,s1);
    cp -> setTitle(s1);
}

void rotateTitle() {
    Container c;
    inputTitle(&c);
    cout << "c.getTitle(): " << c.getTitle() << endl;
    c.rightRotateTitle();
}
void Container::rightRotateTitle(){
    string s;
    s = title;
    int len = s.length();
    
     for(int i = 0; i < len; i++){
        string last = s.substr(len-1,1);
        string sub = s.substr(0,len-1);
        s = last + sub;
        cout << s << endl;
    }
}

void findDelete() {
    Container c;
    inputTitle(&c);      // This AAis aAA AAtest AAtitle.
    c.findDeleteTitle();
}
void Container::findDeleteTitle(){

    string fd; // fd = 찾아서 없앨 단어 받는 변수
    cout << "word to delete? ";
    cin >> fd;

    int startindex = 0;
    while(true){
        int findex = title.find(fd,startindex);
        if(findex == -1)
            break;
        title.erase(findex,fd.length());
        startindex = 0;
    }

    cout << title << endl;

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