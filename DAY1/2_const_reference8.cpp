// 2_const_reference8
#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// move 지원 setter 만들기
	// ===> 인자가 한개인 경우는 방법2 보다, 방법1 이 좋습니다.
	// 방법 1. 2개의 함수
//	void setName(const std::string& s) { name = s; }
//	void setName(std::string&& s)      { name = std::move(s); }

	// 방법 2. 템플릿(forwarding reference)
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

