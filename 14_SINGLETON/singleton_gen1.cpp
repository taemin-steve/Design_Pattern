/*
#define MAKE_SINGLETON(classname)			\
private:									\
	classname() {}							\
	classname(classname&) = delete;			\
	void operator=(classname&) = delete;	\
public:										\
	static classname& getInstance()			\
	{										\
		static classname instance;			\
		return instance;					\
	}										\
private:// 요게 있어주는게 좋음. 디폴트가 private으로 끝나게 지정해 주는 구조 
*/
#include "singleton.h"

class Cursor
{
    MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
}