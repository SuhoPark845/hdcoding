
// 다음중 좋은 코드는 ?
// primitive type 은 const reference 보다 call by value가 좋습니다.
// 
void f1(int n)        {} // good
void f2(const int& n) {} // bad

int main()
{
	int a = 10;
	f1(a);
	f2(a);
}

// 함수 인자를 받는 기본 전략

//					int(primitive)		Rect(user define type)
// 인자값을 수정		f(int&)				f(Rect&)
// 인자값을 읽기만		f(int)				f(const Rect& )