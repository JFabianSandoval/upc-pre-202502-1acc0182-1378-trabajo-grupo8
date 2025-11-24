#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

template <class T>
class HashTable {
private:
    vector<vector<T>> tabla;
    int capacidad;

    int hashFunction(string clave) {
        unsigned long hash = 5381;
        for (char c : clave)
            hash = ((hash << 5) + hash) + c;
        return hash % capacidad;
    }

public:
    HashTable(int capacidad = 50) {
        this->capacidad = capacidad;
        tabla.resize(capacidad);
    }

    void insertar(string clave, T valor) {
        int idx = hashFunction(clave);
        tabla[idx].push_back(valor);
    }

    T buscar(function<bool(T)> criterio) {//1
        for (int i = 0; i < capacidad; i++) {//1+n(adentro)+1 => n²
            for (T valor : tabla[i]) {//1 + n (adentro)+1 => n
                if (criterio(valor)) return valor;//1
            }
        }
        return nullptr;//1
    }//Valoración O(n²)
};
