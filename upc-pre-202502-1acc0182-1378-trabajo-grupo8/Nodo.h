#pragma once
#include <iostream>
template <class N>
class Nodo
{
private:
	N dato;
	Nodo<N>* siguiente;
public:
	Nodo(int valor)
	{
		dato = valor;
		siguiente = nullptr;//crea un nodo vacio 
	}
	//GETTER AND SETTER
	N GetDato() { return dato; }
	void SetDato(int valor) { dato = valor; }
	Nodo<N>* GetSiguiente() { return siguiente; }
	void SetSiguiente(Nodo<N>* nodo) { siguiente = nodo; }

};