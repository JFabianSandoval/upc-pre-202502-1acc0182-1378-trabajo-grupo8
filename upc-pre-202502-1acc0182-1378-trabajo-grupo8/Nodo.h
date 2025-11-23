#pragma once
#include<iostream>
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

    T GetDato() { return dato; }
    void SetDato(T val) { dato = val; }

    NodoDoble<T>* GetSiguiente() { return siguiente; }
    void SetSiguiente(NodoDoble<T>* n) { siguiente = n; }

    NodoDoble<T>* GetAnterior() { return anterior; }
    void SetAnterior(NodoDoble<T>* n) { anterior = n; }
};
