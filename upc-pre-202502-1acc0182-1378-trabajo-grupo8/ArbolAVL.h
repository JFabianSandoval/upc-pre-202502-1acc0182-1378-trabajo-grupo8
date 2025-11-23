#pragma once 
#include <functional>
#include "NodoArbol.h"

template<typename T>
class ArbolAVL
{
private:

	NodoArbol<T>* raiz;

	typedef function<int(T, T)> Comp; //lambda
	Comp comparador; //comparador lambda para saber segun que criterio/atributo ordenar

	//puntero a funcion
	void(*procesar)(T);

	//Operaciones privadas
	int _altura(NodoArbol<T>* nodo)
	{
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}

	void _rotarDerecha(NodoArbol<T>*& nodo)
	{
		NodoArbol<T>* p = nodo->left;
		nodo->left = p->right;
		p->right = nodo;
		//Actualizamos la altura

		nodo = p;
	}

	void _rotarIzquierda(NodoArbol<T>*& nodo)
	{
		NodoArbol<T>* p = nodo->right;
		nodo->right = p->left;
		p->left = nodo;
		//Actualizamos la altura

		nodo = p;
	}
	void _balanceo(NodoArbol<T>*& nodo)
	{
		int hleft = _altura(nodo->left);
		int hright = _altura(nodo->right);
		int fb = hright - hleft;

		if (fb > 1)
		{ //rotar a la left
			int hhleft = _altura(nodo->right->left);
			int hhright = _altura(nodo->right->right);
			if (hhleft > hhright) { //verificar si aplica doble rotación
				_rotarDerecha(nodo->right);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1)
		{ //rotar a la right
			int hhleft = _altura(nodo->left->left);
			int hhright = _altura(nodo->left->right);
			if (hhleft < hhright) {//verificar si aplica doble rotación 
				_rotarIzquierda(nodo->left);
			}
			_rotarDerecha(nodo);
		}
		//Actualizar la altura del nodo raiz
		hleft = _altura(nodo->left);
		hright = _altura(nodo->right);
		nodo->altura = 1 + ((hleft > hright) ? hleft : hright);
	}

	void _enOrdenGuardar(NodoArbol<T>* nodo, ofstream& archivo)
	{
		if (nodo == nullptr)
			return;

		_enOrdenGuardar(nodo->left, archivo);

		Contribuyente* contribuyente = nodo->dato;
		archivo << contribuyente->getNumRUC() << "|"
			<< contribuyente->getNombreComercial() << "|"
			<< contribuyente->getFechaInscripcion();

		archivo << "\n";

		_enOrdenGuardar(nodo->right, archivo);
	}


public:
	ArbolAVL(void(*procesar)(T), Comp comparador)
	{
		this->procesar = procesar;
		this->comparador = comparador;
		this->raiz = nullptr;
	}
	~ArbolAVL() {}

	bool isEmpty() { return raiz == nullptr; }

	NodoArbol<T>*& getRaizRef() { return raiz; }

	NodoArbol<T>* getRaiz() { return raiz; }

	NodoArbol<T>* crearNodo(T elemento, NodoArbol<T>* padre)
	{
		NodoArbol<T>* nuevoNodo = new NodoArbol<T>;

		nuevoNodo->dato = elemento;
		nuevoNodo->right = nullptr;
		nuevoNodo->left = nullptr;
		nuevoNodo->padre = padre;

		return nuevoNodo;
	}

	void mostrarArbol(NodoArbol<T>* nodo, int cont = 0)
	{
		if (nodo == nullptr)
			return;
		else
		{
			mostrarArbol(nodo->right, cont + 1);
			for (int i = 0; i < cont; i++)
			{
				cout << "    ";
			}
			procesar(nodo->dato);
			//cout << nodo->dato->getTotalCasesPerMillion() << '\n'; 
			mostrarArbol(nodo->left, cont + 1);
		}
	}

	bool insertarNodo(NodoArbol<T>*& nodo, T nuevoDato, NodoArbol<T>* padre)
	{
		if (nodo == nullptr) //si el árbol está vacío
		{
			NodoArbol<T>* nuevoNodo = crearNodo(nuevoDato, padre);
			nodo = nuevoNodo;
			return true;
		}
		else //si el árbol no está vacío
		{
			if (nodo->dato == nuevoDato)
				return false;

			int resultado = comparador(nuevoDato, nodo->dato);

			if (resultado == 0)//si son el mismo valor
			{
				insertarNodo(nodo->left, nuevoDato, nodo); //va a la left
			}
			if (resultado < 0) //si el resultado es negativo, nuevoDato es menor
				insertarNodo(nodo->left, nuevoDato, nodo);
			else //si el resultado es positivo, nuevoDato es mayor
				insertarNodo(nodo->right, nuevoDato, nodo);
			//Si los datos son iguales deberia actuar una lista, implementala en struct Nodo

			_balanceo(nodo);
		}

		_balanceo(nodo);
		return true;
	}

	bool buscarNodo(NodoArbol<T>*& nodo, T datoBuscado)
	{
		if (nodo == nullptr)
			return false;
		//else if(nodo->dato == datoBuscado) //si es el mismo objeto
		//	return true;
		else
		{
			int resultado = comparador(datoBuscado, nodo->dato);

			if (resultado == 0)//si son el mismo valor 
				return true;
			if (resultado < 0) //si nuevoDato es menor 
				return buscarNodo(nodo->left, datoBuscado);
			else //Si nuevoDato es mayor
				return buscarNodo(nodo->right, datoBuscado);
		}
	}

	T obtenerDato(NodoArbol<T>* nodo, T datoBuscado)
	{
		if (nodo == nullptr)
			return nullptr;
		//else if (nodo->dato == datoBuscado) //si es el mismo objeto
		//	return nodo;
		else
		{
			int resultado = comparador(datoBuscado, nodo->dato);

			if (resultado == 0)//si son el mismo valor 
				return nodo->dato;
			if (resultado < 0) //si nuevoDato es menor 
				return obtenerDato(nodo->left, datoBuscado);
			else //Si nuevoDato es mayor
				return obtenerDato(nodo->right, datoBuscado);
		}
	}

	void enOrden(NodoArbol<T>* nodo)
	{
		if (nodo == nullptr)
			return;

		enOrden(nodo->left);
		procesar(nodo->dato);
		enOrden(nodo->right);
	}

	void preOrden(NodoArbol<T>* nodo)
	{
		if (nodo == nullptr)
			return;

		procesar(nodo->dato);
		preOrden(nodo->left);
		preOrden(nodo->right);
	}

	void postOrden(NodoArbol<T>* nodo)
	{
		if (nodo == nullptr)
			return;

		postOrden(nodo->left);
		postOrden(nodo->right);
		procesar(nodo->dato);
	}

	int getCantidadDeNodos(NodoArbol<T>* nodo)
	{
		if (nodo == nullptr)
			return 0;
		else
		{
			int cantLeft, cantRight;
			cantLeft = getCantidadDeNodos(nodo->left);
			cantRight = getCantidadDeNodos(nodo->right);
			return 1 + cantLeft + cantRight; //el 1 es para contar el nodo Raiz
		}
	}

	int getAltura(NodoArbol<T>* nodo)
	{
		if (nodo == nullptr)
			return 0;
		else
		{
			int alturaLeft, alturaRight;
			alturaLeft = 1 + getAltura(nodo->left);
			alturaRight = 1 + getAltura(nodo->right);
			return alturaLeft > alturaRight ? alturaLeft : alturaRight;
		}
	}

	NodoArbol<T>* getMinimo(NodoArbol<T>* nodo)
	{
		if (nodo == nullptr) //si está vacío
			return nullptr;
		else if (nodo->left == nullptr) //si ya no tiene hijo left
			return nodo;
		else //si tiene hijo left
			return getMinimo(nodo->left);
	}

	NodoArbol<T>* getMaximo(NodoArbol<T>* nodo)
	{
		if (nodo == nullptr)
			return nullptr;
		if (nodo->right == nullptr)
			return nodo;
		else
			return getMaximo(nodo->right);
	}

	void destruirNodo(NodoArbol<T>* nodoADestruir)
	{
		nodoADestruir->left = nullptr;
		nodoADestruir->right = nullptr;

		delete nodoADestruir;
	}

	void reemplazar(NodoArbol<T>* nodo, NodoArbol<T>* nuevoNodo)
	{
		if (nodo->padre) //si tiene padre
		{
			//asignar al padre su nuevo hijo
			if (nodo->dato == nodo->padre->left->dato)
				nodo->padre->left = nuevoNodo;
			else if (nodo->dato == nodo->padre->right->dato)
				nodo->padre->right = nuevoNodo;
		}

		if (nuevoNodo)
		{
			nuevoNodo->padre = nodo->padre;
		}
	}

	void eliminarNodo(NodoArbol<T>* nodoAEliminar)
	{
		if (nodoAEliminar->left && nodoAEliminar->right) //Si sus hijos existen/si tiene 2 hijos
		{
			NodoArbol<T>* menor = getMinimo(nodoAEliminar->right);
			nodoAEliminar->dato = menor->dato;
			eliminarNodo(menor);
		}
		else if (nodoAEliminar->left) //si tiene un hijo left
		{
			reemplazar(nodoAEliminar, nodoAEliminar->left);
			destruirNodo(nodoAEliminar);
		}
		else if (nodoAEliminar->right) //si tiene un hijo right
		{
			reemplazar(nodoAEliminar, nodoAEliminar->right);
			destruirNodo(nodoAEliminar);
		}
		else //Si no tiene hijos
		{
			reemplazar(nodoAEliminar, nullptr);
			destruirNodo(nodoAEliminar);
		}
	}

	bool eliminar(NodoArbol<T>* nodo, T datoAEliminar)
	{
		if (nodo == nullptr)
			return false;

		int resultado = comparador(datoAEliminar, nodo->dato);

		if (resultado < 0) //si el resultado es negativo, datoAEliminar es menor
			eliminar(nodo->left, datoAEliminar);
		else if (resultado > 0) //si el resultado es positivo, datoAEliminar es mayor
			eliminar(nodo->right, datoAEliminar);
		else //  r==0 es porque se encontró el elemento e en el arbol
		{
			eliminarNodo(nodo);
			return true;
		}
		return false;
	}

	void guardarEnArchivo(NodoArbol<T>* nodo, const string& filename)
	{
		ofstream archivo(filename, ios::out | ios::trunc);
		if (archivo.is_open())
		{
			_enOrdenGuardar(nodo, archivo);
			archivo.close();
		}
		else
		{
			cout << "No se pudo abrir el archivo para escribir." << endl;
		}
	}
};
