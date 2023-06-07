#include <iostream>
#include <string>
using namespace std;

class item{
protected:
    int price; // golds의 수 
public:
    item(int p = 0) {
        price = p;
    }
    virtual void use(){
        cout << "item but nothing happens" << endl;
    }
    virtual void sell(){
        cout << "item for " << price << " golds" << endl;
    }
};

class weapon : public item{
public:
    weapon(int p = 0){
        this -> price = p;
    }
    void use() override{
        cout << "weapon and attacks" << endl;
    }
    void sell() override{
        cout << "weapon for " << price << " golds" << endl;
    }
};
class potion:public item{
public:
    potion(int p = 10){
        this -> price = p;
    }
    void use() override{
        cout << "potion and feels better" << endl;
    }
    void sell() override {
        cout << "item for " << price << " golds" << endl;
    }
};

//아래 코드는 수정 불가
void use(string name, item *ptr){
    cout << name << " use ";
    ptr->use();
}
void sell(string name, item *ptr){
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

// 입력 출력 예시
//(입력)Warrior 1 50
//(출력)Warrior use item but nothing happens
//(출력)Warrior use weapon and attacks
//(출력)Warrior use potion and feels better
//(출력)Warrior sells item for 1 golds
//(출력)Warrior sells item for 50 golds
//(출력)weapon for 50 golds
//(출력)item for 50 golds
//(출력)item for 10 golds