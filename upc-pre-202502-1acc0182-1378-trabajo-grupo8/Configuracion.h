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
		privacidadPerfil = "Pública";
		cout << "\nTu cuenta ahora es pública. Todos los usuarios pueden ver tu perfil y publicaciones.\n";
	};

	void cuentaPrivada()
	{
		privacidadPerfil = "Privada";
		cout << "\nTu cuenta ahora es privada. Solo tus amigos o seguidores pueden ver tu contenido.\n";
	};

	void privarVisualizacionDeContenido()
	{
		cout << "\n¿Deseas ocultar tu contenido a ciertos usuarios? (1 = Sí, 0 = No): ";
		int opcion;
		cin >> opcion;
		if (opcion == 1)
			cout << "Selecciona los usuarios que no podrán ver tu contenido (simulado)...\n";
		else
			cout << "No se modificó la visibilidad de tu contenido.\n";
	};

	//CONFIG SEGUN IDIOMA
	void idiomaDelContenido()
	{
		cout << "\nIngrese el idioma que desea establecer (por ejemplo: Español, Inglés, Francés): ";
		cin >> idioma;
		cout << "El idioma de tu cuenta ahora es: " << idioma << ".\n";
	};
};
