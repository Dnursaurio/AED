#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

auto tiempo_ini = high_resolution_clock::now();

//funcion bubble
void bubble(long long int arr[], long long int tam)
{
	
	for (long long int i = 0; i <= tam - 1; i++)
	{
		for (long long int o = 0; o < tam - 1; o++)
		{
			if (arr[o] > arr[o + 1])
			{
				swap(arr[o], arr[o + 1]);
			}
		}
	}

	auto tiempo_fin = high_resolution_clock::now();
	auto duracion = duration_cast<microseconds>(tiempo_fin - tiempo_ini);

	for (long long int u = 0; u <= tam - 1; u++)
	{
		cout << arr[u] << " ";
	}
	cout << endl;

	cout << "Tiempo de ejecucion: " << duracion.count() << " microsegundos" << endl;
}

int main()
{
	cout << "-----------------Bubble Sort Normal-----------------" << endl;
	cout << "Array de 10 elementos:" << endl;
	long long int arr1[10] = { 6,9,7,4,3,56,80,12,35,67 };
	bubble(arr1, 10);
	return 0;
}