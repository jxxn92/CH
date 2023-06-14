/*************************************************************************
 * 아래 Circle 클래스는 원의 반지름을 관리한다.
 *************************************************************************/

#include <iostream>
using namespace std;

class Circle {
private:
	int radius; 
public:
	Circle(int r = 0) {radius = r;};
	void show() { cout <<  "radius = "  << radius <<  endl;}
	void setRadius(int r) { this->radius = r;}


    /*****************************************************************/
	/* 여기에 외부 연산자 함수의 클래스 내 선언 */
    friend Circle operator+(const int& cnt,const Circle& c);
}; 


/*****************************************************************/
/* 여기에  + 연산자 함수를 구현 */

Circle operator+(const int& cnt,const Circle& c){
    Circle *tmp = new Circle;
    tmp->radius = c.radius + cnt;
    return *tmp;
}





//아래 코드는 수정 불가

/* 입출력 예
(입력)input radius = 5
(출력)radius = 10
(출력)radius = 15
*/

/*********************************************************************
 * 아래 main() 함수는 위의 Circle 크래스를 이용한 예이다.
 *  + 연산자가 동작할수 있도록 위의 코드의 일부를 수정하시오.
 * 아래 코드는 절대 수정하지 마시오. 
 *********************************************************************/
int main () {
	Circle a, b;
	int radius ;

	cout << "input radius = " ;
	cin >> radius;

	a.setRadius(radius*2);
           /* 주어진 숫자를 Circle 객체의 radius값에 더해준다. */
	b = radius + a ;

	a.show();
	b.show();
}