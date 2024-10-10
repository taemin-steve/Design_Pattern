#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> s = {1,2,3,4,3,2,1};

	auto first = s.begin();
	auto last  = s.end();

	auto ret = std::find(first, last, 3); // first 를 ++ 하면서 이동중이다.
}

// 거구로 만드는 반복자를 새로 만들면 >> list, deque도 다 해줘야한다.
