// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// 동기화 자원을 사용시 "lock/unlock" 을 직접 사용하면
// deadlock 의 위험이 있습니다.

// 반드시 "생성자/소멸자"를 사용해서 관리해야 합니다.

// RAII : Resource Acquision Is Initialization
//		 자원을 획득하는 것은 (자원 관리객체-lock_guard) 가 초기화 될때 이다.
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

// 아래 함수를 2개의 스레드가 실행한다고 생각해 보세요.
void foo()
{
	{
		std::lock_guard<std::mutex> g(m);
		//lock_guard<std::mutex> g(m); // 생성자에서 lock 수행

		// 위 코드는 
		// 아래 코드들에서 어떤 일이 발생(예외, return등)해도 m.unlock()을 보장한다는
		// 의미가 있습니다.

	//	m.lock();
		shared_data = 100;
		// 예외 발생..
	//	m.unlock();
	}

	//...
}


int main()
{

}