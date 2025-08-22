#include <iostream>
#include <vector>
#include <list>
using namespace std;

class CSMatrix
{
private:
    //desarrollar una tabl hash
    struct Elem
    {
        int x;
        int y;
        int val;
        Elem(int x_, int y_, int valor_) :x(x_), y(y_), val(valor_) {}
    };
    int dimx, dimy;
    int table_size;
    vector<list<Elem>> tabla;
    //Funcion de hasheo
    int hash(int x, int y)
    {
        return (x * dimy + y) % table_size;
    }

public:
    CSMatrix(int dx, int dy, int ts)
    {
        dimx = dx;
        dimy = dy;
        table_size = ts;
        tabla.resize(ts);
    }

    int get(int x, int y)
    {
        int h = hash(x, y);
        for (auto& e : tabla[h])
        {
            if (e.x == x && e.y == y)
            {
                return e.val;
            }
        }
        return 0;
    }

    void set(int x, int y, int v)
    {
        int h = hash(x, y);
        for (auto it = tabla[h].begin(); it != tabla[h].end(); it++)
        {
            if (it->x == x && it->y == y)
            {
                if (it->val == 0)
                {
                    tabla[h].erase(it);
                }
                else
                {
                    it->val = v;
                }
                return;
            }
        }
        if (v != 0)
        {
            tabla[h].push_back(Elem(x, y, v));
        }
    }

    void print()
    {
        for (int i = 0; i < dimx; i++)
        {
            for (int j = 0; j < dimy; j++)
            {
                cout << get(i, j) << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    CSMatrix m(5, 5, 7); // Matriz 5x5 con tabla hash de tamaño 7

    cout << "1. Matriz inicial (vacía):" << endl;
    m.print();
    cout << endl;

    cout << "2. Insertando nuevos elementos:" << endl;
    m.set(0, 0, 5);  // Esquina superior izquierda
    m.set(4, 4, 8);  // Esquina inferior derecha
    m.set(2, 2, 3);  // Centro
    m.set(1, 3, 6);  // Posición arbitraria
    m.print();
    cout << endl;

    cout << "3. Modificando elementos existentes:" << endl;
    m.set(0, 0, 9);  // Cambiar 5 por 9
    m.set(2, 2, 7);  // Cambiar 3 por 7
    m.print();
    cout << endl;

    cout << "4. Eliminando elementos (poniendo 0):" << endl;
    m.set(0, 0, 0);  // Eliminar el 9
    m.set(2, 2, 0);  // Eliminar el 7
    m.print();
    cout << endl;

    cout << "5. Intentando eliminar elementos en posiciones vacías:" << endl;
    m.set(3, 3, 0);  // Intentar eliminar en posición vacía
    m.print();
    cout << endl;

    cout << "6. Operaciones mixtas:" << endl;
    m.set(1, 1, 2);  // Insertar nuevo
    m.set(1, 1, 4);  // Modificar existente
    m.set(1, 1, 0);  // Eliminar existente
    m.set(1, 1, 0);  // Intentar eliminar ya eliminado
    m.print();
    cout << endl;

    return 0;
}
