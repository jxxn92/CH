#include <iostream>
#include <string>
using namespace std;

class weapon{
private:
    string name;
    int damage;
public:
    weapon(string n="?", int d = 10){ 
        name = n; damage = d;
        cout << name <<" "<< damage << endl;
    }
    string get_name(){
        return name;
    }
    int get_damage(){
        return damage;
    }
    void attack(){
        cout <<"Attack with " << name << " Damage " << damage <<  endl;
    }
};

class sword : public weapon{
public:    
    sword(string n="?", int d = 10) : weapon(n, d){}
    void stab(){cout <<"Stab with " << get_name() << " Damage " << get_damage() <<  endl;}
};

class gun : public weapon{
public:    
    gun(string n="?", int d = 10) : weapon(n, d){}
    void attack(){
        cout <<"Shoot with " << get_name() << " Damage " << get_damage() <<  endl;
    }
};
//위에 코드는 수정 불가
//main함수 실행 출력을 참고 하여
//class weapon을 상속 받은 sword, gun 클라스를 구현하라

//여기에 코드 작성

//아래 코드는 수정 불가
int main() {
    string w1,w2,w3;
    int d2,d3;

    cin >> w1;
    cin >> w2 >> d2;
    cin >> w3 >> d3;

    weapon punch(w1);
    sword a(w2,d2);
    gun b(w3, d3);

    punch.attack();
    a.attack();
    a.stab();
    b.attack();
    b.weapon::attack();
}


//아래는 예시 입력 출력이다
//(입력)fist
//(입력)Excaliber 25
//(입력)AK47 47
//(출력)fist 10
//(출력)Excaliber 25
//(출력)AK47 47
//(출력)Attack with fist Damage 10
//(출력)Attack with Excaliber Damage 25
//(출력)Stab with Excaliber Damage 25
//(출력)Shoot with AK47 Damage 47
//(출력)Attack with AK47 Damage 47