#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;
public:
	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading...\n";
	}
	void draw() 
	{ 
		std::cout << "draw " << image_url << '\n';
	}
};

int main()
{
	Image* img1 = new Image("www.image.com/a.png");
	img1->draw();

	Image* img2 = new Image("www.image.com/a.png"); // 동일 이미지를 두번이나 받는다!
	img2->draw();
}



