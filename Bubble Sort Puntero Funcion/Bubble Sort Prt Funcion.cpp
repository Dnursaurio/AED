#include <iostream>
#include <chrono>
#include <random>
#include <set>
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
	long long int tam = 1000000;
	long long int* arr = new long long int[tam];
	random_device rand;
	mt19937_64 generar(rand());
	uniform_int_distribution<long long int> distribucion(1, tam * 10);
	set<long long int> nros_diferentes;
	while (nros_diferentes.size() < tam)
	{
		nros_diferentes.insert(distribucion(generar));
	}
	long long int i = 0;
	for (long long int num : nros_diferentes)
	{
		arr[i++] = tam;
	}
	bubble(arr, tam, ascendente);
	return 0;
}