
// C46.���ڰ� �Ѱ��� �����ڴ� explicit �� �ϴ� ���� ����.

class Vector
{
public:
	// explicit ������ : direct initialization �� �����ϰ�
	//					copy initialization �� ����Ҽ� ����.
	// ���� main �Լ��� 3���� ���� �Դϴ�.
	explicit Vector(int sz) {}
};

// �Լ��� ���� ������ "copy initialization" �� �Ǵ� �ڵ� �Դϴ�.
void fn(Vector v) {} // Vector v = 10

int main()
{
	// ���ڰ� int �Ѱ��� �����ڰ� �ִٸ� �Ʒ� ó�� 4���� ���·� ��ü ������
	// �����մϴ�.
	Vector v1(10);		// C++98	direct initialization
	Vector v2 = 10;		// C++98	copy initialization

	Vector v3{ 10 };	// C++11	direct initialization
	Vector v4 = { 10 };	// C++11	copy initialization

	fn(10); // �� ������ ������.
}