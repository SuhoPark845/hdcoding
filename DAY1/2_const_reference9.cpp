// 2_const_reference9
#include <string>
#include <iostream>

// setter ���� ���鶧�� move�� ����ϸ� �˴ϴ�.
// ����, �Լ� ���ڷθ� ����Ҷ��� move ����� �ʿ� �����ϴ�.

void print_msg(std::string msg)
{
	std::cout << msg << std::endl;
}
int main()
{
	std::string s = "sldjfsdlkfsdfsdkfjlsd";
	print_msg(s);
}