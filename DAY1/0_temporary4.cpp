#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }

	Point(const Point& p) { std::cout << "copy ctor" << std::endl; }
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
Point& f2() // return by reference : 리턴용 임시객체를 만들지 말고
{			//						pt 자체를 반환해 달라는 의미.
	return pt;
}
int main()
{
	std::cout << "------" << std::endl;

//	f1().x = 10; // error. f1()은 임시객체를 반환 하는데
				 // 임시객체(temporary)는 등호의 왼쪽에 올수 없다.
//	f1();
	f2().x = 10; // ok.. 결국 pt.x = 10 이 됩니다.

	std::cout << "------" << std::endl;

}



Point& f3() 
{			
	Point p(1, 2);
	return p;   // 컴파일 에러는 아니지만, 절대 이렇게 하면 안됩니다.
				// F43(21page) : 절대 지역변수를 참조나 포인터로 반환
				//			하지말라.
}
// 핵심 1. value return 과 reference return 의 차이점 알아 두세요
//     2. reference return 은 객체가 파괴 되지 않은 경우(전역변수등)에
//        만 사용해야 합니다.
//		  지역변수는 반드시 value return 으로만 사용해야 합니다.