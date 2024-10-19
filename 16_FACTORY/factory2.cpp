#include <iostream>
#include <vector>
#include <map>
#include "singleton.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; } //객체를 만드는 새로운 방법
};
// cpp에는 클래스 이름을 자료구조에 저장할 수 없음 >> 대신 생성함수 create()는 보관 가능하다.


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using F = Shape*(*)(); 

	std::map<int, F> create_map; // 도형의 번호, 생성 함수 등록

public:

	void register_shape(int key, F create_function)
	{
		create_map[key] = create_function;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;

		if (create_map[type] != nullptr)
		{
			p = create_map[type](); // 도형 생성
		}
		return p;
	}
};




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에 제품을 등록한다.
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);
	// 새로운 도형이 생기면 공장에 제품을 등록하고, 찍어내야 한다.

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8)
		{
			Shape* s = factory.create(cmd);

			if ( s )
				v.push_back(s);
		}


		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
		}
	}
}




