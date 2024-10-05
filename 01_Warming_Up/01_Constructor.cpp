#include <iostream>

using namespace std;

class Base
{
private:
    /* data */
public:
    Base() { cout << "Base()" << endl;}
    Base(int a) { cout << "Base(int)" << endl;}

    ~Base(){cout << "~Base()" << endl;}
};

class Derived : public Base
{
private:
    /* data */
public:
    Derived(/* args */)
    {
        cout << "Derived" << endl; // Base()ㄴ 먼저 호출된 다음에 호출 됨
    };
    Derived(int a)
    {
        cout << "Derived(int)" << endl; // Base()가 기본적으로 호출됨 Base(int a)가 호출되지 않음
    };
    ~Derived()
    {
        cout << "~Derived()" << endl;
    };
};

int main()
{
    Derived(5);
}

//1. 항상 부모 클래스의 기본 생성자가 호출된다.
