#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// 아래 코드는 C++98 시절에는 좋은 코드 입니다.
	// 하지만 C++11 이후에는 "move"를 지원하지 못하는 "old style code" 입니다.
//	void setName(const std::string& s) { name = s;	}
	void setName(const std::string& s) { name = std::move(s); }
									// 이렇게도 move는 안됩니다.
									// const 는 move 될수 없으므로
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

