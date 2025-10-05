#pragma once
#include <utility>
using namespace std;
template <class N>
class Nodo
{
private:
    T dato;
    Nodo<N>* siguiente;

public:
    // Constructores
    Nodo() : dato(), siguiente(nullptr) {}
    Nodo(N& valor) : dato(valor), siguiente(nullptr) {}
    Nodo(N&& valor) : dato(move(valor)), siguiente(nullptr) {}

    // Acceso al dato
    T& GetDato() { return dato; }
    const T& GetDato() const { return dato; }
    void SetDato(const T& valor) { dato = valor; }
    void SetDato(T&& valor) { dato = move(valor); }

    // Enlace siguiente
    NodoSimple<T>* GetSiguiente() const { return siguiente; }
    void SetSiguiente(NodoSimple<T>* nodo) { siguiente = nodo; }
};