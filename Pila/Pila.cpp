#include <iostream>

using namespace std;

void print(int arr[], int tam)
{
	for (int* i = arr + 0; i <= arr + tam - 1; i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

template <class T>
class Pila
{
public:
	bool Push(T elemento)
	{
		if (top == NULL)
		{
			top = arr + 0;
			*top = elemento;
			print(arr, 10);
			return true;
		}
		else if (top < arr + 9)
		{
			top++;
			*top = elemento;
			print(arr, 10);
			return true;
		}
		else
		{
			print(arr, 10);
			return false;
		}
		
	}

	bool Pop(T& elemento)
	{
		if (top > arr + 0)
		{
			cout << "Eliminando elemento (" << *top << ") de la pila" << endl;
			*top = 0;
			top--;
			print(arr, 10);
			return true;
		}
		else if (top == arr + 0)
		{
			*top = 0;
			cout << "Eliminaste el ultimo elemento del array, la pila que asi: ";
			print(arr, 10);
			top = nullptr;
			return true;
		}
		else
		{
			cout << "Pila vacia" << endl;
			return false;
		}
	}
private:
	T* top = nullptr;
	T arr[10];

};

int main()
{
	cout << "-------------Pila-------------" << endl;
	Pila <int> p;
	cout << "Iniciando pila ..." << endl;
	p.Push(14);
	cout << "Agregando elementos ..." << endl;
	p.Push(20);
	p.Push(8);
	p.Push(3);
	p.Push(16);
	p.Push(5);
	p.Push(100);
	p.Push(12);
	p.Push(18);
	p.Push(10);
	cout << "Anadiendo elementos excedentes ..." << endl;
	p.Push(2);
	cout << "Eliminando elementos ..." << endl;
	int eliminado;
	p.Pop(eliminado);
	p.Pop(eliminado);
	p.Pop(eliminado);
	p.Pop(eliminado);
	p.Pop(eliminado);
	p.Pop(eliminado);
	p.Pop(eliminado);
	p.Pop(eliminado);
	p.Pop(eliminado);
	cout << "Ultimo elemento ..." << endl;
	p.Pop(eliminado);
	cout << "Eliminacion fuera de rango ..." << endl;
	p.Pop(eliminado);
	return 0;
}