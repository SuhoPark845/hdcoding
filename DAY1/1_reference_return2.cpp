#include <iostream>

class Counter
{
	int value{ 0 };
public:
	~Counter() { std::cout << "~Counter" << std::endl; }

	// �ٽ� 1. *this �� ��ȯ�ϸ� ��� �Լ� ȣ���� ���������� ��밡���մϴ�(main ����)
	//     2. *this �� ������ ��ȯ �ϸ� �ӽð�ü�� ���� �˴ϴ�.
	//     3. ���, *this �� ��ȯ �Ҷ��� "�ݵ�� ���� ��ȯ"�� ����ؾ� �մϴ�.
	//        => �Ʒ� �Լ��� ����Ǵ� ���� ��ü(c)�� �ı����� �����Ƿ� �����մϴ�
//	Counter increment()
	Counter& increment()
	{
		++value;
		return *this;
	}
	int get() const { return value; }
};

int main()
{
	Counter c;
	c.increment().increment().increment();

	std::cout << c.get() << std::endl; // ????
}