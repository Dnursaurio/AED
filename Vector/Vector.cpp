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
		if (ptr != nullptr)
		{
			for (T* p = ptr + 1; p <= ptr + tam - 1; p++)
			{
				*p = *(p-1);
			}
			*ptr = valor;
			print<int>(ptr, tam);
			return true;
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
}