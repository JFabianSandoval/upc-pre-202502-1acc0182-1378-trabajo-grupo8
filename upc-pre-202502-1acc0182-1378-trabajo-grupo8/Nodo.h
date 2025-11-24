#pragma once

template <class T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T dato) {
        this->dato = dato;
        this->siguiente = nullptr;
    }
};
