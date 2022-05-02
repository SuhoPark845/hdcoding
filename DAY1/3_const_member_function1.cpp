// Con.1 : By default, make objects immutable
// Con.2 : By default, make member functions const   ===>> �ʹ��� �߿��մϴ�.
//													�� ���Ѿ� �մϴ�.
// Con.3 : By default, pass pointersand references to consts

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// �ٽ� : ��� ��ü�� ��� ��� �Լ��� ȣ���Ҽ� �ֽ��ϴ�.
	//		 ��� ����Ÿ�� �������� ���� ��� ����Լ��� �ݵ�� ��� ����Լ���
	//	     �ؾ� �մϴ�.
	void print() const 
	{
//		x = 10; // error. ��� ��� �Լ��� ��� ����� ��� ��� �˴ϴ�.

		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
	const Point pt(1, 2); // �� ��쿡 �Ʒ� 3���� ������ ������.

	pt.x = 10;		// error. x�� public ������ "���" �̹Ƿ�	
	pt.set(10, 20);	// error. 
	pt.print();		// ??
}


