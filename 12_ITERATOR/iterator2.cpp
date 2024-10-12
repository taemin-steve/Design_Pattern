#include <iostream>

template<typename T> struct IEnumerator
{
	virtual T& getObject() = 0;
	virtual bool moveNext() = 0;
	virtual ~IEnumerator() {}
};

template<typename T> struct IEnumerable  
{
	virtual IEnumerator<T>* getEnumerator() = 0;
	virtual ~IEnumerable() {}
};




template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

//--------------------------


template<typename T> 
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr)
		: current(p)
	{
	}

	T& getObject() override { return current->data; }

	bool moveNext() override
	{
		current = current->next;
		return current != nullptr; 
	}
};

//slist_enumerator p1(500번지);
//p1.moveNext();
//int n = p1.getObject();








template<typename T> class slist : public  IEnumerable<T> 
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IEnumerator<T>* getEnumerator() override
	{
		return new slist_enumerator<T>(head); // 반드시 new를 해줘야함. 
		// 다 쓰면 반드시 삭제해 주어야 하는데, 라이브러리가 할당하고, 사용자가 삭제하는 코드는 좋지 않음.
		// GC가 없어서 자동으로 삭제가 안되고, 이는 상당히 부담스러움. 
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	IEnumerator<int>* p = s.getEnumerator();

	std::cout << p->getObject() << std::endl; // 50
	p->moveNext();
	std::cout << p->getObject() << std::endl; // 40
}

// moveNext(), getObject() 둘다 가상함수. 

// 모든 컨테이너가 동일하게 동작하지 않는다.

// 인터페이스를 상송해서 만드는 경우 위와 같은 다양한 단점이 존재.