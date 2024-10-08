template<typename T, typename Ax = std::allocator<T> >
class vector
{
	T* ptr;
	Ax ax;
pubilc:
	void resize(std::size_t newsize)
	{
		ptr = ax.allocate(size);

		ax.deallocate(ptr, size);
	}
};

template<typename T>
class malloc_allocator 
{
public:
	inline T*   allocate(std::size_t size)  { return static_cast<T*>(malloc(sizeof(T)*size));}
	inline void deallocate(T* ptr, std::size_t size) { free(ptr);}
};

int main()
{
	vector<int, malloc_allocator<int> > v;

}

//policy base design 
//객체 말고 탬플릿으로 전달해보자. >> 인라인 치환도 가능하다. // 실행시간에 교체할 수는 없음. 