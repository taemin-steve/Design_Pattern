#include <vector>
#include <deque>
#include <list>
#include <iostream>

template<typename T> // private 상속을 한다면 재정의할 기회가 있음!!!! 이렇게 하면 깔끔하지만, 재정의는 불가능.
class stack 
{
	std::list<T> c;
public:
	void push(const T& a) 
	{ 
		c.push_back(a); 
	}
	void pop()			  
	{ 
		c.pop_back(); 
	}
	T&   top()            
	{ 
		return c.back(); 
	}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

//	s.push_front(100); // error. 
						// 함수 없음.
}
