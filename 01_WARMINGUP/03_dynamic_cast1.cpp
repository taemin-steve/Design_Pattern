#include <iostream>

class Animal
{
public:
//	virtual ~Animal() {}
};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
//	Animal* pa = new Dog;
	Animal* pa = new Cat;

//	Dog* pd = pa; // error 명시적으로 캐스팅을 진행해야 한다. 
	Dog* pd = static_cast<Dog*>(pa); //static_cast는 런타임에 확인하기 때문에 실제로 잘못되었는지 확인이 어려움
	// Dog* pd = dynamic_cast<Dog*>(pa); // 다이나믹 케스트

	//std::println("{}", reinterpret_cast<void*>(pd));

	std::cout << reinterpret_cast<void*>(pd) << std::endl;

}

// Static Cast의 경우 컴파일 시간 캐스팅으로, 실행시간에 오버헤드가 없다. 단, 컴파일 시간에는 메모리에 대한 조사가 불가능하여 잘못된 DOwnCasting이 될 수 있음.
// Dynamic Cast >> 실행시간 오버헤드가 존재하며, 실제로 잘못된 다운케스팅이 되면 0값을 반환한다. 
// 가상함수 테이블을 활용하기 떄문에 가상함수가 있어야 한다. 