#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// ���ڰ� 2�� �̻��� �����ڳ� setter�� move�� �����Ϸ��� 
	// �Ʒ� ó�� ���ø����� �մϴ�.
	// T&& �� ����� 
	// People p1(s1)            => People(std::string& ) ����� ������ ����
	// People p1(std::move(s1)) => People(std::string&&) ����� ������ ����
	template<typename T1, typename T2> 
	People(T1&& name, T2&& addr) 
//		: name(name), addr(addr)    // �� �ڵ�� ������ ����
//		: name(std::move(name)), addr(std::move(addr)) // �� �ڵ�� ������ move
		: name(std::forward<T1>(name)), addr(std::forward<T2>(addr))
	{
		// std::forward<T1>(name) : �� ������ ȣ���
		//							std::move(s1)�� ����ؼ� ���ڸ� ����������
		//							move �� �̵��ϰ�, �׷��� ������ ����
	}
	// ���� �� �ڵ尡 6���� �����ϰ�, 4���� �ʿ��� �����ڸ� �ڵ��������ְ� �˴ϴ�.
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2);
	People p2(std::move(s1), std::move(s2));
}