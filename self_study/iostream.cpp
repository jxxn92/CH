#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char cmd[80];

    while(true){
        cout << "종료하려면 exit을 입력하세요." << endl;
        cin.get(cmd,80);
        if(strcmp(cmd,"exit") == 0 ){
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        }
        else{
            cin.ignore();
        }
    }
}