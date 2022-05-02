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
	void Go() { std::cout << "Truck Go" << std::endl; }
};
// AddRef 와 Release를 자동으로 호출하는 간단한 도구(스마트포인터)
// 를 제공하면 편리 합니다.
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p)         { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	
	~AutoPtr() { if (obj) obj->Release(); }

	// 포인터 처럼 보이기 위한 연산자 재정의
	T* operator->() { return obj; }
	T& operator*() { return *obj; } // 핵심.. "T&" 를 반환하는 이유를
									// 정확히 아셔야 합니다.
};
int main()
{
	AutoPtr<Truck> p1 = new Truck; // p1( new Truck)
	AutoPtr<Truck> p2 = p1;

	// p1은 객체지만 -> 와 * 연산자가 재정의 되었기때문에
	// raw pointer 와 동일하게 사용가능
	p1->Go();

	(*p1).Go(); 
}