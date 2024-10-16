#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor& ) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex m; // 멀티쓰레드에 위험해 동기화가 필요함
	static Cursor* instance;
public:
	static Cursor& get_instance()
	{
		m.lock();
		if ( instance == nullptr )
			instance = new Cursor; // 힙 영역에 instance 객체가 생성된다.
		m.unlock();
		return *instance;
	}
};
Cursor* Cursor::instance = nullptr;
std::mutex Cursor::m;

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}