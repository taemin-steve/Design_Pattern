#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

class component
{
    string name;
    int size;
public:
    component() {}
    virtual ~component() {}

    virtual int getSize() = 0;
    virtual void print(int a = 0) = 0;

    void set_title(string n) {name = n;}
    string get_title(){return name;}

};

class Folder : public component
{
    //string name;
    vector<component* > v; // Upcasting을 활용하기 위해 포인터로 받아준다.
public :
    Folder(string n) : component() {set_title(n);}
    void add(component* c) {v.push_back(c);}
    int getSize()
    {   
        int total = 0;
        for(component* p : v)
        {
            total += p->getSize();
        }
        return total;
    }
    void print(int a = 0)
    {   
        string spaces(a * 4, ' ');
        cout << spaces <<  get_title() << endl;
        for(component* p : v)
        {
            p->print(a + 1);
        }
    }
};


class File : public component
{
    //string name;
    int size;
public :
    File(string n, int s) : component() 
    {
        set_title(n);
        set_size(s);
    }
    void set_size(int s) {size = s;}
    int getSize(){return size;}
    void print(int a = 0)
    {
        string spaces(a * 4, ' ');
        cout<< spaces << "(" << get_title() << ", " << size << ")" << endl;
    }
};


int main()
{
    //조건 1. Folder와 File의 객체를 생성할 수 있어야 한다. 
    Folder* rootFolder = new Folder("ROOT"); // 폴더는 이름만 존재 
    Folder* aaaaFolder = new Folder("AAAA");
    Folder* bbbbFolder = new Folder("BBBB");

    File* file1 = new File("a.txt", 10); // 화일은 이름과 크기가 존재
    File* file2 = new File("b.txt", 20);
    File* file3 = new File("c.txt", 30);
    File* file4 = new File("d.txt", 40);

    //조건 2. 폴더안에 파일 및 다른 폴더를 넣을 수 있어야 한다. 
    rootFolder->add(aaaaFolder);
    rootFolder->add(bbbbFolder);
    rootFolder->add(file1);

    aaaaFolder->add(file2);
    aaaaFolder->add(file3);

    bbbbFolder->add(file4);

    //조건 3. 파일과 폴더 크기를 출력할 수 있어야 한다. 
    // 폴더는 자신만의 크기는 없지만 크기를 구할 수 있다. 
    cout << file1->getSize() << endl;
    cout << aaaaFolder->getSize() << endl;
    cout << rootFolder->getSize() << endl;

    //조건 4. 화면 출력 
    file1->print(); // 파일이므로 이름과 크기만 출력 ex) (a.txt, 10)
    rootFolder->print(); // ROOT 폴더 전체의 모양을 보기 좋게 출력해주세요

    //조건 5. 폴더 제거시 폴더 안에 있는 모든 파일과 폴더가 제거 되도록 해주세요.
    delete rootFolder;

}