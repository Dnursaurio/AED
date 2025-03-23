#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

//funcion bubble
void bubble(long long int arr[], long long int tam)
{
	auto tiempo_ini = high_resolution_clock::now();

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

	cout << "Tiempo de ejecución: " << duracion.count() << " microsegundos" << endl;
}

int main()
{
	cout << "-----------------Bubble Xor-----------------" << endl;
	long long int arr[10] = {12,54,20,6,40,19,1,43,4,100};
	bubble(arr, 10);
	return 0;
}