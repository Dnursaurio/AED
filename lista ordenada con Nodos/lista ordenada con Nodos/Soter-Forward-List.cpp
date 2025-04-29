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
		head = 0;
	}
	~CList()
	{

	}
	void print()
	{
		for (CNode* T = head; T; T = T->next)
		{
			cout << T->value << " ";
		}
		cout << endl;
	}
	bool Find(int val, CNode**& p)
	{
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
private:
	CNode* head;
};

int main()
{
	CList lista;
	lista.Insert(2);
	lista.Insert(11);
	lista.Insert(60);
	lista.Insert(4);
	lista.Insert(3);
	lista.print();

	return 0;
}