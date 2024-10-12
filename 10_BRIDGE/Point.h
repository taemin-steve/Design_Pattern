//#include "PointImpl.h"
class PointImpl; // 핵심.. 포인터를 쓸때는 전방선언으로도 충분하다.

class Point
{
	PointImpl* impl;
public:
	Point(int x, int y);

	void print() const;
};

//PIMPL >> 컴파일러 방화벽이자, 완벽한 정보 은닉이가능하다. 아예 DLL로 줘버리면 돤다.