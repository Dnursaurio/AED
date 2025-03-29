#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

bool ascendente(long long int a, long long int b)
{
	return a > b;
}

bool descendente(long long int a, long long int b)
{
	return a < b;
}

void bubble(long long int arr[], long long int tam, bool (*comp)(long long int, long long int))
{
	auto time1 = high_resolution_clock::now();
	for (long long int* p = arr + 0; p <= arr + tam - 1; p++)
	{
		for (long long int* q = arr + 0; q < arr + tam - 1; q++)
		{
			if (comp(*q, *(q + 1)))
			{
				long long int tmp = *q;
				*q = *(q + 1);
				*(q + 1) = tmp;
			}
		}
	}
	auto time2 = high_resolution_clock::now();
	auto duracion = duration_cast<microseconds>(time2 - time1);
	cout << "el tiempo de ejecucion es de: " << duracion.count() << " microsegundos" << endl;
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
	cout << "---------------Bubble Sort Puntero a Funcion---------------" << endl;
	long long int arr[100] = { 3,24,65,76,9,32,12,56,74,1,
		3,24,65,76,9,32,12,56,74,1,
		3,24,65,76,9,32,12,56,74,1, 
		3,24,65,76,9,32,12,56,74,1,
		3,24,65,76,9,32,12,56,74,1,
		3,24,65,76,9,32,12,56,74,1,
		3,24,65,76,9,32,12,56,74,1,
		3,24,65,76,9,32,12,56,74,1,
		3,24,65,76,9,32,12,56,74,1,
		3,24,65,76,9,32,12,56,74,1 };

	bubble(arr, 100, ascendente);
	imprimir(arr, 100);

	return 0;
}