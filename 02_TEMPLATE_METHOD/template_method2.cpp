#include <iostream>
#include "Painter.h"

class Shape
{
public:
	virtual ~Shape() {}

	void draw() // draw 함수에 전체적으로 변경되지 않는 처리 과정은 등록해 둠 
	{
		PainterPath path;
		path.begin();

		// path 멤버 함수로 그림을 그린다.
		draw_imp(path); // 변해야 하는 코드를 찾아 함수로 뺌

		path.end();

		Painter surface;
		surface.draw_path(path);		
	}

protected:
	virtual void draw_imp(PainterPath& path) = 0;// 함수마다 변경되어야 하는 것은 기반 함수가 재정의 하도록 함.
};



class Rect : public Shape
{
protected:
	void draw_imp(PainterPath& path) override
	{
		path.draw_rect();
	}
};


class Circle : public Shape
{
protected:
	void draw_imp(PainterPath& path) override
	{
		path.draw_circle();
	}
};

int main()
{
	Shape* s1 = new Rect;
	Shape* s2 = new Circle;

	s1->draw();
	s2->draw();
}

//핵심
// 변하지 않는 코드 내부에 있는 변해야 하는 코드를 찾는다. 
// 변해야 하는 코드를 가상함수로 분리 
// 변경이 필요한 부분만 재정의 해서 활용할 수 있음

