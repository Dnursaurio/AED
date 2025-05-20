#include <iostream>
using namespace std;

class Cola {
private:
    int* arreglo;
    int* frente;
    int* final;
    int capacidad;
    int cantidad;

public:
    Cola(int cap) {
        capacidad = cap;
        arreglo = new int[capacidad];
        frente = arreglo;
        final = arreglo;
        cantidad = 0;
    }

    ~Cola() {
        delete[] arreglo;
    }

    void push(int valor) {
        if (cantidad == capacidad) {
            cout << "Cola llena\n";
            return;
        }

        *final = valor;
        final++;
        cantidad++;
    }

    void pop() {
        if (cantidad == 0) {
            cout << "Cola vacía\n";
            return;
        }

        int* ptr = frente;
        for (int i = 0; i < cantidad - 1; i++) {
            *ptr = *(ptr + 1);
            ptr++;
        }

        final--;
        cantidad--;
    }

    void mostrar() {
        int* ptr = frente;
        for (int i = 0; i < cantidad; i++) {
            cout << *(ptr + i) << " ";
        }
        cout << endl;
    }

    void modificar() {
        // EJERCICIO:
        // Recorre todos los elementos de la cola y reemplaza
        // cada número impar por su negativo usando punteros.
        int* h = frente;
        for (h; h <= final; h++)
        {
            if (*h % 2 == 1)
            {
                *h = *h - 2 * *h;
            }
        }
    }
};

int main() {
    Cola c(5);  // Creamos una cola con capacidad 5

    c.push(10);
    c.push(3);
    c.push(4);
    c.push(7);

    cout << "Antes de modificar:\n";
    c.mostrar();  // Debería mostrar: 10 3 4 7

    c.modificar();  // Aquí tú debes implementar el cambio de impares a negativos

    cout << "Despues de modificar:\n";
    c.mostrar();  // Si implementas bien: 10 -3 4 -7

    return 0;
}
