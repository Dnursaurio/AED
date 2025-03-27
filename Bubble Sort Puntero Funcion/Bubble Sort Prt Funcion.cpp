#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

long long int ascendente(long long int arr[], long long int tam)
{
	long long int* p;
	long long int* q;

	auto time1 = high_resolution_clock::now();

	for (p = arr + 0; p <= arr + tam - 1; p++)
	{
		for (q = arr + 0; q < arr + tam - 1; q++)
		{
			if (*q > *(q + 1))
			{
				swap(*q, *(q + 1));
			}
		}
	}

	auto time2 = high_resolution_clock::now();
	auto duracion = duration_cast<microseconds>(time2 - time1);

	cout << "el tiempo de ejecucion del array asccendente es de: " << duracion.count() << " microsegundos." << endl;
	return 0;
}

long long int descendente(long long int arr[], long long int tam)
{
	long long int* p;
	long long int* q;

	auto time1 = high_resolution_clock::now();

	for (p = arr + 0; p <= arr + tam - 1; p++)
	{
		for (q = arr + 0; q < arr + tam - 1; q++)
		{
			if (*q < *(q + 1))
			{
				swap(*q, *(q + 1));
			}
		}
	}

	auto time2 = high_resolution_clock::now();
	auto duracion = duration_cast<microseconds>(time2 - time1);

	cout << "el tiempo de ejecucion del array desccendente es de: " << duracion.count() << " microsegundos." << endl;

	return 0;
}

long long int imprimir(long long int arr[], long long int tam)
{
	long long int* u;

	for (u = arr + 0; u <= arr + tam - 1; u++)
	{
		cout << *u << " ";
	}
	cout << endl;

	return 0;
}

int main()
{
	cout << "---------------Bubble Sort Puntero a Funcion---------------" << endl;
	long long int (*ptr_funcion1) (long long int arr[], long long int) = NULL;
	long long int (*ptr_funcion2) (long long int arr[], long long int) = NULL;

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

	ptr_funcion1 = ascendente;
	ptr_funcion2 = descendente;
	cout << "El array ascedente: " << endl;
	ptr_funcion1(arr,100);
	imprimir(arr, 100);
	cout << "El array descedente: " << endl;
	ptr_funcion2(arr, 100);
	imprimir(arr,100);
	return 0;
}