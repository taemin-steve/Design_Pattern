#include <iostream>
#include <string>

class Image
{
	std::string image_path;
public:
	Image(const std::string& path) : image_path(path) {	}

	void draw() const { std::cout << "draw " << image_path << std::endl; }
};

class Frame 
{
	Image* img;
public:
	Frame(Image* img) : img(img) {}

	void draw() const 
	{ 
		std::cout << "==========================" << std::endl; 
		img->draw();
		std::cout << "==========================" << std::endl; 
	}
};

class Balloon 
{
	Image* img;
public:
	Balloon(Image* img) : img(img) {}

	void draw() const 
	{ 
		std::cout << "== Balloon ===============" << std::endl; 
		img->draw();
		std::cout << "== Balloon ==============="  << std::endl; 
	}
};
int main()
{
	Image img("www.image.com/car.jpg");
	img.draw();

	Frame frame(&img);
	frame.draw();

	Balloon balloon(&img);
//	Balloon balloon(&frame); // ?
	balloon.draw();
}

//객체에 기능을 추가하고 싶으면 상속이 아닌 포함을 활용 >> 포인트 맴버 변수를 초기화시에 받는 구조로 형성 
//왜 이렇게 하지? 그냥 Image에 넣으면 되잖아. >> 기능 중첩이 포인트. 이렇게 하면 기능 중첩이 안됨