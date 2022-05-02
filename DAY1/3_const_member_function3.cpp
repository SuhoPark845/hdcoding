#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;

	// mutable 멤버 데이타 : 상수 함수 안에서도 멤버 데이타를 
	//						수정할수 있게하기 위해 사용
	mutable char cache[32];
	mutable bool cache_valid = false;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 아래 함수는 분명 x, y 의 값을 변경하지 않으면 "상수함수"가 되어야 합니다.
	const char* toString() const 
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}

