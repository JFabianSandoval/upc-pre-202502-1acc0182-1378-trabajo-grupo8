#pragma once
#include <iostream>

template <class T>
class NodoDoble {
private:
    T dato;
    NodoDoble<T>* siguiente;
    NodoDoble<T>* anterior;

public:
    NodoDoble(T valor) {
        dato = valor;
        siguiente = nullptr;
        anterior = nullptr;
    }

    // Cambiado: devolvemos una referencia al dato
    T& GetDato() {
        return dato;
    }

    // Cambiado: usamos const referencia para evitar copias innecesarias
    void SetDato(const T& val) {
        dato = val;
    }

    NodoDoble<T>* GetSiguiente() { return siguiente; }
    void SetSiguiente(NodoDoble<T>* n) { siguiente = n; }

    NodoDoble<T>* GetAnterior() { return anterior; }
    void SetAnterior(NodoDoble<T>* n) { anterior = n; }
};
