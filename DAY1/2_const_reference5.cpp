#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// 아래 코드는 C++98 시절에는 좋은 코드 입니다.
	// 하지만 C++11 이후에는 "move"를 지원하지 못하는 "old style code" 입니다.
//	void setName(const std::string& s) { name = s;	}
//	void setName(const std::string& s) { name = std::move(s); }
									// 이렇게도 move는 안됩니다.
									// const 는 move 될수 없으므로

	// std::move(s2) 의 결과는 rvalue reference(&&) 로 나오게 됩니다.
	// 따라서, 아래 처럼 오버로딩 가능합니다.
	// 아래 코드가 C++11 에서의 최상의 setter 입니다.
	void setName(const std::string& s) { name = s; }
	void setName(std::string&& s)      { name = std::move(s); }
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);
	p.setName( std::move(s2) ); // 1. && 버전이 있다면 사용
								// 2. 없다면 const & 에도 전달 가능
								//    단, move 되지는 않는다.
								// 즉, 에러는 아니지만 성능향상을 볼수는없다

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


}

