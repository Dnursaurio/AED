#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int* head = arr;
    int* tail = arr + n - 1;
    int* helper_a = head;
    int* helper_b = helper_a + 1;

    for (helper_a; helper_a < tail; helper_a++)
    {
        int* helper_b = helper_a + 1;
        for (helper_b; helper_b <= tail; helper_b++)
        {
            if (*helper_a > *helper_b)
            {
                int temp = *helper_b;
                int* r = helper_b;
                for (r; r > helper_a; r--)
                {
                    *r = *(r - 1);
                }
                *helper_a = temp;
            }
        }
    }

}

int main() {
    int datos[] = { 5, 2, 4, 6, 1, 3 };
    int n = sizeof(datos) / sizeof(datos[0]);

    insertionSort(datos, n);

    for (int i = 0; i < n; i++)
        cout << datos[i] << " ";
    return 0;
}