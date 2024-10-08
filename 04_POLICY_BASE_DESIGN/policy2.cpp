template<typename T>
class vector
{
	T* ptr;
pubilc:
	void resize(std::size_t newsize)
	{
		ptr = allocate(size);

		deallocate(ptr, size);
	}

	virtual T*   allocate(std::size_t size)   { return new T[size];}
	virtual void deallocate(T* ptr, std::size_t size) { delete[] ptr;}
};

template<typename T> 
class malloc_vector : public vector<T>
{
public:
	T*   allocate(std::size_t size)   { return static_cast<T*>(malloc(sizeof(T)*size));}
	void deallocate(T* ptr, std::size_t size) { free(ptr);}
};


int main()
{
	//vector<int> v;
	malloc_vector<int> v;
}

//메모리 할당하는 코드를 재사용하기가 어려움
// vector, list, ...  모두 재정의 해야함. 
// 해당기능(메모리 할당)은 다른 곳에서도 쓰일 수 있다. 