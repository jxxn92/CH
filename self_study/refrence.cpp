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

#include <iostream>
using namespace std;

int main(){
    int arr[3] = {1,2,3};
    int (&ref)[3] = arr;

    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;

    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << endl;
    return 0;
}