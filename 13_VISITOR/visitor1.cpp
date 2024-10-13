#include <iostream>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// 방법 1. 직접 연산
	for (auto& e : s)
	{
		e *= 2;
	}

	// 방법 2. 방문자 패턴 사용
	TwiceVisitor<int> tv; // 요소 한개의 값을 2배로 하는
						  // 방문자
	s.accept(&tv);

	ShowVisitor<int> sv; // 요소 한개를 출력하는 방문자
	s.accept(&sv);	
}

//어떻게 모든 요소를 방문하게 할 것인가??
// 방문자의 인터페이스가 필요함 
// 방문 대상 (list, vector)등은 accept() 함수가 필요.

