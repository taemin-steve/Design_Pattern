#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
#include "CoolText.h"

class ClsAdapter : public CoolText, public Shape //원하는 기능을 물려받고, 도형편집기의 인터페이스 요구사항도 맞추어준다.
{
public:
	ClsAdapter(const std::string& text) 
			: CoolText(text) {}

	void draw() override { CoolText::show();}
};	


int main()
{
	std::vector<Shape*> v;

	v.push_back( new ClsAdapter("Hello"));

	v[0]->draw();
}