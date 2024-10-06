#include <iostream>
#include "Painter.h"

class Shape
{
public:
	virtual ~Shape() {}
	virtual void draw() = 0;
};

class Rect : public Shape
{
public:
	void draw() override
	{
		PainterPath path;
		path.begin();

		// path 멤버 함수로 그림을 그린다.
		path.draw_rect();

		path.end();

		Painter surface;
		surface.draw_path(path);
	}
};


class Circle : public Shape
{
public:
	void draw() override
	{
		PainterPath path;
		path.begin();

		// path 멤버 함수로 그림을 그린다.
		path.draw_circle();
		
		path.end();

		Painter surface;
		surface.draw_path(path);
	}
};

int main()
{
	Shape* s1 = new Rect;
	Shape* s2 = new Circle;

	s1->draw();
	s2->draw();
}

// Behavior pattern
// 탬플릿 메소드 : 알고리즘의 처리과정은 변경하지 않고 알고리즘의 각 단계의 처리를 서브클래스에서 재정의 할 수 있게 한다. 

