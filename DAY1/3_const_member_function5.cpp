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

	// ���̻� p�� �ʿ���ٸ� delete �ص� �ɱ� ?
	// �ڵ尡 ������ ���
	// ��ü�� ����� ���� ������
	// ����� ���� ��ƽ��ϴ�. �ƹ��� ������� �ʴ´ٴ� ����� �־�� �մϴ�.
	delete p;
}

int main()
{
	foo();
}