
// ������ ���� �ڵ�� ?
// primitive type �� const reference ���� call by value�� �����ϴ�.
// 
void f1(int n)        {} // good
void f2(const int& n) {} // bad

int main()
{
	int a = 10;
	f1(a);
	f2(a);
}

// �Լ� ���ڸ� �޴� �⺻ ����

//					int(primitive)		Rect(user define type)
// ���ڰ��� ����		f(int&)				f(Rect&)
// ���ڰ��� �б⸸		f(int)				f(const Rect& )