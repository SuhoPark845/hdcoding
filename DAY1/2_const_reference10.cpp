// 2_const_reference9
#include <string>
#include <iostream>
#include <string_view>

void* operator new(std::size_t sz)
{
	printf("called new %d bytes\n", sz);
	return malloc(sz);
}

// 아래 주석 바꿔 가면서 위에 new 호출되는 것 살펴 보세요.
void print_msg(const std::string& msg)
//void print_msg(std::string_view msg) 
{
	std::cout << msg << std::endl;
}

int main()
{
	print_msg("인자를 이렇게 보낼때를 생각해 보세요");
}

