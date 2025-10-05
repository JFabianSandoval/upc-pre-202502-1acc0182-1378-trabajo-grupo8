#pragma once
#include <iostream>
using namespace std;

template <class N>
class Nodo
{
private:
    N dato;
    Nodo<N>* siguiente;

public:
    Nodo()
    {
        siguiente = nullptr;
    }
    Nodo(N valor)
    {
        dato = valor;
        siguiente = nullptr;
    }
    N GetDato()
    {
        return dato;
    }
    void SetDato(N valor)
    {
        dato = valor;
    }
    Nodo<N>* GetSiguiente()
    {
        return siguiente;
    }
    void SetSiguiente(Nodo<N>* nodo)
    {
        siguiente = nodo;
    }
};