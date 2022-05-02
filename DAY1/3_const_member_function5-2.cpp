#include <iostream>
#include <vector>

// 참조계수를 책임지는 기반 클래스 설계
class RefCount
{
	int ref = 0;
public:
	void AddRef() { ++ref; }

	void Release()  // void Release( RefCount* this) 처럼되는것
	{				// 즉, this는 지금 RefCount* 타입 입니다.
		if (--ref == 0) 
			delete this; 
	}

	// 기반 클래스 소멸자는 반드시 가상함수가 되어야 합니다.
	virtual ~RefCount() {}
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