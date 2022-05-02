#include <iostream>
#include <vector>

template<typename T>
class RefCount
{
	mutable int ref = 0;
public:
	// 핵심 : 객체의 수명을 관리하는 아래 2개의 멤버 함수는 
	//		반드시 상수 멤버 함수가 되어야 합니다.
	//		상수 객체도 "수명 관리"는 할수 있어야 합니다.

	void AddRef() const { ++ref; }

//	void Release()		 // void Release( RefCount* this)
	void Release() const // void Release( const RefCount* this)
	{

		if (--ref == 0)
			//	delete this;
//			delete static_cast<T*>(this); // const RefCount* => Truck* 인데
									// static_cast 는 const 제거 못합니다.
//			delete static_cast<T*>(const_cast<RefCount*>(this)); // ok

			delete static_cast<const T*>(this); 
					// const RefCount* => const Truck*
	}
	~RefCount() {}
};
// github.com/aosp-mirror
// platform system core 에서

// libutils/include/utils/LightRefBase.h 찾아 보세요




class Truck : public RefCount< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	const Truck* p = new Truck;

	p->AddRef(); // 이코드가 되야 할까요? 안되야 할까요 ?
	p->Release();
}