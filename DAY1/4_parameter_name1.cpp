// F9. ������ ���� �Ķ���ʹ� �̸��� �־�� �ȵȴ�. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// ����ȭ �ڿ��� ���� "lock/unlock" �� ���� ����ϸ�
// deadlock �� ������ �ֽ��ϴ�.

// �ݵ�� "������/�Ҹ���"�� ����ؼ� �����ؾ� �մϴ�.

// RAII : Resource Acquision Is Initialization
//		 �ڿ��� ȹ���ϴ� ���� (�ڿ� ������ü-lock_guard) �� �ʱ�ȭ �ɶ� �̴�.
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

// �Ʒ� �Լ��� 2���� �����尡 �����Ѵٰ� ������ ������.
void foo()
{
	{
		std::lock_guard<std::mutex> g(m);
		//lock_guard<std::mutex> g(m); // �����ڿ��� lock ����

		// �� �ڵ�� 
		// �Ʒ� �ڵ�鿡�� � ���� �߻�(����, return��)�ص� m.unlock()�� �����Ѵٴ�
		// �ǹ̰� �ֽ��ϴ�.

	//	m.lock();
		shared_data = 100;
		// ���� �߻�..
	//	m.unlock();
	}

	//...
}


int main()
{

}