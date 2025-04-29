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
	CList();
	~CList();
	bool Find(int x, CNode**& p);
	bool Insert(int val);
	bool Remove(int val);
	void print();
private:
	CNode* head;
};

CList::CList()
{
	head = 0;
}

CList::~CList()
{}

bool CList::Find(int x, CNode**& p)
{
	//solo hace el avance del puntero
	for (p = &head; *p && (*p)->value < x; p = &((*p)->next));
	//esto retorna 0 o 1
	return *p && (*p)->value == x;
}

bool CList::Insert(int val)
{
	CNode** p;
	if (Find(val, p)) return false;
	CNode* temp = new CNode(val);
	temp->next = *p;
	*p = temp;
	return true;
}

bool CList::Remove(int val)
{
	CNode** p;
	if (!Find(val, p)) return false;
	CNode* temp = *p;
	*p = temp->next;
	delete temp;
	return true;
}

void CList::print()
{
	for (CNode* t = head; t; t = t->next)
	{
		cout << t->value << " ";
	}
	cout << "\n";
}

int main()
{
	CList lista;
	lista.Insert(4);
	lista.Insert(2);
	lista.Insert(8);
	lista.print();
	lista.Remove(2);
	lista.print();
	lista.Insert(95);
	lista.Insert(1);
	lista.print();
	return 0;
}