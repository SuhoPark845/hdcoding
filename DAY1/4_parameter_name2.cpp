#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// �Լ� �����ε��� ���ڷθ� Ȱ���ϱ� ���� 
// empty class ���� => 10������ ���� C++���迡�� �����ϴ� ���
// empty class : ��� ����� ���� Ŭ����
//				 sizeof(empty class) �� �׻� 1�Դϴ�. (ǥ�ع����� ����)
//				�ƹ� ����� ������ �ϳ��� ������ Ÿ���̹Ƿ� 
//				�Լ� ���ڷ� ��밡���մϴ�. (�ַ� �Լ� �����ε�����λ��)
struct adopt_lock_t {};

adopt_lock_t adopt_lock;


template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m)                : mtx(m) { mtx.lock(); }

	// �Ʒ� �ڵ忡�� 2��° ������ �ǵ��� ���� ���� ������ �ƴ�
	// �Լ� �����ε��� ���� ���� �Դϴ�.
	// �̷� ���ڴ� "�Ķ���� �̸�"�� ���� ������..
	// �����Ϸ� ����ȭ�� ���� �� �˴ϴ�.
	lock_guard(T& m, adopt_lock_t ) : mtx(m) {  }

	~lock_guard() { mtx.unlock(); }
};
void foo()
{
//	std::lock_guard<std::mutex> g(m); // �����ڿ��� ������ lock

	if (m.try_lock())
	{
		// �̹� mutex �� lock �� ȹ���ߴ�.
		// �׷���, unlock �� lock_guard�� �����ϰ� �ʹ�.
		//lock_guard<std::mutex> g(m, adopt_lock);
		std::lock_guard<std::mutex> g(m, std::adopt_lock);

		shared_data = 100;
	}
}


int main()
{

}