#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
//-------------------------------------------

/*
void f1(Point  pt) {} // call by value     : 복사본 객체 생성
void f2(Point& pt) {} // call by reference : 복사본 객체 생성 안함

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/

//-----------------------------------

Point pt(1, 2); // 전역변수 

Point f1() // return by value : 리턴용 임시객체가 생성되어서 반환.
{
	return pt;
}
int main()
{
	std::cout << "------" << std::endl;

	f1().x = 10; // error. f1()은 임시객체를 반환 하는데
				 // 임시객체(temporary)는 등호의 왼쪽에 올수 없다.

	std::cout << "------" << std::endl;

}



