#include <iostream>

using namespace std;

template<class O>
void print(O* arr, O tam)
{
	for (O* i = arr + 0; i <= arr + tam - 1; i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

template <class T>
class Leque
{
public:
	Leque(int tamano):tam(tamano)
	{
		mapa = new T* [tam];
		mapeador = mapa + 0;
		ptrarr = new T[tam];
		mapa[i] = ptrarr;
		ptr = ptrarr + 0;
	}
	void PushFront(T valor)
	{
		if (mapeador < mapa + tam - 1)
		{
			if (ptr < ptrarr + tam - 1)
			{
				for (T* p = ptrarr + tam - 1; p >= ptrarr; p--)
				{
					T* q = p - 1;
					*p = *q;
				}
				*ptr = valor;
				print<int>(ptrarr, tam);
			}
			else
			{
				mapeador++;
				i = i + 1;
				T* narr;
				narr = new T[tam];
				mapa[i] = narr;
				ptrarr = narr;
			}
		}
	}
	/*
	void PopFront(& valor);
	void PushBack (T valor);
	void PopBack (& valor);
	void operator[](T index);
	*/

private:
	T** mapa;
	T** mapeador;
	T* ptrarr;
	T* ptr;
	int i = 0;
	int tam;
};

int main()
{
	Leque<int>L1{ 5 };
	L1.PushFront(12);
	L1.PushFront(14);
}