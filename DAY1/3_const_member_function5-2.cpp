#include <iostream>
#include <vector>

// 참조계수를 책임지는 기반 클래스 설계
class RefCount
{
	int ref = 0;
public:
	void AddRef() { ++ref; }
	void Release() { if (--ref == 0) delete this; }
};
// Truck 도 참조 계수 기술로 관리하고 싶다.
class Truck : public RefCount 
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	Truck* p = new Truck;
	p->AddRef();
	p->Release();
}