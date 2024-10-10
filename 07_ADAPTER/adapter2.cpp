#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
#include "CoolText.h"

class ClsAdapter : public CoolText, public Shape //클래스 어댑터 >> CoolText 객체를 하나 새로 생성하는 것과 동일
{
public:
	ClsAdapter(const std::string& text) : CoolText(text) {}

	void draw() override { CoolText::show();}
};	

class ObjAdapter : public Shape  // 객체 어댑터
{
	CoolText* ct; // 객체를 받아올 떄는 보통 이런 형식을 많이 사용한다.
public:
	ObjAdapter(CoolText* ct) : ct(ct) {}

	void draw() override { ct->show();}
};	

int main()
{
	std::vector<Shape*> v;

	CoolText ct("Hello");	// CoolText : 클래스
							// ct       : 객체

//	v.push_back( &ct ); 	// error

	v.push_back( new ObjAdapter( &ct)  ); // 이미 위에서 만든 CoolText의 객체를 가져와서 사용

	v[0]->draw();
}