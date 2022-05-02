// 상수 멤버 함수는 "선택"이 아닌 "필수" 문법 입니다.

// 객체의 상태를 변경하지 않는 getter( getxxx) 함수는 반드시 
// 
// 상수 멤버함수로 해야 합니다.

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};

//void foo(Rect r)		// call by value : 복사본에 의한 성능저하..
void foo(const Rect& r)
{
	int n = r.getArea(); // ????
}

int main()
{
	Rect r(1, 2, 3, 4);	 // 상수 객체 아님.
	int n = r.getArea(); // ok. 
	foo(r);
}