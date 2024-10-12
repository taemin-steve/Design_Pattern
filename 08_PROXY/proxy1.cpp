#include <iostream>
#include <string>

class Image
{
	std::string name;
public:
	Image(const std::string& name) : name(name)
	{
		std::cout << "open " << name << '\n';
	}
	void draw() { std::cout << "draw " << name << '\n'; }

	int width()  const { return 100;}
	int height() const { return 100;}
};

int main()
{
	Image* img = new Image("C:\\a.png");
	img->draw();

	int w = img->width(); // 이것만 확인하고 싶음! 
	int h = img->height(); // 하지만 해당 동작을 수행하기 위해서는 메모리에 전체 객체를 로드해 주어야함 
}