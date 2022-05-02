#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// ���� �ӽð�ü�� ����ϴ°� ?

// �ٽ� 3. const & �� ����(Ư¡)
// 1. �ӽð�ü�� ������ �ִ�.
// 2. pt �� �б⸸ �ϰڴٴ°��� ��Ȯ�� �Ҽ� �ִ�.(�Ǽ� ����)

void foo(const Point& pt) {}

// �ٽ� 2. �Ʒ�ó�� ����� ���ڷ� "�ӽð�ü"�� �����Ҽ� ���� �˴ϴ�.
//void foo(Point& pt) {} // Point& pt = Point(1,2)

int main()
{
//	Point pt(1, 2);
//	foo(pt);

	// �ٽ� 1. �Լ� ���ڷθ� ����ϴ� ��ü�� �ʿ� �ϴٸ�
	//		  �ӽð�ü ���·� �����ϴ� ���� ȿ�����̴�.
	foo( Point(1, 2) );

	std::cout << "-----" << std::endl;
}





