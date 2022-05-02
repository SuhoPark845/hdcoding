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

int main()
{
	Truck* p1 = new Truck;
	p1->AddRef();

	Truck* p2 = p1;
	p2->AddRef();

	p1->Release();
	p2->Release();
}