#include <iostream>
#include <vector>

template<typename T>
class RefCount
{
	mutable int ref = 0;
public:
	// �ٽ� : ��ü�� ������ �����ϴ� �Ʒ� 2���� ��� �Լ��� 
	//		�ݵ�� ��� ��� �Լ��� �Ǿ�� �մϴ�.
	//		��� ��ü�� "���� ����"�� �Ҽ� �־�� �մϴ�.

	void AddRef() const { ++ref; }

	void Release() const // void Release( RefCount* this)
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
	const Truck* p = new Truck;

	p->AddRef(); // ���ڵ尡 �Ǿ� �ұ��? �ȵǾ� �ұ�� ?
	p->Release();
}