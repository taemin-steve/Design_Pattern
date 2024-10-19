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

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using F = Shape*(*)(); 

	std::map<int, F> create_map; 

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

class RegisterFactory
{	
public:
	RegisterFactory(int type, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(type, f);
	}
};


#define REGISTER(classname)						\
	static Shape* create() { return new classname; }	\
	static RegisterFactory rf;

#define REGISTER_IMPL(type, classname)			\
	RegisterFactory classname::rf(type, &classname::create);

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	REGISTER(Rect)
};
REGISTER_IMPL(1, Rect)






class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	REGISTER(Circle)
};
REGISTER_IMPL(2, Circle)


class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	//REGISTER(Triangle)
	static Shape* create() { return new Triangle; }	
	static RegisterFactory rf1; // rf1으로 하더라도 어차피 factory는 싱글턴이기 떄문에 문제는 없음. 비효율적일 뿐
};
RegisterFactory Triangle::rf1(3, &Triangle::create);



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

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




