#pragma once 
#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T>
class Cola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	int tam;
public:
	Cola()
	{
		this->inicio = nullptr;
		this->fin = nullptr;
		this->tam = 0;
	}

	Nodo<T>* getInicio() { return inicio; }

	int getTam() { return tam; }
	void setTam(int tam) { this->tam = tam; }
	int getTamIncrementado() { return tam + 1; }

	bool esVacia()
	{
		return (inicio == nullptr);
	}

	void encolar(T dato) //agrega un dato al final
	{
		Nodo<T>* newNodo = new Nodo<T>(dato);//1
		if (esVacia())//1
		{
			inicio = newNodo;//1
			fin = inicio;//1
		}
		else
		{
			fin->siguiente = newNodo;//1
			fin = newNodo;//1
		}

		tam++;//1
	}//Valoración O(1)

	T desencolar()  //devuelve el primer dato y lo elimina
	{
		if (esVacia())
		{
			cout << "La cola está vacía" << '\n';
			return T();
		}

		T dato = inicio->dato;
		Nodo<T>* temp = inicio;

		if (inicio == fin) //si solo hay 1 elemento
		{
			inicio = nullptr;
			fin = nullptr;
		}
		else
			inicio = inicio->siguiente;

		delete temp;
		tam--;
		return dato;
	}

	T peek() //obtener 1er dato
	{
		if (esVacia())
		{
			cout << "La cola está vacía" << '\n';
			return T();
		}
		return inicio->dato;
	}

	template<class Func>
	void mostrar(Func funcionMostrar)
	{
		if (esVacia()) {
			cout << "No se han registrado elementos." << '\n';
			return;
		}

		Nodo<T>* temp = inicio;
		while (temp != nullptr)
		{
			if (temp->dato != nullptr) {
				(temp->dato->*funcionMostrar)(); // Asegúrate de que T tenga el método mostrarDatos 
			}
			temp = temp->siguiente;
		}
	}

	float obtenerSumaSegunAtributo()
	{
		float montoTotal = 0;

		if (esVacia())
			cout << "No se han registrado elementos." << '\n';
		else
		{
			for (Nodo<T>* aux = inicio; aux != nullptr; aux = aux->siguiente)
			{
				if (aux->dato != nullptr)
					montoTotal += aux->dato->getMonto(); //Asegurarse q T tenga el metodo getMonto 
			}
		}

		return montoTotal;
	}
};

