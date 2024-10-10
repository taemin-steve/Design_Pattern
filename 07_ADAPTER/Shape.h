// Shape.h
#pragma once

class Shape
{
public:
	virtual ~Shape() {}

	virtual void draw() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl;}
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl;}
};

//Cool Text 쓰고 싶은데, 인터페이스가 안맞음. 
// 그럼 Draw 형식으로 바꿔주면 되지 않을까?
