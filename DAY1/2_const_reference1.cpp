// F16 ~ F20  ( 10 page ~)

#include <iostream>

struct Rect
{
	int left, top, right, bottom;
};

// call by value 의 문제점
// 1. 복사본 생성(메모리 오버헤드)
// 2. 복사생성자, 소멸자 호출, 즉, 2번의 함수 호출 발생
//void fn(Rect rc)

// 그래서, const reference 가 좋습니다.
// 장점 : 복사본 없고, 함수 호출도 없고, temporary도 받을수 있다.
// const 가 없으면 temporary 를 받을수 없습니다. 꼭 붙이세요..
void fn(const Rect& rc)
{
}

int main()
{
	Rect rc;
	fn(rc);
}
