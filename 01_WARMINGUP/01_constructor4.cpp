class Animal
{
//public:		// A, B 모두 ok
//private:		// A, B 모두 error
protected: // protected는 상속에 열려 있으나 호출에 막혀 있다.
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}
};

int main()
{
	// 다음중 에러를 모두 골라 보세요
	//Animal a;	// A error protected 생성자를 직접 호출 하는 case
	Dog    d;	// B ok
}



