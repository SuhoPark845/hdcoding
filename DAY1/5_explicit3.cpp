#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

struct adopt_lock_t 
{
	// �����Ϸ��� �����ϴ� "����Ʈ ������"�� explicit �� �ƴմϴ�.
	// explicit �� �ϱ� ���� ����ڰ� ���� �����ڸ� �����մϴ�.
//	explicit adopt_lock_t() {} // ���� �ڵ�

	explicit adopt_lock_t() = default; // ���� �ڵ� 
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
	//	lock_guard<std::mutex> g2(m, {}); // �ǰ� �ұ�� �ȵǰ� �ұ�� ?

		shared_data = 100;
	}
}


int main()
{

}