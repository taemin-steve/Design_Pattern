#include <iostream>
#include <string>


struct IDraw
{
	virtual void draw() const  = 0;

	virtual ~IDraw() {}
};


class Image : public IDraw
{
	std::string image_path;
public:
	Image(const std::string& path) : image_path(path) {	}

	void draw() const { std::cout << "draw " << image_path << std::endl; }
};

class Decorator : public IDraw
{
	IDraw* img;
public:
	Decorator(IDraw* img) : img(img) {}

	void draw() const { img->draw();}
};

class Frame : public Decorator
{

public:
	Frame(IDraw* img) : Decorator(img) {}

	void draw() const 
	{ 
		std::cout << "==========================" << std::endl; 
		Decorator::draw();
		std::cout << "==========================" << std::endl; 
	}
};

class Balloon  : public Decorator
{
	
public:
	Balloon(IDraw* img) : Decorator(img) {}

	void draw() const 
	{ 
		std::cout << "== Balloon ===============" << std::endl; 
		Decorator::draw();
		std::cout << "== Balloon ==============="  << std::endl; 
	}
};

int main()
{
	Image img("www.image.com/car.jpg");

	Frame frame(&img); //업케스팅이 암묵적으로 발생

	Balloon balloon(&frame); // draw 해주면 중첩적으로 이전 객체의 draw가 불리는 구조! 
	balloon.draw(); // 
}