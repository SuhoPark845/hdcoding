#include <iostream>
#include <vector>

template<typename T>
class RefCount
{
	mutable int ref = 0;
public:
	// 핵심 : 객체의 수명을 관리하는 아래 2개의 멤버 함수는 
	//		반드시 상수 멤버 함수가 되어야 합니다.
	//		상수 객체도 "수명 관리"는 할수 있어야 합니다.

	void AddRef() const { ++ref; }

	void Release() const // void Release( RefCount* this)
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
	const Truck* p = new Truck;

	p->AddRef(); // 이코드가 되야 할까요? 안되야 할까요 ?
	p->Release();
}