#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Node
{
	Node(int cx, int cy, int val)
	{
		x = cy;
		y = cx;
		valor = val;
		next[0] = NULL;
		next[1] = NULL;
	}

	int x;
	int y;
	int valor;
	Node* next[2];
};

struct Matriz
{
	//vector horizontal
	vector<Node*> x1;
	//vector vertical
	vector<Node*> y2;

	//Busqueda en el vector horizontal
	bool FindX(int x, int y, Node**& p)
	{
		for (p = &x1[x]; (*p) != NULL; p = &((*p)->next[1]));
		return (*p) != NULL && (*p)->y == y;
	}

	//Busqueda en el vector vertical
	bool FindY(int x, int y, Node**& q)
	{
		for (q = &y2[y]; (*q) != NULL; q = &((*q)->next[0]));
		return (*q) != NULL && (*q)->x == x;
	}

	/*
	-Inserta
	-Modifica
	-Elimina
	*/
	void Set(int x, int y, int val)
	{
		Node** p;
		Node** q;
		if (FindX(x, y, p))
		{
			FindY(x, y, q);
			//Modificacion de valores
			if (val != 0)
			{
				(*p)->valor = val;
			}
			//Eliminacion de valores
			else
			{
				Node* temp = (*p);
				(*p) = (*p)->next[1];
				(*q) = (*q)->next[0];
				delete[] temp;
			}
		}
		else
		{
			FindY(x, y, q);
			//Nada
			if (val == 0)
			{
				return;
			}

			//Insercion
			Node* temp = (*p);
			*p = new Node(x, y, val);
			(*p)->next[1] = temp;
			temp = (*q);
			*q = *p;
			(*q)->next[0] = temp;
		}
	}

	int Get(int x, int y)
	{
		Node** p;
		if (FindX(x, y, p))
		{
			return (*p)->valor;
		}
		else
		{
			return 0;
		}
	}
};

struct Aux
{
	Aux(int cx, int cy, Matriz* a)
	{
		x = cx;
		y = cy;
		aux = a;
	}

	int operator=(int val)
	{
		aux->Set(x, y, val);
		return val;
	}

	operator int()
	{
		return aux->Get(x, y);
	}

	Matriz* aux;
	int x;
	int y;
};

int main()
{

}