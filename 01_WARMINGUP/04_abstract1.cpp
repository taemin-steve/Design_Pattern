class Shape //순수 가상함수가 하나라도 있으면 추상 클래스가 됨
{
public:
	virtual ~Shape() {}	

	virtual void draw() = 0; // 구현부가 없고 = 0 으로 구성 >> 순수 가상함수
};

int main()
{
//	Shape  s;	// error	
	Shape* p;	// ok 객체를 생성할 수는 없지만 포인터는 생성 가능하다.
}
