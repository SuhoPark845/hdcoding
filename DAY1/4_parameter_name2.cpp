#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// 함수 오버로딩의 인자로만 활용하기 위한 
// empty class 설계 => 10여년전 부터 C++업계에서 유행하는 기술
// empty class : 어떠한 멤버도 없는 클래스
//				 sizeof(empty class) 는 항상 1입니다. (표준문서에 정의)
//				아무 멤버도 없지만 하나의 독립된 타입이므로 
//				함수 인자로 사용가능합니다. (주로 함수 오버로딩기술로사용)
struct adopt_lock_t {};

adopt_lock_t adopt_lock;


template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m)                : mtx(m) { mtx.lock(); }

	// 아래 코드에서 2번째 인자의 의도는 실제 인자 전달이 아닌
	// 함수 오버로딩을 위한 인자 입니다.
	// 이런 인자는 "파라미터 이름"을 적지 마세요..
	// 컴파일러 최적화가 좀더 잘 됩니다.
	lock_guard(T& m, adopt_lock_t ) : mtx(m) {  }

	~lock_guard() { mtx.unlock(); }
};
void foo()
{
//	std::lock_guard<std::mutex> g(m); // 생성자에서 무조건 lock

	if (m.try_lock())
	{
		// 이미 mutex 의 lock 을 획득했다.
		// 그런데, unlock 은 lock_guard로 관리하고 싶다.
		//lock_guard<std::mutex> g(m, adopt_lock);
		std::lock_guard<std::mutex> g(m, std::adopt_lock);

		shared_data = 100;
	}
}


int main()
{

}