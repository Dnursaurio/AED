#include <iostream>

using namespace std;

struct Node
{
	Node(int v)
	{
		valor = v;
		next = NULL;
	}
	Node* next;
	int valor;
};

class List
{
public:
	List()
	{
		head = NULL;
		tail = NULL;
	}
	bool Find(int x, Node**& p)
	{
		for (p = &head; *p && (*p)->valor < x; p = &((*p)->next));
		return *p && (*p)->valor == x;
	}
	bool PushFront(int x)
	{
		Node** p;
		if (Find(x, p))
		{
			return false;
		}
		else if (tail == NULL)
		{
			tail = new Node(x);
			head = tail;
			return true;
		}
		else
		{
			Node* temp;
			temp = new Node(x);
			temp->next = head;
			head = temp;
		}
	}
	bool PopFront(int& x)
	{
		Node** p;
		x = head->valor;
		if (!Find(x, p))
		{
			return false;
		}
		else if (head != tail)
		{
			Node* temp;
			temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else
		{
			Node* temp;
			temp = head;
			head = NULL;
			tail = NULL;
			delete temp;
			return true;
		}
	}
	bool PushBack(int x)
	{
		Node** p;
		if (Find(x, p))
		{
			return false;
		}
		else if(tail == NULL)
		{
			tail = new Node(x);
			head = tail;
			return true;
		}
		else
		{
			Node* temp;
			temp = new Node(x);
			tail->next = temp;
			tail = temp;
			return true;
		}
	}
	bool PopBack(int& x)
	{
		Node** p;
		x = tail->valor;
		if (!Find(x, p))
		{
			return false;
		}
		else if (tail != head)
		{
			Node* temp;
			for (temp = head; temp->next != tail; temp = temp->next);
			delete tail;
			tail = temp;
			temp->next = nullptr;
		}
		else
		{
			Node* temp;
			temp = tail;
			head = NULL;
			tail = NULL;
			delete temp;
			return true;
		}
	}
	void print()
	{
		for (Node* i = head; i; i = i->next)
		{
			cout << i->valor << " ";
		}
		cout << endl;
	}

private:
	Node* head;
	Node* tail;
};

int main()
{
	cout << "--------------------Lista--------------------" << endl;
	List l;
	int terminated_front;
	int terminated_back;
	cout << "probando el PushFront ..." << endl;
	l.PushFront(12);
	l.print();
	l.PushFront(16);
	l.PushFront(6);
	l.print();
	cout << "probando el PopFront ..." << endl;
	l.PopFront(terminated_front);
	l.PopFront(terminated_front);
	l.print();
	cout << "probando el PushBack ..." << endl;
	l.PushBack(18);
	l.PushBack(24);
	l.print();
	cout << "probando el PopBack ..." << endl;
	l.PopBack(terminated_back);
	l.print();
}