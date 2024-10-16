#include <mutex>

template<typename T> //CRTP라는 방법 
class Singleton
{
protected:
	Singleton() {} // 싱속 받아서 사용할 수 있도록 변경해 주었음

private:	
	Singleton(const Singleton& ) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static std::mutex m;
	static T* instance;
public:
	static T& get_instance()
	{		
		std::lock_guard<std::mutex> g(m);

		if ( instance == nullptr )
			instance = new T;
		
		return *instance;
	}
};
template<typename T> T* Singleton<T>::instance = nullptr; //추가적으로 해주어야함
template<typename T> std::mutex Singleton<T>::m;


class Mouse : public Singleton< Mouse > // 상속을 통해서 싱글톤 코드를 재사용하는 방법도 가능
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();
}