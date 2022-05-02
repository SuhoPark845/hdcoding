class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	// C++11 이후에는 인자가 없거나, 여러개 있어도 explicit를 붙일수 있습니다.
	explicit Point() = default;

	explicit Point(int x, int y) : x{ x }, y{ y } {}
};
void fn(Point pt) {} 

int main()
{
	// C++11 부터는 인자가 2개 있는 것도 아래 처럼 가능합니다.
	Point p1{ 1,2 };
	Point p2 = { 1,2 }; // ok  explicit 라면 에러

	Point p3{};    // ok
	Point p4 = {}; // ok  explicit 라면 에러

	fn( {} ); // ok . explicit 라면 에러
}


