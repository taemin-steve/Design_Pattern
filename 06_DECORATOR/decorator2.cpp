#include <iostream>
#include <string>

class Image
{
	std::string image_path;
public:
	Image(const std::string& path) : image_path(path) 
	{	
		// load image from file or internet
	}
	void draw() const 
	{ 
		std::cout << "draw " << image_path << std::endl; 
	}
};

class Frame : public Image 
{
public:
	using Image::Image;

	void draw() const 
	{ 
		std::cout << "==========================" << std::endl; 
		Image::draw();
		std::cout << "==========================" << std::endl; 
	}
};
class Balloon : public Image 
{
public:
	using Image::Image;

	void draw() const 
	{ 
		std::cout << "== Balloon ==============" << std::endl; 
		Image::draw();
		std::cout << "== Balloon ==============" << std::endl; 
	}
};

int main()
{
	Image img("www.image.com/car.jpg");
	img.draw();

	Frame frame("www.image.com/car.jpg");
	frame.draw();

	Balloon balloon("www.image.com/car.jpg");
	balloon.draw();
}


//상속을 통해서 추가적인 서비스를 구현하는 경우 
//>> 객체가 아닌 클래스에 기능을 추가한 것. 이미지를 다시 로드하는 것이 반복됨
// 여러개의 서비스를 중복해서 추가 하기가 어려움. 
