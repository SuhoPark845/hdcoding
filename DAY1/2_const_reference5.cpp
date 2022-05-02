#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// �Ʒ� �ڵ�� C++98 �������� ���� �ڵ� �Դϴ�.
	// ������ C++11 ���Ŀ��� "move"�� �������� ���ϴ� "old style code" �Դϴ�.
//	void setName(const std::string& s) { name = s;	}
//	void setName(const std::string& s) { name = std::move(s); }
									// �̷��Ե� move�� �ȵ˴ϴ�.
									// const �� move �ɼ� �����Ƿ�

	// std::move(s2) �� ����� rvalue reference(&&) �� ������ �˴ϴ�.
	// ����, �Ʒ� ó�� �����ε� �����մϴ�.
	// �Ʒ� �ڵ尡 C++11 ������ �ֻ��� setter �Դϴ�.
	void setName(const std::string& s) { name = s; }
	void setName(std::string&& s)      { name = std::move(s); }
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);
	p.setName( std::move(s2) ); // 1. && ������ �ִٸ� ���
								// 2. ���ٸ� const & ���� ���� ����
								//    ��, move ������ �ʴ´�.
								// ��, ������ �ƴ����� ��������� �����¾���

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


}

