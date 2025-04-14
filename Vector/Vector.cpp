#include <iostream>

using namespace std;

template <class O>
void print(O arr[], int tam)
{
	for (O* i = arr + 0; i <= arr + tam - 1; i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

template <class T>
class Cvector
{
public:
	Cvector(T tamano):tam(tamano)
	{
		//ahora mi puntero ptr apunta al primer elemento del arreglo
		ptr = new T[tam];
	}
	bool PushFront(T valor)
	{
		if (ptr < ptr + tam - 1)
		{
			for (T* p = ptr + tam - 1; p >= ptr; p--)
			{
				T* q = p - 1;
				*p = *q;
			}
			*ptr = valor;
			print<int>(ptr, tam);
			return true;
		}
		else
		{
			T* ref = ptr;
			cout << "ampliando vector ..." << endl;
			T ntam = tam * 2;
			ptr = new T[ntam];
			cout << "copiando elemementos ..." << endl;
			for (T* i = ptr; i <= ptr + tam - 1; i++)
			{
				*i = *ptr;
			}
			delete[] ref;
			print<int>(ptr, ntam);
		}
	}
	void PopFront(T& valor);
	void PushBack(T valor);
	void PopBack(T& valor);
	void operator [](T& index);
private:
	T* ptr;
	int tam;
};
int main()
{
	/*aca mi tamaño se hace 10
	tam = 10, entonces mi arreglo tiene tamaño 10*/
	Cvector <int> V1{10};
	V1.PushFront(1);
	V1.PushFront(2);
	V1.PushFront(4);
	V1.PushFront(5);
	V1.PushFront(15);
	V1.PushFront(19);
	V1.PushFront(123);
	V1.PushFront(40);
	V1.PushFront(32);
	V1.PushFront(54);
	V1.PushFront(4);
}