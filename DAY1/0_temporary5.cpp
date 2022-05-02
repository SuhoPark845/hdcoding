#include <iostream>

struct Base
{
	int value = 10; 

	Base() {}
	Base(const Base& b) : value(b.value) 
	{
		std::cout << "Base copy ctor" << std::endl;
	}
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl; // 20

	// 아래 2줄의 차이점은 뭘까요 ?
	std::cout << static_cast<Base>(d).value << std::endl; // 10
//	std::cout << static_cast<Base&>(d).value << std::endl; // 10
}







