#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }

	Point(const Point& p) { std::cout << "copy ctor" << std::endl; }
};
//-------------------------------------------

/*
void f1(Point  pt) {} // call by value     : ���纻 ��ü ����
void f2(Point& pt) {} // call by reference : ���纻 ��ü ���� ����

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/

//-----------------------------------

Point pt(1, 2); // �������� 

Point f1() // return by value : ���Ͽ� �ӽð�ü�� �����Ǿ ��ȯ.
{
	return pt;
}
Point& f2() // return by reference : ���Ͽ� �ӽð�ü�� ������ ����
{			//						pt ��ü�� ��ȯ�� �޶�� �ǹ�.
	return pt;
}
int main()
{
	std::cout << "------" << std::endl;

//	f1().x = 10; // error. f1()�� �ӽð�ü�� ��ȯ �ϴµ�
				 // �ӽð�ü(temporary)�� ��ȣ�� ���ʿ� �ü� ����.
//	f1();
	f2().x = 10; // ok.. �ᱹ pt.x = 10 �� �˴ϴ�.

	std::cout << "------" << std::endl;

}



Point& f3() 
{			
	Point p(1, 2);
	return p;   // ������ ������ �ƴ�����, ���� �̷��� �ϸ� �ȵ˴ϴ�.
				// F43(21page) : ���� ���������� ������ �����ͷ� ��ȯ
				//			��������.
}
// �ٽ� 1. value return �� reference return �� ������ �˾� �μ���
//     2. reference return �� ��ü�� �ı� ���� ���� ���(����������)��
//        �� ����ؾ� �մϴ�.
//		  ���������� �ݵ�� value return ���θ� ����ؾ� �մϴ�.