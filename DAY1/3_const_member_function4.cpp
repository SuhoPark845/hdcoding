#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}
	~vector() { delete[] buff; }

	// [] ������ ������ : ��ü�� �迭 ó�� ��밡���ϰ� �Ѵ�.
	//					�Ϲ������� ���� Ÿ���� ������ �ؾ� �մϴ�.
	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	vector<int> v1(10);

	v1[0] = 0;    // v.operator[](0) = 0;

	int a = v1[0];
}