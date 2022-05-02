#include <iostream>
#include <vector>

// 참조계수를 책임지는 기반 클래스 설계

// CRTP : Curiously Recurring Template Pattern

// 기반 클래스에서 미래에 만들어진 파생 클래스 이름을 사용할수 있게 하는 기술

// 파생 클래스가 기반클래스에게 자신의 이름을 템플릿 인자로 전달하는 기술

template<typename T> 
class RefCount
{
	int ref = 0;
public:
	void AddRef() { ++ref; }

	void Release()  // void Release( RefCount* this)
	{				
		if (--ref == 0)
			//	delete this;
			delete static_cast<T*>(this);
	}
	~RefCount() {}
};

class Truck : public RefCount< Truck  >
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