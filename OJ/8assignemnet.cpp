#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Node{
private:
    friend class BaseList;
    Node *prev;
    Node *next;
    int value;
    Node(int value) { prev = next = nullptr; this->value = value; }
    int getValue() { return value;} // 현재 노드 다음에 n 노드를 추가한다.
    void add(Node *n) { next = n; n->prev = this; }
    // 현재 노드를 삭제하고 이 노드의 next 노드를 리턴한다.
    Node *remove() { Node *n = next; delete this; return n; }
};

// 여러 개의 노드들을 가지고 있는 double linked 리스트
class BaseList {
private:
    Node *head;   // double linked 리스트의 맨 처음  노드를 가리키는 포인터
    Node *tail;   // double linked 리스트의 맨 마지막 노드를 가리키는 포인터
protected:
    int size;     // 현재 리스트 내에 있는 노드(데이터)의 개수

    BaseList() { head = tail = nullptr; size = 0; } // 생성자: 멤버 초기화
    // 소멸자: 모든 노드를 삭제함
    ~BaseList() { for (Node *n = head; n != nullptr; n = n->remove()); }

    void add_rear(int value);
    int remove_rear();
    int remove_front();
};

// 새로운 노드(value 값을 저장하고 있음)를 생성한 후 리스트의 맨 마지막에 추가
void BaseList::add_rear(int value) {
    Node *n = new Node(value);
    if(tail != nullptr){
        tail->add(n);
        tail = n;
    }
    else{
        head = tail = n;
    }
    size++;
}

// 리스트의 마지막 노드를 제거한 후 그 노드에 저장된 value를 리턴
int BaseList::remove_rear() {
    if(size == 0)
        return -1;
    int val = tail->value;

    Node *prev = tail -> prev;
    delete tail;
    size--;
    if(prev != nullptr){
        prev->next = nullptr;
        tail = prev;
    }
    else{
        tail = head = nullptr;
    }
    return val;
}

// 리스트의 맨 처음 노드를 제거한 후 그 노드에 저장된 value를 리턴
int BaseList::remove_front() {
    if(size == 0){
        return -1;
    }
    int val = head->value;

    Node *next = head -> next;
    delete head;
    size--;
    if(next != nullptr){
        next->prev = nullptr;
        head = next;
    }
    else{
        tail = head = nullptr;
    }
    return val;
}

class MyQueue :public BaseList {  	// BaseList를 상속받게 선언해야 함
public:
    void enqueue(int value) {  // 큐의 맨 끝에 노드 추가 후 value 저장
        add_rear(value);
    }
    int dequeue() { // 큐의 맨 앞의 노드 삭제하고 노드의 value 값 리턴
        return remove_front(); 
    }
    int length() { return size; }
    static void test(); // static 함수임
};

void MyQueue::test() {
    MyQueue mQ;
    int size;
    cout << "큐에 삽입할 정수의 개수? ";
    cin >> size;
    cout << "큐에 enqueue()된 원소들 : ";
    for (int i = 0; i < size; i++) {
        mQ.enqueue(i*100); // 큐에 삽입
        cout << i*100 << ' ';
    }
    cout << endl << "큐의 크기: " << mQ.length() << endl;
    cout << "큐에서 dequeue()된 모든 원소들 : ";
    while (mQ.length() != 0)
        cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
    cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}

class MyStack : public BaseList {
public:
    void push(int value) { // 스택의 맨 끝에 노드 추가 후 value 저장
        add_rear(value); 
    }
    int pop() { // 스택의 맨 끝의 노드 삭제하고 노드의 value 값 리턴
        return remove_rear(); 
    }
    int length() { return size; }
    static void test(); // static 함수임
};

void MyStack::test() {
    MyStack mStack;
    int size;
    cout << "스택에 삽입할 정수의 개수? ";
    cin >> size;
    cout << "스택에 push()된 원소들 : ";
    for (int i = 0; i < size; i++) {
        mStack.push(i); // 스택에 푸시
        cout << i << ' ';
    }
    cout << endl << "스택 크기: " << mStack.length() << endl;
    cout << "스택에서 pop()된 모든 원소들 : ";
    while (mStack.length() != 0)
        cout << mStack.pop() << ' '; // 스택에서 팝
    cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}

int main()
{
    MyQueue::test();
    MyStack::test();
    return 0;
}
