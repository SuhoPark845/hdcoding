#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// ���� �ӽð�ü�� ����ϴ°� ?
void foo(const Point& pt) {}

int main()
{
//	Point pt(1, 2);
//	foo(pt);

	// �ٽ� 1. �Լ� ���ڷθ� ����ϴ� ��ü�� �ʿ� �ϴٸ�
	//		  �ӽð�ü ���·� �����ϴ� ���� ȿ�����̴�.
	foo( Point(1, 2) );

	std::cout << "-----" << std::endl;
}





