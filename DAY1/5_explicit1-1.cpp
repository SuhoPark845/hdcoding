// 5_explicit1-1
#include <vector>
#include <string>

void f1(std::vector<int> v) {}
void f2(std::string s)      {}

int main()
{
	std::vector<int> v1(10); // ok
	std::string s1("abcd");  // ok

	// �Ʒ� 2���� �ڵ尡 �Ǵ°� ������ �ȵǴ°� ������ �Ǵ��� ������
	f1(10); 
	f2("abcd");
}