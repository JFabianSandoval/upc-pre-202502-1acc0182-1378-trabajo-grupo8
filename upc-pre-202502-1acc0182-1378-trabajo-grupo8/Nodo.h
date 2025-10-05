#pragma once
#include <utility>
using namespace std;
template <class N>
class Nodo
{
private:
    N dato;
    Nodo<N>* siguiente;

public:
    // Constructores
    Nodo() : dato(), siguiente(nullptr) {}
    Nodo(N& valor) : dato(valor), siguiente(nullptr) {}
    Nodo(N&& valor) : dato(move(valor)), siguiente(nullptr) {}

    // Acceso al dato
    void SetDato(N& valor) { dato = valor; }
    void SetDato(N&& valor) { dato = move(valor); }

    // Enlace siguiente
    Nodo<N>* GetSiguiente() const { return siguiente; }
    void SetSiguiente(Nodo<N>* nodo) { siguiente = nodo; }
};