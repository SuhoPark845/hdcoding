// 2_const_reference8
#include <iostream>
#include <string>

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

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);
	p.setName(std::move(s2)); 

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


}

