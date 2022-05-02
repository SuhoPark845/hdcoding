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

//	void Release()		 // void Release( RefCount* this)
	void Release() const // void Release( const RefCount* this)
	{

		if (--ref == 0)
			//	delete this;
//			delete static_cast<T*>(this); // const RefCount* => Truck* �ε�
									// static_cast �� const ���� ���մϴ�.
//			delete static_cast<T*>(const_cast<RefCount*>(this)); // ok

			delete static_cast<const T*>(this); 
					// const RefCount* => const Truck*
	}
	~RefCount() {}
};
// github.com/aosp-mirror
// platform system core ����

// libutils/include/utils/LightRefBase.h ã�� ������




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