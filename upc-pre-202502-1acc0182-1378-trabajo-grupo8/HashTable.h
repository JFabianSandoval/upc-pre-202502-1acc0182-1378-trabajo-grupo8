#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "Lista.h"
using namespace std;

template <class T>
class HashTable {
private:
    vector<Lista<T>*> tabla;  // Ahora usa Lista en lugar de vector
    int capacidad;
    int colisionesReportadas = 0;

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
        // Inicializar cada posición con una lista vacía
        for (int i = 0; i < capacidad; i++) {
            tabla[i] = new Lista<T>();
        }
    }

    // Insertar con detección de colisiones a partir de 4 elementos
    void insertar(string clave, T valor) {
        int idx = hashFunction(clave);

        // Detectar colisión si ya hay 4 o más elementos
        if (tabla[idx]->longitud() >= 4) {
            colisionesReportadas++;
            cout << "[COLISION #" << colisionesReportadas << "] En índice " << idx
                << " - Elementos actuales: " << tabla[idx]->longitud() << endl;
        }

        tabla[idx]->insertarFinal(valor);
    }

    //Buscar en la tabla hash
    T buscar(function<bool(T)> criterio) {
        for (int i = 0; i < capacidad; i++) {
            T resultado = tabla[i]->buscar(criterio);
            if (resultado != nullptr)
                return resultado;
        }
        return nullptr;
    }

    //Obtener todos los elementos de una clave (idPost)
    Lista<T>* obtenerPorClave(string clave) {
        int idx = hashFunction(clave);
        return tabla[i];
    }

    // Mostrar estadísticas de colisiones
    void mostrarEstadisticas() {
        cout << "\n===== ESTADÍSTICAS HASHTABLE =====\n";
        cout << "Capacidad: " << capacidad << endl;
        cout << "Colisiones detectadas (>=4): " << colisionesReportadas << endl;

        int bucketUsados = 0;
        int maxColisiones = 0;

        for (int i = 0; i < capacidad; i++) {
            int tam = tabla[i]->longitud();
            if (tam > 0) {
                bucketUsados++;
                if (tam > maxColisiones) maxColisiones = tam;
            }
        }

        cout << "Buckets utilizados: " << bucketUsados << "/" << capacidad << endl;
        cout << "Máximo de elementos en un bucket: " << maxColisiones << endl;
        cout << "==================================\n";
    }

    ~HashTable() {
        for (int i = 0; i < capacidad; i++) {
            delete tabla[i];
        }
    }
};