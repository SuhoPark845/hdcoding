#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// �Ʒ� �����ڵ� C++98 ������ ���� ���� �ڵ� �Դϴ�.
	// �׷���, move �� �������� ���ϴ� �ڵ� �Դϴ�.
	People(const std::string& name, const std::string& addr)
		: name(name), addr(addr)
	{
	}
	People(std::string&& name, std::string&& addr)
		: name(std::move(name) ), addr(std::move(addr) )
	{
	}
	People(std::string&& name, const std::string& addr)
		: name(std::move(name)), addr(addr)
	{
	}
	People(const std::string& name, std::string&& addr)
		: name(name), addr(std::move(addr))
	{
	}
	// ��� ���ڰ� 2���� setter(�Ǵ� ������)�� move�� �����ϰ� �Ϸ��� 
	// �� ó�� 4���� ������ �մϴ�.
	// ���ڰ� 3����� "8" �� �ʿ�, 4�����=> 16��
	// ==> �׷��� forwarding reference ��� ����� ���ø��� ����ϰ� �˴ϴ�.
	// ==> "�ڵ尡 �� ������ ���ϴ�."
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2);
//	People p2(std::move(s1), std::move(s2)); 
//	People p2(std::move(s1), s2);
	People p2(s1, std::move(s2));
}