#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;

	// mutable ��� ����Ÿ : ��� �Լ� �ȿ����� ��� ����Ÿ�� 
	//						�����Ҽ� �ְ��ϱ� ���� ���
	mutable char cache[32];
	mutable bool cache_valid = false;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// �Ʒ� �Լ��� �и� x, y �� ���� �������� ������ "����Լ�"�� �Ǿ�� �մϴ�.
	const char* toString() const 
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}

