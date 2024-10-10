#include <vector>
#include <deque>
#include <list>
#include <iostream>

template<typename T> 
class stack : public std::list<T>
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
	//가능하지만, 필요없는 push_front같은 함수들도 보인다! //stack에서는 없는 기능
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

//	s.push_front(100); // ??
}

//기존 sequence container에 이름만 살짝 변경해서  stack처럼 보이게 하자!
