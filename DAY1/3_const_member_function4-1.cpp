#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}
	~vector() { delete[] buff; }
	
	// 동일이름의 "상수 멤버 함수와 비상수 멤버 함수를" 동시에 제공할수 있습니다.
	// 비상수 객체 ==> 비상수 멤버 함수
	// 상수 객체   ==> 상수 멤버 함수를 사용하게 됩니다.
	T& operator[](int idx)             { return buff[idx]; }
	const T& operator[](int idx) const { return buff[idx]; }
};
int main()
{
	vector<int> v1(10);
	const vector<int> v2(10); // 읽기 전용으로 vector를 사용하겠다는것

//	v1.front() = 10; // T& front() {}
//	v2.front() = 10; // error. const T& front() const {} 로 만들게 됩니다.
		
	int n = 0;

	// 다음중 에러가 나와야 하는 코드를 골라 보세요
	v1[0] = 0;		// 1
	n     = v1[0];	// 2

//	v2[0] = 0;		// 3. error 나와야 합니다.
	n     = v2[0];	// 4. ok    되어야 합니다.

}