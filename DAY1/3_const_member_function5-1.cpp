#include <iostream>
#include <vector>

class Car
{
	int speed;
	int ref = 0;
public:
	~Car() { std::cout << "~Car" << std::endl; }

	void AddRef()  { ++ref; }
	void Release() { if (--ref == 0) delete this; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();
	Car* p2 = p1; // 포인터 복사 시 참조 계수 증가
	p2->AddRef();

	// 포인터 사용후에는 직접 지우지 말고 참조 계수 감소
	p2->Release();
	p1->Release();
}