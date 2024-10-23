#include <iostream>
#include <list>

using namespace std;

template<typename T>
class Adapter
{
public :
    virtual ~Adapter() {};
    virtual void Push(T comp) = 0;
    virtual T Pop() = 0;
};

template<typename T>
class Queue : public Adapter<T>
{
    std::list<T> l;
public : 
Queue<T> () {};
    void Push(T comp) {l.push_back(comp);} 
    T Pop()
    {
        T value= l.front();
        l.pop_front();
        return value;
    }
};

int main()
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);

    cout << q.Pop() << endl;
    cout << q.Pop() << endl;
}