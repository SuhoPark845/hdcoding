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

	// 다음중 에러가 나와야 하는 코드를 골라 보세요
	v1[0] = 0;    
	n     = v1[0];

	v2[0] = 0;
	n     = v2[0];

}