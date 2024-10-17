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
			instance = new T; // 전달받은 Type의 객체가 생성됨
		
		return *instance;
	}
};
template<typename T> T* Singleton<T>::instance = nullptr; //T는 위의 클래스 내에서만 토용되므로 다음과같이 적어주어야 함 
template<typename T> std::mutex Singleton<T>::m;


class Mouse : public Singleton< Mouse > // 상속을 통해서 싱글톤 코드를 재사용하는 방법도 가능
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();
}