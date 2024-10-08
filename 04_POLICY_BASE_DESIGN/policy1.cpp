template<typename T>
class vector
{
	T* ptr;
pubilc:
	void resize(std::size_t newsize)
	{
		// 메모리 할당/해지가 필요 하다면 ?
		ptr = new T[newsize];

		delete[] ptr;
	}
};

int main()
{
	vector<int> v;
}

// 전통적인 분류에서는 없다. 
// cpp, stl의 구현이 해당 디자인으로 구현되어 있음
// 전략 패턴 + 성능을 향상 
// 기존의 전략패터능ㄴ 가상함수를 사용하기 떄문에 성능저하(느림) + 메모리 가 많이 먹는 다는 단점이 있음 

