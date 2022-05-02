#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
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
int main()
{
	std::cout << "------" << std::endl;

	f1().x = 10; // error. f1()�� �ӽð�ü�� ��ȯ �ϴµ�
				 // �ӽð�ü(temporary)�� ��ȣ�� ���ʿ� �ü� ����.

	std::cout << "------" << std::endl;

}



