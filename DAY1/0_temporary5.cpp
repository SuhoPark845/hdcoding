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

	// �Ʒ� 2���� �������� ����� ?
//	std::cout << static_cast<Base>(d).value << std::endl; // 10
//	std::cout << static_cast<Base&>(d).value << std::endl; // 10

	static_cast<Base>(d).value = 30; // error. �ӽð�ü��
									 // ��ȣ�� ���ʿ� �ü� ����.
	static_cast<Base&>(d).value = 30;// ok.. 

}
// ���, �ӽð�ü(temporary)��
// 1. �����ڰ� �ǵ������� ���鶧�� �ְ�
//    ==> �Լ� ���ڷ� �����Ҷ�      ex) f( Point(1,2))

// 2. �����ڰ� �ۼ��� �ڵ� ������ �����ɼ��� �ִ�.
//   ==> �Լ��� return by value �� ����Ҷ�
//   ==> value type ���� ĳ���� �Ҷ�!!

// �ӽð�ü�� ���� �����Ǵ��� �˾ƾ�, ���׸� ����, ������ ����ų�� �ֽ��ϴ�.







