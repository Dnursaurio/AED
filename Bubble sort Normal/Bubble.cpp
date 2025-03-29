#include <iostream>
#include <chrono>
#include <random>
#include <set>
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

	cout << "Tiempo de ejecucion: " << duracion.count() << " microsegundos" << endl;
}

int main()
{
	cout << "-----------------Bubble Sort Normal-----------------" << endl;
	cout << "Array de 10 elementos:" << endl;
    const long long int N = 1000000; // 1 millón de elementos
    set<long long int> unique_elements;

    // Generador de números aleatorios
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister pseudo-random generator
    uniform_int_distribution<long long int> dis(1, 10000000); // Rango aleatorio

    // Llenar el set con 1 millón de elementos aleatorios no repetidos
    while (unique_elements.size() < N)
    {
        unique_elements.insert(dis(gen));
    }

    // Transferir los elementos del set al arreglo
    long long int* arr = new long long int[N];
    int i = 0;
    for (auto it = unique_elements.begin(); it != unique_elements.end(); ++it, ++i)
    {
        arr[i] = *it;
    }

    // Llamar a la función bubble sort
    bubble(arr, N);

    // Limpiar memoria
    delete[] arr;

    return 0;
}