#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// temporary 특징
	Point pt(1, 2);
	
	pt.x = 10;				
	Point(1, 2).x = 10; // 핵심 1. temporary 는 lvalue가 될수 없다.		
						// error.

	Point* p1 = &pt;		 
	Point* p2 = &Point(1, 2);	// error
								// 핵심 2. temporary 는 주소연산자로
								//		주소를 구할수 없다.
							
	Point& r1 = pt;			
	Point& r2 = Point(1, 2);	// error
								// 핵심 3. temporary 를 
								// non-const reference로 가리킬수없다.

	const Point& r3 = Point(1, 2);	// ok.. const reference는
								// temporary 를 가리킬수 있다.
								// 이 경우 temporary 의 수명은
								// r3의 수명과 동일해 집니다.
								// 이름없는 객체에 이름을 부여한것
//	r3.x = 10;	// error
				// x는 public 이지만 const 참조 이므로

	// C++11 에서는 상수성 없이 임시객체를 가리키고 싶었습니다
	// move 와 perfect forwarding 이라는 기술을 만들기 위해서
	Point&& r4 = Point(1, 2); // const 없이 temporary를 
							// 가리키는 참조
							// rvalue reference 라고 합니다.
}







