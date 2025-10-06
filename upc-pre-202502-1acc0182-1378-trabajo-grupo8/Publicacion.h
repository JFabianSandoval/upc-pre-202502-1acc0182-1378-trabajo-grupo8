#pragma once
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;

template <class PU>
class Publicacion
{
private:
	PU idPublicaciones;
	int numComentarios;
	int numReacciones;
	PU tags;
	int tipode; // 1 = feed, 2 = foto, 3 = video, 4 = story
	string contenido;

public:
	// PUBLICACION SEGUN CONTENIDO
	void contenidoPublicacion()
	{
		cout << "\n--- Crear publicación ---\n";
		cout << "Escribe el contenido de tu publicación: ";
		cin.ignore();
		getline(cin, contenido);

		cout << "¿Deseas agregar etiquetas? (1 = Sí / 0 = No): ";
		int opcion;
		cin >> opcion;
		if (opcion == 1)
		{
			cout << "Ingresa tus etiquetas (separadas por comas): ";
			cin.ignore();
			getline(cin, tags);
		}
		else
		{
			tags = "Sin etiquetas";
		}

		numComentarios = 0;
		numReacciones = 0;
		cout << "\nPublicación creada correctamente.\n";
	};

	void devolvertipo()
	{
		cout << "\n--- Tipo de publicación ---\n";
		cout << "Seleccione el tipo de publicación (1=Feed, 2=Foto, 3=Video, 4=Story): ";
		cin >> tipode;

		switch (tipode)
		{
		case 1:
			cout << "Tipo de publicación: Feed.\n";
			break;
		case 2:
			cout << "Tipo de publicación: Foto.\n";
			break;
		case 3:
			cout << "Tipo de publicación: Video.\n";
			break;
		case 4:
			cout << "Tipo de publicación: Story.\n";
			break;
		default:
			cout << "Tipo no válido.\n";
			break;
		}
	};

	void agregarComentario()
	{
		numComentarios++;
		cout << "\nSe agregó un nuevo comentario. Total de comentarios: " << numComentarios << ".\n";
	};

	void agregarReaccion()
	{
		numReacciones++;
		cout << "\nSe agregó una nueva reacción. Total de reacciones: " << numReacciones << ".\n";
	};

	void mostrarEstadisticas()
	{
		cout << "\n--- Estadísticas de la publicación ---\n";
		cout << "Comentarios: " << numComentarios << endl;
		cout << "Reacciones: " << numReacciones << endl;
		cout << "Etiquetas: " << tags << endl;
	};
};
