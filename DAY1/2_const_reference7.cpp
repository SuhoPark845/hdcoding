#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// 인자가 2개 이상인 생성자나 setter를 move를 지원하려면 
	// 아래 처럼 템플릿으로 합니다.
	// T&& 로 만들면 
	// People p1(s1)            => People(std::string& ) 모양의 생성자 생성
	// People p1(std::move(s1)) => People(std::string&&) 모양의 생성자 생성
	template<typename T1, typename T2> 
	People(T1&& name, T2&& addr) 
//		: name(name), addr(addr)    // 이 코드는 무조건 복사
//		: name(std::move(name)), addr(std::move(addr)) // 이 코드는 무조건 move
		: name(std::forward<T1>(name)), addr(std::forward<T2>(addr))
	{
		// std::forward<T1>(name) : 이 생성자 호출시
		//							std::move(s1)를 사용해서 인자를 전달했으면
		//							move 로 이동하고, 그렇제 않으면 복사
	}
	// 이제 이 코드가 6번과 동일하게, 4개의 필요한 생성자를 자동생성해주게 됩니다.
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2);
	People p2(std::move(s1), std::move(s2));
}