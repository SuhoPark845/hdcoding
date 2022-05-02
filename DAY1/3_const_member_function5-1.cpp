#include <iostream>
#include <vector>

class Car
{
	int speed;
	int ref = 0;
public:
	~Car() { std::cout << "~Car" << std::endl; }

	void AddRef()  { ++ref; }
	void Release() { if (--ref == 0) delete this; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();
	Car* p2 = p1; // ������ ���� �� ���� ��� ����
	p2->AddRef();

	// ������ ����Ŀ��� ���� ������ ���� ���� ��� ����
	p2->Release();
	p1->Release();
}