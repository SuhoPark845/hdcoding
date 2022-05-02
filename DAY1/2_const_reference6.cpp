#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// 아래 생성자도 C++98 에서는 아주 좋은 코드 입니다.
	// 그런데, move 를 지원하지 못하는 코드 입니다.
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
	// 결론 인자가 2개인 setter(또는 생성자)를 move를 지원하게 하려면 
	// 위 처럼 4개를 만들어야 합니다.
	// 인자가 3개라면 "8" 개 필요, 4개라면=> 16개
	// ==> 그래서 forwarding reference 라는 기술의 템플릿을 사용하게 됩니다.
	// ==> "코드가 좀 복잡해 집니다."
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