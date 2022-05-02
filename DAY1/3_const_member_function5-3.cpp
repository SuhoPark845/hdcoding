#include <iostream>
#include <vector>

// ��������� å������ ��� Ŭ���� ����

// CRTP : Curiously Recurring Template Pattern

// ��� Ŭ�������� �̷��� ������� �Ļ� Ŭ���� �̸��� ����Ҽ� �ְ� �ϴ� ���

// �Ļ� Ŭ������ ���Ŭ�������� �ڽ��� �̸��� ���ø� ���ڷ� �����ϴ� ���

template<typename T> 
class RefCount
{
	int ref = 0;
public:
	void AddRef() { ++ref; }

	void Release()  // void Release( RefCount* this)
	{				
		if (--ref == 0)
			//	delete this;
			delete static_cast<T*>(this);
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
	Truck* p = new Truck;
	p->AddRef();
	p->Release();
}