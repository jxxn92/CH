#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char cmd[80];

    while(true){
        cout << "�����Ϸ��� exit�� �Է��ϼ���." << endl;
        cin.get(cmd,80);
        if(strcmp(cmd,"exit") == 0 ){
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;
        }
        else{
            cin.ignore();
        }
    }
}