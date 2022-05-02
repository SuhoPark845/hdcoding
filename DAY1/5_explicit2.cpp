class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	// C++11 ���Ŀ��� ���ڰ� ���ų�, ������ �־ explicit�� ���ϼ� �ֽ��ϴ�.
	explicit Point() = default;

	explicit Point(int x, int y) : x{ x }, y{ y } {}
};
void fn(Point pt) {} 

int main()
{
	// C++11 ���ʹ� ���ڰ� 2�� �ִ� �͵� �Ʒ� ó�� �����մϴ�.
	Point p1{ 1,2 };
	Point p2 = { 1,2 }; // ok  explicit ��� ����

	Point p3{};    // ok
	Point p4 = {}; // ok  explicit ��� ����

	fn( {} ); // ok . explicit ��� ����
}


