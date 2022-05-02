#include <iostream>

class Counter
{
	int value{ 0 };
public:
	~Counter() { std::cout << "~Counter" << std::endl; }

	// 핵심 1. *this 를 반환하면 멤버 함수 호출을 연속적으로 사용가능합니다(main 참고)
	//     2. *this 를 값으로 반환 하면 임시객체가 생성 됩니다.
	//     3. 결론, *this 를 반환 할때는 "반드시 참조 반환"을 사용해야 합니다.
	//        => 아래 함수가 실행되는 동안 객체(c)가 파괴되지 않으므로 안전합니다
//	Counter increment()
	Counter& increment()
	{
		++value;
		return *this;
	}
	int get() const { return value; }
};

int main()
{
	Counter c;
	c.increment().increment().increment();

	std::cout << c.get() << std::endl; // ????
}