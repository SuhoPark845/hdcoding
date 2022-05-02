// 2_const_reference9
#include <string>
#include <iostream>

// setter 등을 만들때만 move를 고려하면 됩니다.
// 단지, 함수 인자로만 사용할때는 move 고려할 필요 없습니다.

void print_msg(std::string msg)
{
	std::cout << msg << std::endl;
}
int main()
{
	std::string s = "sldjfsdlkfsdfsdkfjlsd";
	print_msg(s);
}