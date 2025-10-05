#pragma once
#include "Publicacion.h"
#include <iostream>
#include <string>
using namespace std;

template <class ST>
class Fotos
{
private:
	ST tipode;
	string descripcion;
	int cantidadLikes;
	int cantidadComentarios;

public:

	// FOTOS SEGUN TIPO DE PUBLICACION
	void devolverTipo()
	{
		cout << "\n--- Crear publicaci�n tipo Foto ---\n";
		cout << "Ingrese una descripci�n para la foto: ";
		cin.ignore();
		getline(cin, descripcion);

		tipode = "Foto";
		cantidadLikes = 0;
		cantidadComentarios = 0;

		cout << "Publicaci�n tipo " << tipode << " creada correctamente.\n";
	};

	void darLike()
	{
		cantidadLikes++;
		cout << "\nHas dado 'Me gusta' a esta foto. Total de likes: " << cantidadLikes << ".\n";
	};

	void comentarFoto()
	{
		cantidadComentarios++;
		cout << "\nHas comentado en esta foto. Total de comentarios: " << cantidadComentarios << ".\n";
	};

	void mostrarFoto()
	{
		cout << "\n--- Visualizaci�n de Foto ---\n";
		cout << "Descripci�n: " << descripcion << endl;
		cout << "Likes: " << cantidadLikes << endl;
		cout << "Comentarios: " << cantidadComentarios << endl;
	};
};
