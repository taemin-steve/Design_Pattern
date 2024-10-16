class Cursor
{
private:
	Cursor() {} // 생성자를 private에 배치해서 생성을 막아버림

	Cursor(const Cursor& ) = delete; //복사 금지
	Cursor& operator=(const Cursor&) = delete; // 대입 금지

public:
	static Cursor& get_instance() // 객체를 부르기 위해서 다시 객체를 생성해야함을 방지 >> static 사용
	{
		static Cursor instance; // static으로 만들었기 떄문에 한번만 호출
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
//	Cursor c3 = c1; >> 복사생성자가 자동으로 호출됨. >> 복사도 금지해야함. >> 관례적으로 대입도 금지함
//	Cursor c1;
//	Cursor c2;
}

//싱글턴은 결국 전역변수 아닌가? 
// 멀티 스레드간의 문제도 있고 
// 객체간의 결합도가 증가하고, 재사용성이 감소하기도 한다.