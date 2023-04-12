#include <iostream>
using namespace std;

class ArrayUtility2{
public:

   static int* create(int &size);
   static void print(int s[], int size);
   static int* concat(int s1[], int s2[], int size_s1, int size_s2);
   static int* remove(int s1[], int s2[], int size_s1, int size_s2, int&retSize);
};


// ���� �ڵ�� ���� �Ұ�

// ���⿡ ArrayUtility2 ��� �Լ� �ڵ� �ۼ�
int* ArrayUtility2::create(int &size){
   cout << "Enter number of integer : ";
   cin >> size;
   int *arr = new int[size];

   if(arr == nullptr){
      exit(1);
   }   
   cout << "Enter "<< size <<" integer(s) : ";
   for (int i = 0 ; i < size ; i++){
      cin >> arr[i];
   }
   return arr;
} 
void ArrayUtility2::print(int s[], int size){

   for(int i = 0; i < size ; i++){
      cout << s[i] << " "; 
      }
   cout << endl;
}                                                      //3         2
int* ArrayUtility2::concat(int s1[], int s2[], int size_s1, int size_s2){
   int *arr = new int[size_s1 + size_s2];

   for(int i = 0 ; i < size_s1; i++){
      arr[i] = s1[i];
   }

   for(int i = 0 ; i < size_s2; i++){
      arr[size_s1 + i] = s2[i];
   }

   return arr;
}
int* ArrayUtility2::remove(int s1[], int s2[], int size_s1, int size_s2, int&retSize){
   
   int *p = new int[size_s1 + size_s2];
   int cnt = 0;

   for(int i = 0 ; i < size_s1; i++){
      for(int j = 0; j < size_s2; j++){
         if (s1[i] == s2[j]){
            p[cnt] = s1[i];
            cnt++;
         }     
      }
   }
   retSize = cnt;
   
   int *q = new int[retSize];
}
 
// �Ʒ� �ڵ� ���� �Ұ�

int main() {
   int size1, size2;

   // ù ��° �迭�� ���� �Ҵ� �ް� ����Ÿ�� �Է� �޴´�.
   int *x = ArrayUtility2::create(size1);

   // �� ��° �迭�� ���� �Ҵ� �ް� ����Ÿ�� �Է� �޴´�.
   int *y = ArrayUtility2::create(size2);

   // x[], y[] �� �迭�� ��ģ��.
   int *p = ArrayUtility2::concat(x, y, size1, size2);

   // ��ģ ���� �迭 p[]�� ����Ѵ�
   cout << "concat(x, y, " << size1 << ", " << size2 << "):" << endl;
   ArrayUtility2::print(p, size1+size2);

   //�迭 x[]���� y[]�� ����;
   int retSize;
   int *q = ArrayUtility2::remove(x, y, size1, size2, retSize);

   //�迭 x[]���� y[]�� �� ����� ����Ѵ�;
   cout << "remove(x, y, " << size1 << ", " << size2 << ", " << retSize << "):" << endl;
   ArrayUtility2::print(q, retSize);

   delete [] p;
   delete [] q;
   delete [] x;
   delete [] y;
}

/*
(���)Enter number of integer : (�Է�)5
(���)Enter 5 integer(s) : (�Է�)1 2 4 5 6
(���)Enter number of integer : (�Է�)7
(���)Enter 7 integer(s) : (�Է�)2 4 6 7 9 0 10
(���)concat(x, y, 5, 7):
(���)1 2 4 5 6 2 4 6 7 9 0 10 
(���)remove(x, y, 5, 7, 2):
(���)1 5 
*/