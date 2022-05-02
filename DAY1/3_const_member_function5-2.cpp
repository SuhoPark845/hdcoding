#include <iostream>
#include <vector>

// ��������� å������ ��� Ŭ���� ����
class RefCount
{
	int ref = 0;
public:
	void AddRef() { ++ref; }

	void Release()  // void Release( RefCount* this) ó���Ǵ°�
	{				// ��, this�� ���� RefCount* Ÿ�� �Դϴ�.
		if (--ref == 0) 
			delete this; 
	}

	// ��� Ŭ���� �Ҹ��ڴ� �ݵ�� �����Լ��� �Ǿ�� �մϴ�.
	virtual ~RefCount() {}
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