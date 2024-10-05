class Animal
{
public:
	virtual ~Animal() {}
};
class Cat : public Animal {};
class Dog : public Animal 
{
public:
	void run() {}
};
//기존의 코드를 수정하지 않고, 추가적인 요구사항을 만족시키기 위해 다음과 같이 오버라이딩을 진행
void foo(Animal* p)
{
	// 모든 동물의 공통의 작업
}

void foo(Dog* p)
{
	foo(static_cast<Animal*>(p));
	p->run();
}

int main()
{
	Dog d; foo(&d);
	Cat c; foo(&c);
}