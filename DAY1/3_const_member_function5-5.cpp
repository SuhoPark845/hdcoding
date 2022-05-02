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
// AddRef �� Release�� �ڵ����� ȣ���ϴ� ������ ����(����Ʈ������)
// �� �����ϸ� �� �մϴ�.
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) {}
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) {}
	~AutoPtr() {}

	// ������ ó�� ���̱� ���� ������ ������
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