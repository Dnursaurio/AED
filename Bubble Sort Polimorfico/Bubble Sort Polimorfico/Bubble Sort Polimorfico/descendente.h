#include <iostream>
#include <chrono>
#include "Clase_comparar.h"

using namespace std;
using namespace chrono;

class descencente : public CLASE_COMPARAR
{
public:
	void comparar(long long int arr[], long long int tam)
	{
		cout << "------------------Bubble sort Descendente------------------" << endl;
		auto time1 = high_resolution_clock::now();
		long long int* p;
		long long int* q;
		long long int* u = arr + 0;

		for (p = arr + 0; p < arr + (tam - 1); p++)
		{
			for (q = arr + 0; q < arr + (tam - 1); q++)
			{
				if (*q < *(q + 1))
				{
					swap(*q, *(q + 1));
				}
			}
		}
		auto time2 = high_resolution_clock::now();
		auto duracion = duration_cast<microseconds>(time2 - time1);
		for (u; u <= arr + tam - 1; u++)
		{
			cout << *u << " ";
		}
		cout << endl;
		cout << "El tiempo de ejecucion del Bubble Sort descendente para un array de " << tam << " elementos es: " << duracion.count() << " microsegundos" << endl;
	}
};
