#include <vector>
#include <deque>
#include <list>
#include <iostream>

template<typename T, typename C = std::deque<T> > 
class stack 
{
	C c;
//	C* c; // object adapter
public:
	constexpr void push(const T& a) { c.push_back(a); }
	constexpr void pop()		    { c.pop_back(); 	}
	constexpr T&   top()            { return c.back(); }
};
#include <stack>
int main()
{
	stack<int, std::vector<int>> s1;
	stack<int, std::list<int>> s2;
	stack<int> s;
	s.push(10); // 인라인화가 이루어진다면 s.c.push_back(a) 가 되어 마치 stack은 없는 것처럼 작동하게 된다.
	s.push(20); // 기계어 코드에는 stack과 관련된 코드들은 없는 것 처럼 받아들여진다.
}
