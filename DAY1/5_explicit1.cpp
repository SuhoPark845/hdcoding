
// C46.인자가 한개인 생성자는 explicit 로 하는 것이 좋다.

class Vector
{
public:
	// explicit 생성자 : direct initialization 만 가능하고
	//					copy initialization 을 사용할수 없다.
	// 이제 main 함수의 3곳이 에러 입니다.
	explicit Vector(int sz) {}
};

// 함수의 인자 전달은 "copy initialization" 이 되는 코드 입니다.
void fn(Vector v) {} // Vector v = 10

int main()
{
	// 인자가 int 한개인 생성자가 있다면 아래 처럼 4가지 형태로 객체 생성이
	// 가능합니다.
	Vector v1(10);		// C++98	direct initialization
	Vector v2 = 10;		// C++98	copy initialization

	Vector v3{ 10 };	// C++11	direct initialization
	Vector v4 = { 10 };	// C++11	copy initialization

	fn(10); // 잘 생각해 보세요.
}