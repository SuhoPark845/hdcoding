// 2_const_reference8
#include <iostream>
#include <string>

// move 지원 setter 만드는 방법
// 1. 인자가 한개라면 2개의 아래처럼 setName() 만드세요
// 2. 인자가 2개 이상이면 "template" 으로 만드는 것이 좋습니다.

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
// godbolt.org 에 접속해 보세요 - C++ 코드의 원리를 어셈블리로 확인가능한 사이트
int main()
{
	std::string s1 = "john";
	std::string s2 = "john";
	const std::string s3 = "john";

	People p;
	// template 버전 사용시
	p.setName(s1); // setName(std::string&) 함수 생성
	p.setName(s3); // setName(const std::string&) 함수 생성
	p.setName(std::move(s2)); // setName(std::string&&) 함수 생성

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;


}

