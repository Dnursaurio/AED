#include <iostream>
#include "Clase_comparar.h"
#include "ascendente.h"
#include "descendente.h"
#include <chrono>
#include <random>
#include <set>

using namespace std;
using namespace chrono;

void bubble(long long int arr[], long long int tam, const CLASE_COMPARAR& comp)
{
	auto time1 = high_resolution_clock::now();
	for (long long int* p = arr + 0; p <= arr + tam - 1; p++)
	{
		for (long long int* q = arr + 0; q < arr + tam - 1; q++)
		{
			if (comp.comparar(*q, *(q + 1)))
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
	for (long long int* u = arr + 0; u <= arr + tam - 1; u++)
	{
		cout << *u << " ";
	}
	cout << endl;
}

int main()
{	
    const long long int TAM = 1000000;
    long long int* arr = new long long int[TAM];

    // Generador de números aleatorios únicos
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<long long int> distrib(1, TAM * 10);

    set<long long int> numerosUnicos;
    while (numerosUnicos.size() < TAM)
    {
        numerosUnicos.insert(distrib(gen));
    }

    // Copiar los valores únicos al array
    long long int i = 0;
    for (long long int num : numerosUnicos)
    {
        arr[i++] = num;
    }

    Greater asc;
    bubble(arr, TAM, asc);

    delete[] arr;
    return 0;
}