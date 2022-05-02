#include <iostream>

struct Rect
{
	int left, top, right, bottom;
};

void f1(Rect& rc)       {}
void f2(const Rect& rc) {}

int main()
{
	Rect rc;
	f1(rc); // ok
	f2(rc); // ok

	f1(Rect()); // error. const 가 없으면 임시객체는 전달할수 없습니다.
	f2(Rect()); // ok
}
