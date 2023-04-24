/**************************************************
 ���� �ڵ�� �������� �����Ͽ� ���� �Լ� append()�� �ۼ��ϰ� 
 ��ü ���α׷��� �ϼ��Ͻÿ�.
 append()�� Buffer ��ü�� ���ڿ��� �߰��ϰ� 
 Buffer ��ü�� ���� ������ ��ȯ�ϴ� �Լ��̴�.
 **************************************************/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Ŭ���� ���� �Ұ�
class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }  //  ������
	
	void add(string next)  {                    // text�� next ���ڿ� �����̱�   
		text += next; 
	}
	void print() {                              // ���� ���
		cout << text << endl;
	}
	
	void replace(string s, string r){            // text �� ���ڿ� ��ȯ
		int findex = text.find(s);
		text.replace(findex, s.length(), r);
	}
};


// ���⿡  append() �Լ� �߰� 

Buffer& append(Buffer&buf,string str){
    buf.add(str);
    return buf;
}


// main ���� �Ұ�
int main() {
	Buffer buf("Hello ");            // ��ü ����
	
	string str;
	cout << "Enter string : ";       // buf ��ü �ڿ� ���� ���ڿ� �Է�
	cin >> str;
	Buffer& temp = append(buf, str); // buf�� ���ڿ���  �Էµ� str ������ ���ڿ��� ������
	
	temp.print();                    // ���� ���
	buf.print();  
	
	buf.replace("Hello", "Good-Bye");   // "Hello", "Good-Bye"�� ����
	temp.print(); 
	buf.print();                        // ���� ���
	
}

/*
���α׷� ���� �������

(���)Enter string : (�Է�)Deok
(���)Hello Deok
(���)Hello Deok
(���)Good-Bye Deok
(���)Good-Bye Deok
*/

