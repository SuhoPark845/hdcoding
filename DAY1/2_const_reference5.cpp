#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// �Ʒ� �ڵ�� C++98 �������� ���� �ڵ� �Դϴ�.
	void setName(const std::string& s) { name = s;	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);
	p.setName( std::move(s2) ); // ?? 

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


}

