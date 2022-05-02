#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 언제 임시객체를 사용하는가 ?

// 핵심 3. const & 의 장점(특징)
// 1. 임시객체를 받을수 있다.
// 2. pt 를 읽기만 하겠다는것을 명확히 할수 있다.(실수 방지)

void foo(const Point& pt) {}

// 핵심 2. 아래처럼 만들면 인자로 "임시객체"를 전달할수 없게 됩니다.
//void foo(Point& pt) {} // Point& pt = Point(1,2)

int main()
{
//	Point pt(1, 2);
//	foo(pt);

	// 핵심 1. 함수 인자로만 사용하는 객체가 필요 하다면
	//		  임시객체 형태로 전달하는 것이 효율적이다.
	foo( Point(1, 2) );

	std::cout << "-----" << std::endl;
}





