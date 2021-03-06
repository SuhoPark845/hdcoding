// 2_const_reference9
#include <string>
#include <iostream>
#include <string_view>
// setter 등을 만들때만 move를 고려하면 됩니다.
// 단지, 함수 인자로만 사용할때는 move 고려할 필요 없습니다.


// 아래 같은 함수는 move 지원 버전을 생각할필요는 없습니다.
// "내부적으로 전달받은 문자열을 보관하는 것은 아니므로..."
/*
void print_msg(const std::string& msg)
{
	std::cout << msg << std::endl;
}
*/
// C++17 부터는 위 코드 보다 아래 코드가 좋습니다.
void print_msg(std::string_view msg) // 참조가 아닌 value 입니다.
{
	std::cout << msg << std::endl;
}
int main()
{
	std::string s = "sldjfsdlkfsdfsdkfjlsd";
	print_msg(s);

	print_msg("인자를 이렇게 보낼때를 생각해 보세요");




	// 참고. string_view 개념
	std::string      s2 = s; // s2가 s의 문자열을 복사해서 사용합니다.
	std::string_view sv = s; // sv는 s의 문자열을 같이 사용합니다
//	sv[0] = 'A'; // error. sv 는 읽기만 됩니다
}