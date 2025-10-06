#pragma once
#pragma once
#include <iostream>
using namespace std;

// Función para intercambiar dos elementos
template <class T>
void intercambiar(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Función de partición
template <class T>
int particion(T arr[], int inicio, int fin)
{
    T pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++)
    {
        if (arr[j] <= pivote)
        {
            i++;
            intercambiar(arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[fin]);
    return i + 1;
}

// Función recursiva QuickSort
template <class T>
void quicksort(T arr[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int indicePivote = particion(arr, inicio, fin);

        // Llamadas recursivas
        quicksort(arr, inicio, indicePivote - 1);
        quicksort(arr, indicePivote + 1, fin);
    }
}

void pruebaQuickSort()
{
    int numeros[] = {42, 5, 20, 7, 15, 3, 60};
    int n = sizeof(numeros) / sizeof(numeros[0]);

    cout << "\nAntes de ordenar: ";
    for (int i = 0; i < n; i++) cout << numeros[i] << " ";

    quicksort(numeros, 0, n - 1);

    cout << "\nDespues de ordenar: ";
    for (int i = 0; i < n; i++) cout << numeros[i] << " ";
    cout << endl;
}
