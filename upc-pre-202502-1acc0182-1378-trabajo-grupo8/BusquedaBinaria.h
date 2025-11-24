#pragma once
#include <iostream>
#include <string>
using namespace std;

class BusquedaBinaria {
public:
    //Búsqueda binaria recursiva en array de strings
    static int buscar(string arr[], int inicio, int fin, string objetivo) {
        if (inicio > fin) {
            return -1; // No encontrado
        }

        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == objetivo) {
            return medio; // Encontrado
        }

        if (arr[medio] > objetivo) {
            return buscar(arr, inicio, medio - 1, objetivo);
        }
        else {
            return buscar(arr, medio + 1, fin, objetivo);
        }
    }

    //Búsqueda binaria iterativa
    static int buscarIterativo(string arr[], int n, string objetivo) {
        int inicio = 0;
        int fin = n - 1;

        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;

            if (arr[medio] == objetivo) {
                return medio;
            }

            if (arr[medio] > objetivo) {
                fin = medio - 1;
            }
            else {
                inicio = medio + 1;
            }
        }

        return -1;
    }
};