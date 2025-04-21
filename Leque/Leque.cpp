#include <iostream>

using namespace std;

template <class T>
class Leque
{
public:
	Leque(int tamano):tam(tamano)
	{
		mapa = new T* [tam];
		mapeador = mapa;
	}
	void PushFront(T valor)
	{
		*mapeador = new T[tam];
		if (mapeador < mapa + tam - 1)
		{
			**mapeador = valor;
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
	int tam;
};

int main()
{
	Leque<int>L1{ 5 };
	L1.PushFront(12);
}