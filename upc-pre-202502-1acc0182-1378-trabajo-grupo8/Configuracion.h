#pragma once
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;

template <class C>
class Configuracion
{
private:
	string privacidadPerfil;
	C idioma;
	bool permitirMensajesDesconocidos;
	bool permitirEtiqueta;
	bool permitir;

public:

	//CONFIG SEGUN PRIVACIDAD
	void cuentaPublica()
	{
		privacidadPerfil = "P�blica";
		cout << "\nTu cuenta ahora es p�blica. Todos los usuarios pueden ver tu perfil y publicaciones.\n";
	};

	void cuentaPrivada()
	{
		privacidadPerfil = "Privada";
		cout << "\nTu cuenta ahora es privada. Solo tus amigos o seguidores pueden ver tu contenido.\n";
	};

	void privarVisualizacionDeContenido()
	{
		cout << "\n�Deseas ocultar tu contenido a ciertos usuarios? (1 = S�, 0 = No): ";
		int opcion;
		cin >> opcion;
		if (opcion == 1)
			cout << "Selecciona los usuarios que no podr�n ver tu contenido (simulado)...\n";
		else
			cout << "No se modific� la visibilidad de tu contenido.\n";
	};

	//CONFIG SEGUN IDIOMA
	void idiomaDelContenido()
	{
		cout << "\nIngrese el idioma que desea establecer (por ejemplo: Espa�ol, Ingl�s, Franc�s): ";
		cin >> idioma;
		cout << "El idioma de tu cuenta ahora es: " << idioma << ".\n";
	};
};
