// ������ value�� �����ϰ� �ִ� double linked ����Ʈ ���
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Node {
private:
    // ��� ����� private���� �����Ͽ� �ܺο��� ���� ���ϰ� �ϰ�,
    // BaseList������ Node�� ��� ����� ������ �� �ְ� Ŭ���� ��ü�� friend�� ����
    friend class BaseList;
    Node *prev;
    Node *next;
    int value;
    Node(int value) { prev = next = nullptr; this->value = value; }
    int getValue() { return value; // ���� ��� ������ n ��带 �߰��Ѵ�.
    void add(Node *n) { next = n; n->prev = this; }
    // ���� ��带 �����ϰ� �� ����� next ��带 �����Ѵ�.
    Node *remove() { Node *n = next; delete this; return n; }
};

// ���� ���� ������ ������ �ִ� double linked ����Ʈ
class BaseList {
private:
    Node *head;   // double linked ����Ʈ�� �� ó��  ��带 ����Ű�� ������
    Node *tail;   // double linked ����Ʈ�� �� ������ ��带 ����Ű�� ������
protected:
    int size;     // ���� ����Ʈ ���� �ִ� ���(������)�� ����

    BaseList() { head = tail = nullptr; size = 0; } // ������: ��� �ʱ�ȭ
    // �Ҹ���: ��� ��带 ������
    ~BaseList() { for (Node *n = head; n != nullptr; n = n->remove()); }

    void add_rear(int value);
    int remove_rear();
    int remove_front();
};

// ���ο� ���(value ���� �����ϰ� ����)�� ������ �� ����Ʈ�� �� �������� �߰�
void BaseList::add_rear(int value) {
    Node�� ������ ���� n�� �����ϰ� 
    ���ο� Node�� �������� ����(value �� ����)�Ͽ� n�� ����;
    ���� tail�� nullptr�� �ƴϸ� // NULL ��ſ� nullptr ���
        tail�� ����Լ� add(n)ȣ���Ͽ� ����Ʈ�� �� ���� n�� �߰� 
        ����Ʈ ���� ���� �߰� �Ǿ����Ƿ� tail�� n���� ����
    �ƴ� ��� // ����Ʈ�� ��尡 ���� ��� n�� ù ��尡 ��
        tail�� head ���� n���� ����
    BaseList�� ������ ������ 1 ����
}

// ����Ʈ�� ������ ��带 ������ �� �� ��忡 ����� value�� ����
int BaseList::remove_rear() {
    ����Ʈ�� ��� ������ 0�̸� -1 ���� // list empty error
    ������ ���� val�� �����ϰ�, 
    tail ��忡 ����� value ���� ���� val�� ����
    // ������ ����� �� ��带 ������ ���� prev ���� �� �ʱ�ȭ
    Node * ���� prev�� �����ϰ� tail�� prev ��� ���� ���� prev�� ����
    tail ��带 �޸𸮿� �ݳ���
    ����Ʈ�� ��� ������ 1 ����
    ���� prev�� nullptr�� �ƴϸ� // ������ ����� �� ��尡 ������ ���
        ���� prev�� ����Ʈ�ϴ� ����� next ����� nullptr�� ������
        tail�� ���� prev�� ���� // ���� ������ ���� ������ ����� �� ��尡 ��
    �ƴѰ�� ��, ���� prev�� nullptr�̸� // �� �̻� ���� ��尡 ���� ���
         tail�� head ���� nullptr�� ����
    val ���� ����
}

// ����Ʈ�� �� ó�� ��带 ������ �� �� ��忡 ����� value�� ����
int BaseList::remove_front() {
    ����Ʈ�� ��� ������ 0�̸� -1 ���� // list empty error
    ������ ���� val�� �����ϰ�, 
    head ��忡 ����� value ���� ���� val�� ����
    // ������ ����� �� ��带 ������ ���� next ���� �� �ʱ�ȭ
    Node * ���� next�� �����ϰ� head�� next ��� ���� ���� next�� ����
    head ��带 �޸𸮿� �ݳ���
    ����Ʈ�� ��� ������ 1 ����
    ���� next�� nullptr�� �ƴϸ� // ������ ����� �� ��尡 ������ ���
        ���� next�� ����Ʈ�ϴ� ����� prev ����� nullptr�� ������
        head�� ���� next�� ���� // ���� �� ù ���� ������ ����� �� ��尡 ��
    �ƴѰ�� ��, ���� next�� nullptr�̸� // �� �̻� ���� ��尡 ���� ���
         tail�� head ���� nullptr�� ����
    val ���� ����
}

class MyQueue ... {  	// BaseList�� ��ӹް� �����ؾ� ��
public:
    void enqueue(int value) {  // ť�� �� ���� ��� �߰� �� value ����
        Base List�� ������ ����Լ��� ȣ���� 
    }
    int dequeue() { // ť�� �� ���� ��� �����ϰ� ����� value �� ����
        return Base List�� ������ ����Լ��� ȣ����; 
    }
    int length() { Base List�� ����� �������� ������ ���� }
    static void test(); // static �Լ���
};

void MyQueue::test() {
    MyQueue mQ;
    int size;
    cout << "ť�� ������ ������ ����? ";
    cin >> size;
    cout << "ť�� enqueue()�� ���ҵ� : ";
    for (int i = 0; i < size; i++) {
        mQ.enqueue(i*100); // ť�� ����
        cout << i*100 << ' ';
    }
    cout << endl << "ť�� ũ��: " << mQ.length() << endl;
    cout << "ť���� dequeue()�� ��� ���ҵ� : ";
    while (mQ.length() != 0)
        cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
    cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}

class MyStack : public BaseList {
public:
    void push(int value) { // ������ �� ���� ��� �߰� �� value ����
        Base List�� ������ ����Լ��� ȣ����; 
    }
    int pop() { // ������ �� ���� ��� �����ϰ� ����� value �� ����
        return Base List�� ������ ����Լ��� ȣ����; 
    }
    int length() { Base List�� ����� �������� ������ ���� }
    static void test(); // static �Լ���
};

void MyStack::test() {
    MyStack mStack;
    int size;
    cout << "���ÿ� ������ ������ ����? ";
    cin >> size;
    cout << "���ÿ� push()�� ���ҵ� : ";
    for (int i = 0; i < size; i++) {
        mStack.push(i); // ���ÿ� Ǫ��
        cout << i << ' ';
    }
    cout << endl << "���� ũ��: " << mStack.length() << endl;
    cout << "���ÿ��� pop()�� ��� ���ҵ� : ";
    while (mStack.length() != 0)
        cout << mStack.pop() << ' '; // ���ÿ��� ��
    cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}

int main()
{
    MyQueue::test();
    MyStack::test();
    return 0;
}
