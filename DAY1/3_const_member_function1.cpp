// Con.1 : By default, make objects immutable
// Con.2 : By default, make member functions const   ===>> 너무나 중요합니다.
//													꼭 지켜야 합니다.
// Con.3 : By default, pass pointersand references to consts

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// 핵심 : 상수 객체는 상수 멤버 함수만 호출할수 있습니다.
	//		 멤버 데이타를 수정하지 않은 모든 멤버함수는 반드시 상수 멤버함수로
	//	     해야 합니다.
	void print() const 
	{
//		x = 10; // error. 상수 멤버 함수는 모든 멤버가 상수 취급 됩니다.

		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
	const Point pt(1, 2); // 이 경우에 아래 3줄을 생각해 보세요.

	pt.x = 10;		// error. x는 public 이지만 "상수" 이므로	
	pt.set(10, 20);	// error. 
	pt.print();		// ??
}


