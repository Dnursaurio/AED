#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int TAM = 10000;
    int* array = new int[TAM]; // Reservar memoria din�micamente

    std::srand(std::time(nullptr)); // Inicializar la semilla aleatoria

    // Llenar el array con n�meros aleatorios
    for (int i = 0; i < TAM; i++) {
        array[i] = std::rand(); // Generar n�mero aleatorio
    }

    // Mostrar los primeros 10 n�meros como prueba
    for (int i = 0; i < 10000; i++) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;

    delete[] array; // Liberar memoria
    return 0;
}
