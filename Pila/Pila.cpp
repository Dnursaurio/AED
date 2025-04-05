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
		else if(top < arr + 9)
		{
			top++;
			*top = elemento;
			print(arr, 10);
			return true;
		}
		else
		{
			cout << "pila llena, no entra el elemento (" << elemento << ") haz Pop antes, gracias" << endl;
			print(arr, 10);
			return false;
		}
		
	}
	bool Pop(T& elemento)
	{
		T* popper = &elemento;
		if (top > arr + 0)
		{
			top--;
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
	cout << "anadiendo elementos adicionales" << endl;
	p.Push(2);
	p.Push(13);
	return 0;
}