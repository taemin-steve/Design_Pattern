#include <iostream>

class Base
{
public:
	// 핵심 : Base에 디폴트 생성자가 없음.
	Base(int a){std::cout << "Base(int)" << std::endl;}
};
class Derived : public Base
{
public:		
//	Derived() { }     // Derived() : Base(){ }
//	Derived(int a) { }// Derived(int a) : Base() { }

	Derived()      : Base(0) { }
	Derived(int a) : Base(a) { }
};
int main()
{
	Derived d;
}

// 기본 생성자가 부모클래스에서 정의되지 않았다면, 오류가 발생 
// 이를 막기 위해서 명시적으로 부모 클래스의 생성자를 호출할 수 있음. 