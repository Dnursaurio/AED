#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int TAM = 10000;
    int* array = new int[TAM]; // Reservar memoria dinámicamente

    std::srand(std::time(nullptr)); // Inicializar la semilla aleatoria

    // Llenar el array con números aleatorios
    for (int i = 0; i < TAM; i++) {
        array[i] = std::rand(); // Generar número aleatorio
    }

    // Mostrar los primeros 10 números como prueba
    for (int i = 0; i < 10000; i++) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;

    delete[] array; // Liberar memoria
    return 0;
}
