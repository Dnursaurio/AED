#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <class T, int tam>
struct Hash
{
	Hash() : tabla(tam) {};
	int FuncHash(T val)
	{
		return val % tam;
	}

	void Insert(T val)
	{
		int indice = FuncHash(val);
		tabla[indice].push_back(val);
	}

	void Mostrar()
	{
		for (int i = 0; i < tam; i++)
		{
			cout << "Posicion :" << i << endl;

			typename list<T>::iterator it;
			for (it = tabla[i].begin(); it != tabla[i].end(); it++)
			{
				cout << *it << endl;
			}
		}
	}

	vector<list<T>> tabla;
};

int main()
{
	cout << "----------------Hash Table----------------" << endl;
	Hash<int, 8> ht;
	ht.Insert(2);
	ht.Insert(16);
	ht.Insert(8);
	ht.Mostrar();
	cout << "------------------------------------------" << endl;
	return 0;
}