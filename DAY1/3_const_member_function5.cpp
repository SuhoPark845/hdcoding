#include <iostream>
#include <vector>

class Car
{
	int speed;
public:
};
std::vector<Car*> v;

void foo()
{
	Car* p = new Car;
	v.push_back(p);

	// 더이상 p가 필요없다면 delete 해도 될까 ?
	// 코드가 복잡한 경우
	// 객체를 만드는 것은 쉽지만
	// 지우는 것은 어렵습니다. 아무도 사용하지 않는다는 약속이 있어야 합니다.
	delete p;
}

int main()
{
	foo();
}