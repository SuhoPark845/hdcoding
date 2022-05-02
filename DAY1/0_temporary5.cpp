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
//	std::cout << static_cast<Base>(d).value << std::endl; // 10
//	std::cout << static_cast<Base&>(d).value << std::endl; // 10

	static_cast<Base>(d).value = 30; // error. 임시객체는
									 // 등호의 왼쪽에 올수 없다.
	static_cast<Base&>(d).value = 30;// ok.. 

}
// 결론, 임시객체(temporary)는
// 1. 개발자가 의도적으로 만들때도 있고
//    ==> 함수 인자로 전달할때      ex) f( Point(1,2))

// 2. 개발자가 작성한 코드 때문에 생성될수도 있다.
//   ==> 함수가 return by value 를 사용할때
//   ==> value type 으로 캐스팅 할때!!

// 임시객체가 언제 생성되는지 알아야, 버그를 막고, 성능을 향상시킬수 있습니다.







