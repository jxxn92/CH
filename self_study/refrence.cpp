/* #include <iostream>
using namespace std;

int change_val(int &p){

    p = 3;

    return 0;
}

int main(){

    int number = 5;

    cout << number << endl;
    change_val(number);
    cout << number << endl;
} */

/* #include <iostream>
using namespace std;

int main(){
    int a = 3;
    int &another_a = a;

    another_a = 5;
    cout << "a : " << a << endl;
    cout << "another_a : " << another_a << endl;

    return 0;
} */

/* #include <iostream>
using namespace std;

int main(){
    int x;
    int &y = x;
    int &z = y;

    x = 1;
    cout << "x : " << x << " y : " << y << " z : " << z << endl;

    y = 2;
    cout << "x : " << x << " y : " << y << " z : " << z << endl;

    z =3;
    cout << "x : " << x << " y : " << y << " z : " << z << endl;

} */
/* 
#include <iostream>
using namespace std;

int main(){
    
    int arr[3][2] = {1,2,3,4,5};
    int (&ref)[3][2] = arr;

    ref[0][0] = 2;
    ref[1][0] = 3;
    ref[2][0] = 1;

    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << endl;
    return 0;
} */


#include <iostream>

class Animal {
private: //private 로 선언해서 외부에서 값을 변경하지 못하도록 설정
    int food;
    int weight;
public:
    void set_animal(int _food, int _weight) {
        food = _food;
        weight = _weight;
}
void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
}
void view_stat() {
    std::cout << "이 동물의 food   : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
}
};  // 세미콜론 잊지 말자!

int main() {
    Animal animal;
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
    
    return 0;
}