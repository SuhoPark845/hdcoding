#include <iostream>
#include <vector>

// ��������� å������ ��� Ŭ���� ����
class RefCount
{
	int ref = 0;
public:
	void AddRef() { ++ref; }
	void Release() { if (--ref == 0) delete this; }
};
// Truck �� ���� ��� ����� �����ϰ� �ʹ�.
class Truck : public RefCount 
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	Truck* p = new Truck;
	p->AddRef();
	p->Release();
}