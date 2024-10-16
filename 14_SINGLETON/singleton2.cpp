#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "start  Cursor()" << std::endl;
		std::this_thread::sleep_for(3s); // 3초가 걸린다고 하더라도 늦게 도착한 애들은 앞의 생성자가 생성될 때까지 대기한다. 
		std::cout << "finish Cursor()" << std::endl;		
	}
	Cursor(const Cursor& ) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	static Cursor& get_instance()
	{
		std::cout << "start  get_instance" << std::endl;
		static Cursor instance;
		std::cout << "finish get_instance" << std::endl;
		return instance;
	}
};
int main()
{
//	std::cout << "main" << std::endl;
//	Cursor& c1 = Cursor::get_instance(); // 지연된 초기화. get_instance()를 호출할 때 초기화됨. 안쓰면 생성자가 호출되지 않음

	std::thread t1(&Cursor::get_instance);
	std::thread t2(&Cursor::get_instance);

	t1.join();
	t2.join();
}

//Meyer's singleton >> 오직 한개의 객체를 static 지역변수로 생성한다. 
