#include "print.h"


class Camera
{
public:
	void take() { std::println("take picture"); }
};

class HDCamera
{
public:
	void take() { std::println("take HD picture"); }
};

class People
{
public:
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); } // 문제 없이 잘 동작하던 시스템에 추가적인 코드 수정이 필요한 상태
	//OCP >> 확장에 대해서는 열려있고, 수정에 대해서는 닫혀있어야 한다. 
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ?
}