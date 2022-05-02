// 5_explicit1-1
#include <vector>
#include <string>

void f1(std::vector<int> v) {}
void f2(std::string s)      {}

int main()
{
	std::vector<int> v1(10); // ok
	std::string s1("abcd");  // ok

	// 아래 2줄의 코드가 되는게 좋은지 안되는게 좋은지 판단해 보세요
	f1(10); 
	f2("abcd");
}