#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}
	~vector() { delete[] buff; }

	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	vector<int> v1(10);
	const vector<int> v2(10);

	int n = 0;

	// ������ ������ ���;� �ϴ� �ڵ带 ��� ������
	v1[0] = 0;    
	n     = v1[0];

	v2[0] = 0;
	n     = v2[0];

}