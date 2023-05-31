/*************************************************************************
 *   �Ʒ� Circle Ŭ������ ���� �������� �����Ѵ�.
 *   ������ + (2���� �Լ�), << (1���� �Լ�)�� ���������� �����ϵ��� �߰��Ͻÿ�.
 *   �߰��Ǵ� ������ �Լ��� Ŭ������ �������� �̿��Ͽ� ������ �����Ѵ�.
 *      1)  Circle ��ü =  Circle ��ü +  Circle ��ü   
 *             �캯 �� ���� Circle ��ü�� ���� �ִ� radius���� ���ؼ� 
                �º��� Circle ��ü�� radius ���� �����Ѵ�.
 *      2)  Circle ��ü =  int +  Circle ��ü
 *             �캯�� �־��� int ���� Circle ��ü�� radius���� ���ؼ� 
                �º��� Circle ��ü�� radius ���� �����Ѵ�.
 *      3)  Circle ��ü <<  int
*              �캯�� int ���� �º��� Circle ��ü�� radius���� �����Ѵ�.
 *************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Circle {
private:
	int radius; 
public:
	Circle(int r = 0) {radius = r;};
	void show() { cout <<  "radius = "  << radius <<  endl;}
	void setRadius(int r) { this->radius = r;}
	int  getRadius() { return this->radius;}
	friend Circle& operator+ (const Circle& op1, const Circle& op2);
	Circle& operator<< (const int& tmp);
	friend Circle& operator+(const int tmp,const Circle& op2);

            /*****************************************************************/
	/*  ���⿡ ( Circle ��ü =  Circle ��ü +  Circle ��ü )  ó���� ���� ���� ������ �Լ� ���� */
	

	/*  ���⿡  ( Circle ��ü <<  int ) ó���� ���� ���� ������ �Լ� ���� */
	

            
	/*  ���⿡  (Circle ��ü =  int +  Circle ��ü)  ó���� ���� �ܺ� ������ �Լ��� Ŭ���� ���� ������ �Լ� ���� */
	

	/*****************************************************************/

}; 



/*****************************************************************/
/* ���⿡ ( Circle ��ü =  Circle ��ü +  Circle ��ü )  ó���� ���� ���� ������ �Լ� ���� */
Circle& operator+ (const Circle& op1, const Circle& op2){
	Circle *tmp = new Circle;
	tmp->radius = op1.radius + op2.radius;
	return *tmp;
}


/* ���⿡  ( Circle ��ü <<  int ) ó���� ���� ���� ������ �Լ� ���� */
Circle& Circle::operator<<(const int& tmp){
	this -> radius += tmp;
	return *this;
}


/* ���⿡  (Circle ��ü =  int +  Circle ��ü)  ó���� ���� �ܺ� ������ �Լ� ���� */
Circle& operator+(const int op1,const Circle& op2){
	Circle *tmp = new Circle;
	tmp -> radius = op1 + op2.radius;
	return *tmp;
}

/*****************************************************************/



/* ����� ��
(���)input radius = (�Է�)5
(���)radius = 5
(���)radius = 15
(���)radius = 20
(���)radius = 10
*/


/*********************************************************************
 * �Ʒ� main() �Լ��� ���� Circle Ŭ������ �̿��� ���̴�.
 * �Ʒ� �ڵ�� ���� �������� ���ÿ�. 
 *********************************************************************/

int main () {
	Circle a, b, c, d;
	int radius ;

	cout << "input radius = " ;
	cin >> radius;

	a.setRadius(radius);

	/* Circle ��ü b�� radius���� �����Ѵ�. */	
	b << (radius*3);

	/* �� Circle ��ü a, b�� radius����  ���ؼ�  Circle ��ü c�� �����Ѵ�. */	
	c = a + b ;
    	/* �־��� ���� radius�� Circle ��ü a�� radius���� ���ؼ� Circle ��ü d�� �����Ѵ�. */
	d = radius + a ;

	a.show();
	b.show();
	c.show();
	d.show();
}