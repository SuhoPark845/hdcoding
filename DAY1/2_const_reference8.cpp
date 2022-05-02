// 2_const_reference8
#include <iostream>
#include <string>

// move ���� setter ����� ���
// 1. ���ڰ� �Ѱ���� 2���� �Ʒ�ó�� setName() ���弼��
// 2. ���ڰ� 2�� �̻��̸� "template" ���� ����� ���� �����ϴ�.

class People
{
	std::string name;
public:
	// move ���� setter �����
	// ===> ���ڰ� �Ѱ��� ���� ���2 ����, ���1 �� �����ϴ�.
	// ��� 1. 2���� �Լ�
//	void setName(const std::string& s) { name = s; }
//	void setName(std::string&& s)      { name = std::move(s); }

	// ��� 2. ���ø�(forwarding reference)
	template<typename T>
	void setName(T&& a)
	{
		name = std::forward<T>(a);
	}
};
// godbolt.org �� ������ ������ - C++ �ڵ��� ������ ������� Ȯ�ΰ����� ����Ʈ
int main()
{
	std::string s1 = "john";
	std::string s2 = "john";
	const std::string s3 = "john";

	People p;
	// template ���� ����
	p.setName(s1); // setName(std::string&) �Լ� ����
	p.setName(s3); // setName(const std::string&) �Լ� ����
	p.setName(std::move(s2)); // setName(std::string&&) �Լ� ����

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


}

