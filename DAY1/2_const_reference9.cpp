// 2_const_reference9
#include <string>
#include <iostream>
#include <string_view>
// setter ���� ���鶧�� move�� ����ϸ� �˴ϴ�.
// ����, �Լ� ���ڷθ� ����Ҷ��� move ����� �ʿ� �����ϴ�.

// �Ʒ� ���� �Լ��� move ���� ������ �������ʿ�� �����ϴ�.
// "���������� ���޹��� ���ڿ��� �����ϴ� ���� �ƴϹǷ�..."
/*
void print_msg(const std::string& msg)
{
	std::cout << msg << std::endl;
}
*/
// C++17 ���ʹ� �� �ڵ� ���� �Ʒ� �ڵ尡 �����ϴ�.
void print_msg(std::string_view msg) // ������ �ƴ� value �Դϴ�.
{
	std::cout << msg << std::endl;
}


int main()
{
	std::string s = "sldjfsdlkfsdfsdkfjlsd";
	print_msg(s);
}