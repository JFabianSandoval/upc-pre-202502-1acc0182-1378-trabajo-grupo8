#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;

// se supone que con estas modificaciones ya fucniona como lista doble 


template <class L>
class ListaDoble
{
private:
    Nodo<L>* cabeza;
    Nodo<L>* cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    ~ListaDoble() {}

    Nodo<L>* GetCabeza() { return cabeza; }
    Nodo<L>* GetCola() { return cola; }

    // INSERTAR AL FINAL
    void InsertarAlFinal(L valor)
    {
        Nodo<L>* nuevo = new Nodo<L>(valor);

        if (cabeza == nullptr)
        {
            cabeza = cola = nuevo;
        }
        else
        {
            cola->SetSiguiente(nuevo);
            nuevo->SetAnterior(cola);
            cola = nuevo;
        }
        cout << "Insertado al final: " << valor << endl;
    }

    // INSERTAR AL INICIO
    void InsertarAlInicio(L valor)
    {
        Nodo<L>* nuevo = new Nodo<L>(valor);

        if (cabeza == nullptr)
        {
            cabeza = cola = nuevo;
        }
        else
        {
            nuevo->SetSiguiente(cabeza);
            cabeza->SetAnterior(nuevo);
            cabeza = nuevo;
        }
        cout << "Insertado al inicio: " << valor << endl;
    }

    // ELIMINAR AL INICIO
    void EliminarAlInicio()
    {
        if (cabeza == nullptr)
        {
            cout << "Lista vacía\n";
            return;
        }

        if (cabeza == cola)
        {
            delete cabeza;
            cabeza = cola = nullptr;
            return;
        }

        Nodo<L>* temp = cabeza;
        cabeza = cabeza->GetSiguiente();
        cabeza->SetAnterior(nullptr);
        delete temp;
    }

    // ELIMINAR AL FINAL
    void EliminarAlFinal()
    {
        if (cabeza == nullptr)
        {
            cout << "Lista vacía\n";
            return;
        }

        if (cabeza == cola)
        {
            delete cabeza;
            cabeza = cola = nullptr;
            return;
        }

        Nodo<L>* temp = cola;
        cola = cola->GetAnterior();
        cola->SetSiguiente(nullptr);
        delete temp;
    }

    // BUSCAR
    void BuscarElemento(L valor)
    {
        Nodo<L>* temp = cabeza;

        while (temp != nullptr)
        {
            if (temp->GetDato() == valor)
            {
                cout << "Elemento encontrado: " << valor << endl;
                return;
            }
            temp = temp->GetSiguiente();
        }

        cout << "Elemento NO encontrado\n";
    }

    // MOSTRAR DE INICIO A FIN
    void MostrarLista()
    {
        Nodo<L>* temp = cabeza;

        cout << "Lista -> ";
        while (temp != nullptr)
        {
            cout << temp->GetDato();
            if (temp->GetSiguiente() != nullptr)
                cout << " <-> ";
            temp = temp->GetSiguiente();
        }
        cout << " -> NULL\n";
    }

    // NUEVO: MOSTRAR DE FIN A INICIO
    void MostrarReversa()
    {
        Nodo<L>* temp = cola;

        cout << "Reversa -> ";
        while (temp != nullptr)
        {
            cout << temp->GetDato();
            if (temp->GetAnterior() != nullptr)
                cout << " <-> ";
            temp = temp->GetAnterior();
        }
        cout << " -> NULL\n";
    }

};
