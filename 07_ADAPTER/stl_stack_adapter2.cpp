#include <vector>
#include <deque>
#include <list>
#include <iostream>

template<typename T> 
class stack : private std::list<T> // 상속 받긴 할건데, 다 private 영역으로 해달라!
// >> 구현은 물려받았지만 인터페이스는 물려 받지 않겠다. 대부분의 객체지향에서는 없는 문법이다. private 상속
{
public:
	void push(const T& a) 
	{ 
		std::list<T>::push_back(a); 
	}
	void pop()			  
	{ 
		std::list<T>::pop_back(); 
	}
	T&   top()            
	{ 
		return std::list<T>::back(); 
	}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

//	s.push_front(100); // error. private
}
