// ��� ��� �Լ��� "����"�� �ƴ� "�ʼ�" ���� �Դϴ�.

// ��ü�� ���¸� �������� �ʴ� getter( getxxx) �Լ��� �ݵ�� 
// 
// ��� ����Լ��� �ؾ� �մϴ�.

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};

//void foo(Rect r)		// call by value : ���纻�� ���� ��������..
void foo(const Rect& r)
{
	int n = r.getArea(); // ????
}

int main()
{
	Rect r(1, 2, 3, 4);	 // ��� ��ü �ƴ�.
	int n = r.getArea(); // ok. 
	foo(r);
}