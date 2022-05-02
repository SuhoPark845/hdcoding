#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// temporary Ư¡
	Point pt(1, 2);
	
	pt.x = 10;				
	Point(1, 2).x = 10; // �ٽ� 1. temporary �� lvalue�� �ɼ� ����.		
						// error.

	Point* p1 = &pt;		 
	Point* p2 = &Point(1, 2);	// error
								// �ٽ� 2. temporary �� �ּҿ����ڷ�
								//		�ּҸ� ���Ҽ� ����.
							
	Point& r1 = pt;			
	Point& r2 = Point(1, 2);	// error
								// �ٽ� 3. temporary �� 
								// non-const reference�� ����ų������.

	const Point& r3 = Point(1, 2);	// ok.. const reference��
								// temporary �� ����ų�� �ִ�.
								// �� ��� temporary �� ������
								// r3�� ����� ������ ���ϴ�.
								// �̸����� ��ü�� �̸��� �ο��Ѱ�
//	r3.x = 10;	// error
				// x�� public ������ const ���� �̹Ƿ�

	// C++11 ������ ����� ���� �ӽð�ü�� ����Ű�� �;����ϴ�
	// move �� perfect forwarding �̶�� ����� ����� ���ؼ�
	Point&& r4 = Point(1, 2); // const ���� temporary�� 
							// ����Ű�� ����
							// rvalue reference ��� �մϴ�.
}







