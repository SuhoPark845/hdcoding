#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}
	~vector() { delete[] buff; }

	// [] 연산자 재정의 : 객체를 배열 처럼 사용가능하게 한다.
	//					일반적으로 리턴 타입을 참조로 해야 합니다.
	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	vector<int> v1(10);

	v1[0] = 0;    // v.operator[](0) = 0;

	int a = v1[0];
}