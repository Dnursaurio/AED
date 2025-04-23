#include <iostream>

using namespace std;

struct CNode
{
	CNode(int _v)
	{
		value = _v;
		next = 0;
	}
	int value;
	CNode* next;
};

class CList
{
public:
	CList()
	{
		return;
	}
	~CList()
	{
		return;
	}
	bool Find(int val, CNode**& p)
	{
		/*
		p = &head;
		while (*p && (*p)->value < val tambien esa valido (**p).value)
		{
			p = &((*p)->next);
			return *p && (*p)->value == val;
		}*/
		for (p = &head;*p && (*p)->value < val;p = &((*p)->next))
		{
			return *p && (*p)->value == val;
		}
	}
	bool Insert(int val)
	{
		CNode** p;
		if (Find(val, p))
		{
			return false;
		}
		else
		{
			CNode* temp = new CNode(val);
			temp->next = *p;
			*p = temp;
			return true;
		}
	}
	bool Remove(int val)
	{
		CNode** p;
		if (!Find(val, p))
		{
			return false;
		}
		else
		{
			CNode* temp = *p;
			*p = temp->next;
			delete temp;
			return true;
		}
	}
	void print()
	{
		for (CNode* T = head;T;T = T->next)
		{
			cout << T->value << " ";
		}
	}
private:
	CNode* head;
};

int main()
{
	CList lista;
	lista.Insert(2);
	lista.Insert(11);
	lista.Insert(4);
	lista.Insert(60);
	lista.print();
}