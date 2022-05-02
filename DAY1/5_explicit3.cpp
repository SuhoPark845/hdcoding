#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

struct adopt_lock_t 
{
	// 컴파일러가 제공하는 "디폴트 생성자"는 explicit 가 아닙니다.
	// explicit 로 하기 위해 사용자가 직접 생성자를 제공합니다.
//	explicit adopt_lock_t() {} // 나쁜 코드

	explicit adopt_lock_t() = default; // 좋은 코드 
};
adopt_lock_t adopt_lock;

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }

	lock_guard(T& m, adopt_lock_t) : mtx(m) {  }

	~lock_guard() { mtx.unlock(); }
};
void foo()
{
	if (m.try_lock())
	{
		lock_guard<std::mutex> g1(m, adopt_lock); // ok
	//	lock_guard<std::mutex> g2(m, {}); // 되게 할까요 안되게 할까요 ?

		shared_data = 100;
	}
}


int main()
{

}