#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;
template <class L>
class ListaSimple
{
private:
	Nodo<L>* cabeza;
public:
	ListaSimple() { cabeza = nullptr; }
	~ListaSimple() {}
	Nodo<L>* GetCabeza()
	{
		return cabeza;
	}
	void InsertarAlFinal(L valor)
	{
		Nodo<L>* nuevoNodo = new Nodo<L>(valor);
		if (cabeza == nullptr)
		{
			cabeza = nuevoNodo;
		}
		else
		{
			Nodo<L>* temp = cabeza;
			while (temp->GetSiguiente())
			{
				temp = temp->GetSiguiente();
				cout << "Funciona";
			}
			temp->SetSiguiente(nuevoNodo);
			cout << endl << "El nodo fue insertado al final";
		}
	}
	void InsertarAlInicio(L valor)
	{
		Nodo<L>* nuevoNodo = new Nodo<L>(valor);
		if (cabeza == nullptr)
		{
			cabeza = nuevoNodo;
		}
		else //ya hay elementos 
		{
			nuevoNodo->SetSiguiente(cabeza);
			cabeza = nuevoNodo;
		}
	};
	void EliminarAlFinal()
	{
		if (cabeza == nullptr)
		{
			cout << "Lista Vacia";
			return;
		}
		else if (cabeza->GetSiguiente() == nullptr)//solo si hay un nodo
		{
			delete cabeza;
			cabeza == nullptr;
			return;
		}
		Nodo<L>* temp = cabeza;
		while (temp->GetSiguiente()->GetSiguiente() != nullptr)
		{
			temp = temp->GetSiguiente();
		}
		delete temp->GetSiguiente();
		temp->SetSiguiente(nullptr);


	};
	void EliminarAlInicio()
	{
		if (cabeza == nullptr)
		{
			cout << "Lista Vacia";
			return;
		}
		else if (cabeza->GetSiguiente() == nullptr)//solo si hay un nodo
		{
			delete cabeza;
			cabeza == nullptr;
			return;
		}
		Nodo<L>* temp = cabeza;
		cabeza = cabeza->GetSiguiente();
		delete temp;
	};
	void BuscarElemento(L valor)
	{
		if (cabeza == nullptr)
		{
			cout << "Lista Vacia";
		}
		else
		{
			Nodo<L>* temp = cabeza;
			while (temp != nullptr)
			{
				if (temp->GetDato() == valor)
				{
					cout << "El valor esta en la lista." << endl;
					return;
				}
				temp = temp->GetSiguiente();
			}
			cout << "No esta el elemento o valor en la lista" << endl;
		}

	};
	void MostrarLista()
	{
		if (cabeza == nullptr)
		{
			cout << endl << "LISTA VACIA";
			return;
		}
		Nodo<L>* temp = cabeza;
		cout << endl << "Elementos de la lista: ";
		while (temp != nullptr)
		{
			cout << temp->GetDato();
			if (temp->GetSiguiente() != nullptr)
			{
				cout << " -> ";
			}
			temp = temp->GetSiguiente();
		}
		cout << " -> NULL";
	}
};
