#pragma once
#include <iostream>
#include <functional>
#include <string>
#include "Nodo.h"
using namespace std;

template <class T>
class Lista {
private:
    Nodo<T>* inicio;
    int tam;

public:
    Lista() {
        inicio = nullptr;
        tam = 0;
    }

    int longitud() {
        return tam;
    }

    bool vacia() {
        return inicio == nullptr;
    }

    void insertarInicio(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        nuevo->siguiente = inicio;
        inicio = nuevo;
        tam++;
    }

    void insertarFinal(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);

        if (inicio == nullptr) {
            inicio = nuevo;
        }
        else {
            Nodo<T>* aux = inicio;
            while (aux->siguiente != nullptr)
                aux = aux->siguiente;
            aux->siguiente = nuevo;
        }
        tam++;
    }

    bool eliminar(function<bool(T)> criterio) {
        if (inicio == nullptr) return false;

        if (criterio(inicio->dato)) {
            Nodo<T>* temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
            tam--;
            return true;
        }

        Nodo<T>* aux = inicio;
        while (aux->siguiente != nullptr && !criterio(aux->siguiente->dato)) {
            aux = aux->siguiente;
        }

        if (aux->siguiente == nullptr) return false;

        Nodo<T>* temp = aux->siguiente;
        aux->siguiente = aux->siguiente->siguiente;
        delete temp;
        tam--;
        return true;
    }

    template<typename F>
    void recorrer(F funcion) {
        Nodo<T>* aux = inicio;
        while (aux != nullptr) {
            funcion(aux->dato);
            aux = aux->siguiente;
        }
    }

    T buscar(function<bool(T)> criterio) {
        Nodo<T>* aux = inicio;
        while (aux != nullptr) {
            if (criterio(aux->dato))
                return aux->dato;
            aux = aux->siguiente;
        }
        return nullptr;
    }
};
