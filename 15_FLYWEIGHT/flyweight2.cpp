#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading...\n";
	}
public:

	void draw() 
	{ 
		std::cout << "draw " << image_url << '\n';
	}
	
	static std::map<std::string, Image*> image_map;

	static Image* create(const std::string& url) //객체를 생성하지 않고도 호출할 수 있도록 static선언
	{
		Image* img;
		auto ret = image_map.find(url);
		
		if (ret == image_map.end()) // 이미지가 map에 없을때만 이미지를 새로 생성한다.
		{
			img = new Image(url);
			image_map[url] = img;
		}
		return image_map[url];
	}
};
std::map<std::string, Image*> Image::image_map;

int main()
{
	Image* img1 = Image::create("www.image.com/a.png"); // 내부의 스테틱 함수를 통해서 호출
	img1->draw();

	Image* img2 = Image::create("www.image.com/a.png");
	img2->draw();
}



