#include <iostream>
#include <string>


struct IImage
{
	virtual void draw() = 0;
	virtual int width() const = 0;
	virtual int height() const = 0;
	virtual ~IImage() {}
};

class Image : public IImage
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


class ImageProxy : public IImage
{
	std::string name;
	Image* img = nullptr;
public:
	ImageProxy(const std::string& name) : name(name) {}

	int width()  const { return 100;} // 파일헤더에서 정보 획득
	int height() const { return 100;} // 파일헤더에서 정보 획득

	// 인증을 남길수도 있고 
	// 보안, 원격지 서버에 대한 대행자등 다양한 기능을 추가할 수 있음. 
	// 브릿지와 유사하지만 브릿지는 업데이트를 위함. 
	// 데코레이터는 중첩의 형태로 추가, 인테페이스 동일 >> 프록시는 중첩 x, 이터페이스는 같을 수도 있고 다를 수도 있음. 
	
	void draw() 
	{
		if ( img == nullptr )
			img = new Image(name); // 꼭 그림을 그려 주어야 할때는 img 객체를 생성해서 진행
			// 지연된 생성이라 부름 

		img->draw();
	}
};
int main()
{
//	Image* img = new Image("C:\\a.png");
	IImage* img = new ImageProxy("C:\\a.png");
//	img->draw();

	int w = img->width();
	int h = img->height();
	img->draw();
}