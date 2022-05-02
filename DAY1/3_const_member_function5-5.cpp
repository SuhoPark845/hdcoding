#include <iostream>
#include <vector>

template<typename T>
class RefCount
{
	mutable int ref = 0;
public:
	void AddRef() const { ++ref; }
	void Release() const 
	{

		if (--ref == 0)
			delete static_cast<const T*>(this);

	}
	~RefCount() {}
};



class Truck : public RefCount< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
	void Go() { std::cout << "Truck Go" << std::endl; }
};
// AddRef �� Release�� �ڵ����� ȣ���ϴ� ������ ����(����Ʈ������)
// �� �����ϸ� �� �մϴ�.
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p)         { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	
	~AutoPtr() { if (obj) obj->Release(); }

	// ������ ó�� ���̱� ���� ������ ������
	T* operator->() { return obj; }
	T& operator*() { return *obj; } // �ٽ�.. "T&" �� ��ȯ�ϴ� ������
									// ��Ȯ�� �Ƽž� �մϴ�.
};
int main()
{
	AutoPtr<Truck> p1 = new Truck; // p1( new Truck)
	AutoPtr<Truck> p2 = p1;

	// p1�� ��ü���� -> �� * �����ڰ� ������ �Ǿ��⶧����
	// raw pointer �� �����ϰ� ��밡��
	p1->Go();

	(*p1).Go(); 
}