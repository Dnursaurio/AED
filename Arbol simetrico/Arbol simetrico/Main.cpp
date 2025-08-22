#include <iostream>
using namespace std;

// Definición de la estructura del nodo del árbol
class Nodo {
public:
    int dato;
    Nodo* left;
    Nodo* right;

    // Constructor del nodo
    Nodo(int valor) {
        dato = valor;
        left = right = nullptr;
    }
};

bool EsSimetrico(Nodo* Raiz)
{
    if (Raiz == NULL)
    {
        return true;
    }
    Nodo* izq = Raiz->left;
    Nodo* der = Raiz->right;
    //pila reflejo
    Nodo* stleft[100];
    Nodo* stright[100];
    int top = 0;

    stleft[top] = izq;
    stright[top] = der;
    while (top >= 0)
    {
        Nodo* nodleft = stleft[top];
        Nodo* nodright = stright[top];
        top--;
        if (nodleft == NULL && nodright == NULL)
        {
            continue;
        }
        if (nodleft == NULL || nodright == NULL)
        {
            return false;
        }
        if (nodleft->dato != nodright->dato)
        {
            return false;
        }
        //empilamiento
        top++;
        stleft[top] = nodleft->left;
        stright[top] = nodright->right;

        top++;
        stleft[top] = nodleft->right;
        stright[top] = nodright->left;
    }
    return true;
};

int main() {
    // Árbol A
    Nodo* RaizA = new Nodo(1);
    // Nivel 2
    RaizA->left = new Nodo(2);
    RaizA->right = new Nodo(2);
    // Nivel 3
    RaizA->left->left = new Nodo(3);
    RaizA->left->right = new Nodo(4);
    RaizA->right->left = new Nodo(4);
    RaizA->right->right = new Nodo(3);
    // Nivel 4
    RaizA->left->left->left = new Nodo(5);
    RaizA->left->left->right = new Nodo(6);
    RaizA->left->right->left = new Nodo(7);
    RaizA->left->right->right = new Nodo(8);
    RaizA->right->left->left = new Nodo(8);
    RaizA->right->left->right = new Nodo(7);
    RaizA->right->right->left = new Nodo(6);
    RaizA->right->right->right = new Nodo(5);

    // Árbol B
    Nodo* RaizB = new Nodo(1);
    // Nivel 2
    RaizB->left = new Nodo(2);
    RaizB->right = new Nodo(2);
    // Nivel 3
    RaizB->left->right = new Nodo(4);
    RaizB->right->right = new Nodo(4);
    // Nivel 4
    RaizB->left->right->right = new Nodo(6);
    RaizB->right->right->left = new Nodo(6);

    // Árbol C
    Nodo* RaizC = new Nodo(10);
    // Nivel 2
    RaizC->left = new Nodo(5);
    RaizC->right = new Nodo(5);
    // Nivel 3
    RaizC->left->left = new Nodo(7);
    RaizC->left->right = new Nodo(8);
    RaizC->right->left = new Nodo(8);
    RaizC->right->right = new Nodo(7);
    // Nivel 4
    RaizC->left->left->left = new Nodo(1);
    RaizC->left->left->right = new Nodo(2);
    RaizC->left->right->left = new Nodo(3);
    RaizC->left->right->right = new Nodo(4);
    RaizC->right->left->left = new Nodo(4);
    RaizC->right->left->right = new Nodo(3);
    RaizC->right->right->left = new Nodo(2);
    RaizC->right->right->right = new Nodo(1);

    // Árbol D
    Nodo* RaizD = new Nodo(10);
    // Nivel 2
    RaizD->left = new Nodo(5);
    RaizD->right = new Nodo(5);
    // Nivel 3
    RaizD->left->left = new Nodo(7);
    RaizD->right->left = new Nodo(7);
    // Nivel 4
    RaizD->left->left->left = new Nodo(1);
    RaizD->left->left->right = new Nodo(2);
    RaizD->right->left->left = new Nodo(1);
    RaizD->right->left->right = new Nodo(3);

    cout << "Arbol A" << (EsSimetrico(RaizA) ? " es " : " no es ") << "simetrico \n";
    cout << "Arbol B" << (EsSimetrico(RaizB) ? " es " : " no es ") << "simetrico \n";
    cout << "Arbol C" << (EsSimetrico(RaizC) ? " es " : " no es ") << "simetrico \n";
    cout << "Arbol D" << (EsSimetrico(RaizD) ? " es " : " no es ") << "simetrico \n";

    return 0;
}