#include <iostream>
#include <string>
using namespace std;

//main 함수 입력 출력 예시를 참고하여
//item class의 use, sell 함수와
//class potion, class weapon을 구현하라

class item{
protected:
    int price; // golds의 수 
public:
    item(int p = 0) {
        price = p;
    }
    void sell();
    virtual void use();
  //위에 코드는 수정 불가 
  //아래에 use, sell 함수 구현  
};

void item::sell(){
    cout << "item for " << price << " golds" << endl;
}

void item::use(){
    cout << "item but nothing happens" << endl;
}

//아래에 potion class, weapon class 구현 
class potion : public item{
public:
    potion();
    void use() override;
    void sell();
};

void potion::use(){
    cout << "potion and feels better" << endl;
}
void potion::sell(){
    cout << "item for 10 golds" << endl;
}

potion::potion(){

}
//=================================
class weapon : public item{
public:
    weapon(int price);
    void sell();
    void use() override;
};

weapon::weapon(int price):item(price){

}

void weapon::sell(){
    cout << "weapon for " << price << " golds" << endl;
}

void weapon::use(){
    cout << "weapon and attacks" << endl;
}

//=================================
//아래 코드는 수정 불가
void use( string name, item *ptr){
    cout << name << " use ";
    ptr->use();
}
void sell( string name, item *ptr){
    cout << name << " sells ";
    ptr->sell();
}
int main() {
    string name;
    int p1, p2;
    cin >> name >> p1 >> p2;
    item thing(p1);
    potion healing; // price 값 초기화, potion: 독약
    weapon sword(p2);   
    use(name, &thing);
    use(name, &sword);
    use(name, &healing);
    sell(name, &thing);
    sell(name, &sword);
    sword.sell();
    sword.item::sell();
    healing.sell();
}