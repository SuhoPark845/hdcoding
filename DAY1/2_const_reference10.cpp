// 2_const_reference9
#include <string>
#include <iostream>
#include <string_view>

void* operator new(std::size_t sz)
{
	printf("called new %d bytes\n", sz);
	return malloc(sz);
}

// �Ʒ� �ּ� �ٲ� ���鼭 ���� new ȣ��Ǵ� �� ���� ������.
void print_msg(const std::string& msg)
//void print_msg(std::string_view msg) 
{
	std::cout << msg << std::endl;
}

int main()
{
	print_msg("���ڸ� �̷��� �������� ������ ������");
}

