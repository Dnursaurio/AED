#include <iostream>

using namespace std;

template<class T1>
void imprimir(T1 arr[],int tam)
{
	for (T1* i = arr + 0; i <= arr + tam - 1; i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

template <class T>
class Cola
{
public:
	bool Push(T elemento)
	{
		if (head == nullptr && tail == nullptr)
		{
			tail = arr + 0;
			head = tail;
			*tail = elemento;
			imprimir<int>(arr, 10);
			return true;
		}
		else if (tail < arr + 9)
		{
			tail++;
			*tail = elemento;
			imprimir<int>(arr, 10);
			return true;
		}
		else
		{
			cout << "Cola llena, el valor (" << elemento << ") rebalsa en la cola" << endl;
			imprimir<int>(arr, 10);
			tail = NULL;
			return false;
		}
	}
	bool Pop(T& elemento)
	{
		if (head <= arr + 9)
		{
			*head = 0;
			head++;
			imprimir<int>(arr, 10);
			return true;
		}
		else
		{
			cout << "cola vacia ._." << endl;
			imprimir<int>(arr, 10);
			head = NULL;
			return false;
		}
	}
private:
	T* head = NULL;
	T* tail = NULL;
	T arr[10];
};

int main()
{
	cout << "--------------Cola--------------" << endl;
	Cola<int> c;
	cout << "Iniciando cola ..." << endl;
	c.Push(1);
	cout << "Agregando elementos ..." << endl;
	c.Push(2);
	c.Push(3);
	c.Push(4);
	c.Push(5);
	c.Push(6);
	c.Push(7);
	c.Push(8);
	c.Push(9);
	c.Push(10);
	cout << "Agregando elementos fuera de rango ..." << endl;
	c.Push(11);
	cout << "Eliminando elementos ..." << endl;
	int eliminado;
	c.Pop(eliminado);
	c.Pop(eliminado);
	c.Pop(eliminado);
	c.Pop(eliminado);
	c.Pop(eliminado);
	c.Pop(eliminado);
	c.Pop(eliminado);
	c.Pop(eliminado);
	c.Pop(eliminado);
	c.Pop(eliminado);
	cout << "Eliminacion fuera de rango ..." << endl;
	c.Pop(eliminado);
	return 0;
}