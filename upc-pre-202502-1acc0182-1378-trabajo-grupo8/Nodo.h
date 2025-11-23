#pragma once
#include <iostream>
using namespace std;

template <class N>
class Nodo
{
private:
    N dato;
    Nodo<N>* siguiente;
    Nodo<N>* anterior;

public:
    Nodo() : siguiente(nullptr), anterior(nullptr) {}

    Nodo(N valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}

    N GetDato() const {
        return dato;
    }
    void SetDato(N valor) {
        dato = valor;
    }

    Nodo<N>* GetSiguiente() const {
        return siguiente;
    }
    void SetSiguiente(Nodo<N>* nodo) {
        siguiente = nodo;
    }

    Nodo<N>* GetAnterior() const {
        return anterior;
    }
    void SetAnterior(Nodo<N>* nodo) {
        anterior = nodo;
    }
};
