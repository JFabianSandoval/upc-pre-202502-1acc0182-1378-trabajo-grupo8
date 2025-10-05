#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
//Pila

template <class P>
class NodoPila
{
private:
	P dato;
	NodoPila<P>* siguiente;
public:
	NodoPila(P& valor) :dato(valor), siguiente(nullptr) {};
	P getDato() { return dato; }
	void setDato(P& valor) { dato = valor; }
	NodoPila<P>* getSiguiente() { return siguiente; }
	void setSiguiente(NodoPila<P>* nodo) { siguiente = nodo; }

};
template <class P>
class Pila
{
private:
	NodoPila<P>* cima;
	int size;
public:
	Pila() :cima(nullptr), size(0) {}
	void push(P& valor)
	{
		NodoPila<T>* nuevoNodo = new NodoPila<T>(valor);
		nuevoNodo->setSiguiente(cima);
		cima = nuevoNodo;
		size++;
	};
	void pop()
	{
		if (estaVacia())
			throw runtime_error("Error: la pila está vacía, no se puede eliminar.");

		NodoPila<T>* nodoTemporal = cima;
		cima = cima->getSiguiente();
		delete nodoTemporal;
		size--;
	}
	P top()
	{
		if (estaVacia())
			throw runtime_error("Error: la pila está vacía, no hay elemento superior.");
		return cima->getDato();
	}

	bool estaVacia()
	{
		return cima == nullptr;
	}

	int getSize() const
	{
		return size;
	}

	void limpiar()
	{
		while (!estaVacia())
		{
			pop();
		}
	}
	void mostrar()
	{
		NodoPila<T>* actual = cima;
		cout << "Pila (top → base): ";
		while (actual != nullptr)
		{
			cout << actual->getDato() << " ";
			actual = actual->getSiguiente();
		}
		cout << endl;
	}



};


