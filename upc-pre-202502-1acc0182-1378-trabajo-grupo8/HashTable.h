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

    T buscar(function<bool(T)> criterio) {
        for (int i = 0; i < capacidad; i++) {
            for (T valor : tabla[i]) {
                if (criterio(valor)) return valor;
            }
        }
        return nullptr;
    }
};
