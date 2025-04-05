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
	void Push(T elemento)
	{
		if (top==NULL)
		{
			arr[0] = elemento;
			top = arr + 0;
		}
		else if (top != nullptr)
		{
			top++;
			*top = elemento;
		}
		print(arr, 10);
	}
	void Pop(T& elemento)
	{

	}
private:
	T* top = nullptr;
	T arr[10];
};

int main()
{
	cout << "-------------Pila-------------" << endl;
	Pila <int> p;
	cout << "iniciando pila ..." << endl;
	p.Push(14);
	cout << "agregando elementos ..." << endl;
	p.Push(20);
	p.Push(8);
	p.Push(3);
	p.Push(16);
	p.Push(5);
	p.Push(100);
	p.Push(12);
	p.Push(18);
	p.Push(10);
	return 0;
}