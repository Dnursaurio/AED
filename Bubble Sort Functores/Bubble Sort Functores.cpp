#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

struct Ascendente
{
	void operator ()(long long int arr[], long long int tam)
	{
		long long int* p;
		long long int* q;
		long long int* u;
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
		cout << "Aplicando Bubble sort con functores a un array de: " << tam << " elementos de manera ascendente,\ncon un tiempo de ejecucion de: " << duracion.count() << " microsegundos" << endl;
		for (u = arr + 0; u <= arr + tam - 1; u++)
		{
			cout << *u << " ";
		}
		cout << endl;
	}
};

struct Descendente
{
	void operator ()(long long int arr[], long long int tam)
	{
		long long int* p;
		long long int* q;
		long long int* u;
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
		cout << "Aplicando Bubble sort con functores a un array de: " << tam << " elementos de manera descendente,\ncon un tiempo de ejecucion de: " << duracion.count() << " microsegundos" << endl;
		for (u = arr + 0; u <= arr + tam - 1; u++)
		{
			cout << *u << " ";
		}
		cout << endl;
	}
};

int main()
{
	cout << "-----------------Bubble Sort Functores-----------------" << endl;
	Ascendente asc;
	Descendente desc;
	long long int arr[100] = { 10,5,4,3,6,2,1,8,7,9,
	10,5,4,3,6,2,1,8,7,9,
	10,5,4,3,6,2,1,8,7,9,
	10,5,4,3,6,2,1,8,7,9,
	10,5,4,3,6,2,1,8,7,9,
	10,5,4,3,6,2,1,8,7,9,
	10,5,4,3,6,2,1,8,7,9,
	10,5,4,3,6,2,1,8,7,9,
	10,5,4,3,6,2,1,8,7,9, 
	10,5,4,3,6,2,1,8,7,9};
	asc(arr, 100);
	desc(arr, 100);
}