#include "print.h"


// 미리 서로의 규칙을 정해 기존의 코드 수정없이 새로운 것을 추가할 수 있도록한다.
// 규칙 : 모든 카메라는 ICamera 로 부터 파생 되어야 한다.
// 규칙 : 모든 카메라는 ICamera 인터페이스를 구현해야 한다.
//class ICamera
struct ICamera
{	
//public:
	virtual ~ICamera() {} // 가상 소멸자.

	virtual void take() = 0;	
};




class People
{
public:
	void use_camera(ICamera* p) { p->take(); }
};

class Camera : public ICamera
{
public:
	void take() { std::println("take picture"); }
};

class HDCamera : public ICamera
{
public:
	void take() { std::println("take HD picture"); }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::println("take UHD picture"); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ok

	UHDCamera uhc;
	p.use_camera(&uhc); // ok
}

//추상 클래스와 인터페이스 
// 지켜야 하는 규칙만이 존재한다 >> 인터페이스 (상속, 파생이라는 표현보다는 인터페이스를 구현한다고 많이 표현한다.)
// 추가적인 변수가 존재한다 >> 추상 클래스 

// 기반 클래스는 소멸자가 가상이여야 한다.(업케스팅 하는 경우 소멸자가 호출되면 자식 클래스의 변수들은 초기화가 안되어 메모리 누수발생 가능)
// virtual 키워드를 사용하면 동적바인딩이 되어 런타임중에 어떤 함수를 사용할지에 대해서 결정할 수 있음 (실제 타입에 따라)
// Struct로 구현 가능 ( Public을 생략할 수 있다는 장점을 가지고 있음)
// 강한 결합 : 서로의 클래스의 이름을 알고, 호출하고 있음 >> 교체가 불가능하고 확장성 없는 경직된 디자인
// 약한 결함 : 안터페이스를 통해서 규칙만 지킨다면 수정될 필요가 없음. 교체가 가능하고 확장성이 있는 유연한 디자인.