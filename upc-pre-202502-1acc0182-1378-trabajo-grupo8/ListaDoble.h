#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;

template <class T>
class ListaDoble {
private:
    NodoDoble<T>* cabeza;
    NodoDoble<T>* cola;

public:
    ListaDoble() {
        cabeza = nullptr;
        cola = nullptr;
    }

    NodoDoble<T>* GetCabeza() { return cabeza; }
    NodoDoble<T>* GetCola() { return cola; }

    void InsertarAlFinal(T valor) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

        if (!cabeza) {
            cabeza = cola = nuevo;
        }
        else {
            cola->SetSiguiente(nuevo);
            nuevo->SetAnterior(cola);
            cola = nuevo;
        }
    }

    void Mostrar() {
        NodoDoble<T>* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->GetDato() << " <-> ";
            actual = actual->GetSiguiente();
        }
        cout << "NULL\n";
    }
};
