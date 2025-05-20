#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

class Lista {
private:
    Nodo* cabeza;

public:
    Lista() {
        cabeza = nullptr;
    }

    ~Lista() {
        return;
    }

    void insertar(int valor) {
        Nodo* nuevo = new Nodo{ valor, nullptr };
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }

    void mostrar() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void modificar() {
        // EJERCICIO:
        // Recorre la lista y elimina todos los nodos con valores múltiplos de 3.
        // Usa solo punteros, sin índices ni estructuras adicionales.
        // No se debe crear una nueva lista.

        // Ejemplo: Si la lista es 2 -> 6 -> 9 -> 5 -> 3
        // Resultado esperado: 2 -> 5
        Nodo** help = &cabeza;
        /*while (*help != NULL)
        {
            if ((*help)->valor % 3 == 0)
            {
                Nodo* temp = *help;
                *help = temp->siguiente;
                delete temp;
            }
            else
            {
                help = &((*help)->siguiente);
            }
        }*/
        for (help; *help; help = help)
        {
            if ((*help)->valor % 3 == 0)
            {
                Nodo* temp = *help;
                *help = temp->siguiente;
                delete temp;
            }
            else
            {
                help = &((*help)->siguiente);
            }
        }
    }
};

int main() {
    Lista lista;
    lista.insertar(2);
    lista.insertar(6);
    lista.insertar(9);
    lista.insertar(5);
    lista.insertar(3);

    cout << "Antes de modificar:\n";
    lista.mostrar();  // 2 6 9 5 3

    lista.modificar();  // Aquí tú debes implementar la lógica

    cout << "Despues de modificar:\n";
    lista.mostrar();  // Debería mostrar: 2 5

    return 0;
}
