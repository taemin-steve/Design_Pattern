class Shape
{
public:
	virtual ~Shape() {}	

	virtual void draw() = 0;	
};

class Rect : public Shape
{ //순수 가상함수는 반드시 구현이 되어야 한다.
public:
	virtual void draw() {}
};

int main()
{
	Rect r; // ??
}

//추상 클래스의 의도 -> 특정 함수의 생성을 강제. 