#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

struct Ascendente
{
	bool operator ()(long long int a, long long int b)
	{
		return a > b;
	}
};

struct Descendente
{
	bool operator ()(long long int a, long long int b)
	{
		return a < b;
	}
};


template <class U>
void Bubble(long long int arr[], long long int tam,  U comparar)
{

	auto time1 = high_resolution_clock::now();
	for (long long int* p = arr + 0; p <= arr + tam - 1; p++)
	{
		for (long long int* q = arr + 0; q < arr + tam - 1; q++)
		{
			if (comparar(*q, *(q + 1)))
			{
				long long int tmp = *q;
				*q = *(q + 1);
				*(q + 1) = tmp;
			}
		}
	}
	auto time2 = high_resolution_clock::now();
	auto duracion = duration_cast<microseconds>(time2 - time1);
	cout<<"el tiempo de ejecucion de un array de "<< tam <<" elementos es: "<<duracion.count()<<" microsegundos"<<endl;
}

void imprimir(long long int arr[], long long int tam)
{
	long long int* u;

	for (u = arr + 0; u <= arr + tam - 1; u++)
	{
		cout << *u << " ";
	}
	cout << endl;
}

int main()
{
	cout << "-----------------Bubble Sort Functores-----------------" << endl;
	long long int arr[10] = { 8,7,9,6,4,3,5,2,1,10 };
	cout << "Array ascendente" << endl;
	Ascendente asc;
	Bubble(arr, 10, asc);
	imprimir(arr, 10);
	cout << "Array Descendente" << endl;
	Descendente desc;
	Bubble(arr, 10, desc);
	imprimir(arr, 10);
	
}