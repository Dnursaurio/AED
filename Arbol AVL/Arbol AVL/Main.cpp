#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	Node(int val, int alt)
	{
		valor = val;
		altura = alt;
		nodes[0] = NULL;
		nodes[1] = NULL;
	}

	int valor;
	int altura;
	Node* nodes[2];
};

struct AVL
{
	AVL()
	{
		raiz = NULL;
	}
	Node* raiz;

	bool Find(int val, Node**& p, stack<Node*>& back)
	{
		for (p = &raiz; *p && (*p)->valor != val; p = &((*p)->nodes[(*p)->valor < val]))
		{
			back.push(*p);
		}
		return *p != 0;
	}

	void Insert(int val)
	{
		Node** p;
		stack<Node*> backtracking;
		if (Find(val, p, backtracking))
		{
			return;
		}
		
		*p = new Node(val, 0);

		while (!backtracking.empty())
		{
			backtracking.top()->altura;
			backtracking.pop();
		}
	}

	int diferencia_alturas(Node* n)
	{
		if (!n)
		{
			return 0;
		}
		int derecha = n->nodes[1] != NULL ? n->nodes[1]->altura : 0;
		int izqquierda = n->nodes[0] != NULL ? n->nodes[0]->altura : 0;
		return derecha - izqquierda;
	}

	void bal_AVL(Node** padre)
	{
		bool lado = diferencia_alturas(*padre) > 0 ? 1 : 0;

		//caso LL y RR
		Node* temp = *padre;
		padre = &((*padre)->nodes[lado]);
		temp->nodes[lado] = (*padre)->nodes[!lado];
		(*padre)->nodes[!lado] = temp;

		//caso LR y RL
		Node* temp = *padre;
		padre = &((*padre)->nodes[lado]->nodes[!lado]);
		temp->nodes[lado]->nodes[!lado] = (*padre)->nodes[lado];
		(*padre)->nodes[lado] = temp->nodes[lado];
		temp->nodes[lado] = (*padre)->nodes[!lado];
		(*padre)->nodes[!lado] = temp;
	}

	void InOrder(Node* n)
	{
		if (!n)
		{
			return;
		}
		InOrder(n->nodes[0]);
		cout << n->valor << " ";
		InOrder(n->nodes[1]);
	}

	//funciones de impresion
	void imprimir()
	{
		InOrder(raiz);
		cout << endl;
	}
};

int main()
{
	AVL a;
	a.Insert(80);
	a.Insert(90);
	a.Insert(70);
	a.imprimir();

	return 0;
}