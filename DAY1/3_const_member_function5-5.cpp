#include <iostream>
#include <vector>

template<typename T>
class RefCount
{
	mutable int ref = 0;
public:
	void AddRef() const { ++ref; }
	void Release() const 
	{

		if (--ref == 0)
			delete static_cast<const T*>(this);

	}
	~RefCount() {}
};



class Truck : public RefCount< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};
// AddRef 와 Release를 자동으로 호출하는 간단한 도구(스마트포인터)
// 를 제공하면 편리 합니다.
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) {}
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) {}
	~AutoPtr() {}

	// 포인터 처럼 보이기 위한 연산자 재정의
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
int main()
{
	AutoPtr<Truck> p1 = new Truck;
	p1->AddRef();

	AutoPtr<Truck> p2 = p1;
	p2->AddRef();

	p1->Release();
	p2->Release();
}