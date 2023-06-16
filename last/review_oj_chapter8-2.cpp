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
        cout << n <<" "<< damage << endl;
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
//위에 코드는 수정 불가
//main함수 실행 출력을 참고 하여
//class weapon을 상속 받은 sword, gun 클라스를 구현하라
class sword : public weapon {
public:
    sword(string name,int damage);
    void attack();
    void stab();

};

sword::sword(string name,int damage):weapon(name,damage){    
    //cout << get_name() <<" "<< get_damage() << endl;
}

void sword::attack(){
    cout <<"Attack with " << get_name() << " Damage " << get_damage() <<  endl;
}

void sword::stab(){
    cout <<"Stab with " << get_name() << " Damage " << get_damage() <<  endl;
}

class gun : public weapon{
public:
    gun(string name,int damage);
    void attack();
};

gun::gun(string name,int damage) : weapon(name,damage){
    //cout << get_name() <<" "<< get_damage() << endl;

}

void gun::attack(){
    cout <<"Shoot with " << get_name() << " Damage " << get_damage() <<  endl;
}

//여기에 코드 작성

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