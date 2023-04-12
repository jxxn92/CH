#include <iostream>
using namespace std;

class ArrayUtility2{
public:

   static int* create(int &size);
   static void print(int s[], int size);
   static int* concat(int s1[], int s2[], int size_s1, int size_s2);
   static int* remove(int s1[], int s2[], int size_s1, int size_s2, int&retSize);
};


// 위에 코드는 수정 불가

// 여기에 ArrayUtility2 멤버 함수 코드 작성
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
 
// 아래 코드 수정 불가

int main() {
   int size1, size2;

   // 첫 번째 배열에 대해 할당 받고 데이타를 입력 받는다.
   int *x = ArrayUtility2::create(size1);

   // 두 번째 배열에 대해 할당 받고 데이타를 입력 받는다.
   int *y = ArrayUtility2::create(size2);

   // x[], y[] 두 배열을 합친다.
   int *p = ArrayUtility2::concat(x, y, size1, size2);

   // 합친 정수 배열 p[]를 출력한다
   cout << "concat(x, y, " << size1 << ", " << size2 << "):" << endl;
   ArrayUtility2::print(p, size1+size2);

   //배열 x[]에서 y[]를 뺀다;
   int retSize;
   int *q = ArrayUtility2::remove(x, y, size1, size2, retSize);

   //배열 x[]에서 y[]를 뺀 결과를 출력한다;
   cout << "remove(x, y, " << size1 << ", " << size2 << ", " << retSize << "):" << endl;
   ArrayUtility2::print(q, retSize);

   delete [] p;
   delete [] q;
   delete [] x;
   delete [] y;
}

/*
(출력)Enter number of integer : (입력)5
(출력)Enter 5 integer(s) : (입력)1 2 4 5 6
(출력)Enter number of integer : (입력)7
(출력)Enter 7 integer(s) : (입력)2 4 6 7 9 0 10
(출력)concat(x, y, 5, 7):
(출력)1 2 4 5 6 2 4 6 7 9 0 10 
(출력)remove(x, y, 5, 7, 2):
(출력)1 5 
*/