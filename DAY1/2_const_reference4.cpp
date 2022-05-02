#include <iostream>
#include <string>

int main()
{
	std::string s1 = "abcdefghijklmnopqrstu";
	std::string s2 = "abcdefghijklmnopqrstu";

	std::string s3 = s1;			// s1 �� ���ڿ��� s3�� ����
	std::string s4 = std::move(s2); // s2 �� ���ڿ��� s4 ���Ѿư�(�̵�)

	std::cout << s1 << std::endl; // "abcdefghijklmnopqrstu"
	std::cout << s2 << std::endl; // ""


	const std::string s5 = "abcdefghijklmnopqrstu";
	std::string s6 = std::move(s5); // ���� ? move 
								// �����ü�� move �ɼ� �����ϴ�.
								// �� �ڵ�� ���� �Դϴ�.
	std::cout << s5 << std::endl; // "abcdefghijklmnopqrstu"
}