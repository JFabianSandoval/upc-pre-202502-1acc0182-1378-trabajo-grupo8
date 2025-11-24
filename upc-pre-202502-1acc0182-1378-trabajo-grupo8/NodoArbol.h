#pragma once 

template<class T>
class NodoArbol
{
public:
	T dato;
	NodoArbol<T>* right; //derecha
	NodoArbol<T>* left; //izquierda
	NodoArbol<T>* padre;
	int altura;
public:
	NodoArbol()
	{
		altura = 1;
		this->right = nullptr;
		this->left = nullptr;
		this->padre = nullptr;
	}

	~NodoArbol() {}
};

