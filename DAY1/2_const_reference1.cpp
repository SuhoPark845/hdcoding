// F16 ~ F20  ( 10 page ~)

#include <iostream>

struct Rect
{
	int left, top, right, bottom;
};

// call by value �� ������
// 1. ���纻 ����(�޸� �������)
// 2. ���������, �Ҹ��� ȣ��, ��, 2���� �Լ� ȣ�� �߻�
//void fn(Rect rc)

// �׷���, const reference �� �����ϴ�.
// ���� : ���纻 ����, �Լ� ȣ�⵵ ����, temporary�� ������ �ִ�.
// const �� ������ temporary �� ������ �����ϴ�. �� ���̼���..
void fn(const Rect& rc)
{
}

int main()
{
	Rect rc;
	fn(rc);
}
