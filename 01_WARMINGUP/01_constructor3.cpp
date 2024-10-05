#include <string>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& name, int age) : name(name), age(age) {}
};

class Student : public People
{
	int id;
public:
//	Student(int id) : id(id) {} // Student(int id) : People(),  id(id) {} //


	Student(const std::string& name, int age, int id) 
		: People(name, age),  id(id) {} // id(id)는 맴버 변수의 초기화 (해당 방식은 맴버 변수에 값 할당이 아닌 초기화로
		//조금더 효율적일 수 있음)
};

int main()
{
	Student s("kim", 20, 15);
}

// 부모 클래스에 없는 변수를 생성자로 부른다면, 부모 클래스에는 원래 그들이 가지고 있는 값은 넘겨주고, 본인의 것은
// 직접 초기화 햐야한다.

