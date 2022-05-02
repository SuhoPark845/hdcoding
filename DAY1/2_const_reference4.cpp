#include <iostream>
#include <string>

int main()
{
	std::string s1 = "abcdefghijklmnopqrstu";
	std::string s2 = "abcdefghijklmnopqrstu";

	std::string s3 = s1;			// s1 의 문자열을 s3가 복사
	std::string s4 = std::move(s2); // s2 의 문자열을 s4 빼앗아감(이동)

	std::cout << s1 << std::endl; // "abcdefghijklmnopqrstu"
	std::cout << s2 << std::endl; // ""


	const std::string s5 = "abcdefghijklmnopqrstu";
	std::string s6 = std::move(s5); // 복사 ? move 
								// 상수객체는 move 될수 없습니다.
								// 이 코드는 복사 입니다.
	std::cout << s5 << std::endl; // "abcdefghijklmnopqrstu"
}