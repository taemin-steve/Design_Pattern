#include "print.h"

class Shape
{
public:
	virtual ~Shape() {}

//	virtual void draw() { std::println("draw Shape"); }
	virtual void draw() = 0; // 추상적인 개념을 직접 그려낸다는게 어려움.
};

class Rect : public Shape 
{
public:
	void draw() override { std::println("draw Rect"); }
};

int main()
{
	Rect r;
	r.draw();
}