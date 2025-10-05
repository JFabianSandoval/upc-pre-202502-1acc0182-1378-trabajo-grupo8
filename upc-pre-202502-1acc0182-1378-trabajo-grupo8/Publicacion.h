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
		cout << "\n--- Crear publicaci�n ---\n";
		cout << "Escribe el contenido de tu publicaci�n: ";
		cin.ignore();
		getline(cin, contenido);

		cout << "�Deseas agregar etiquetas? (1 = S� / 0 = No): ";
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
		cout << "\nPublicaci�n creada correctamente.\n";
	};

	void devolvertipo()
	{
		cout << "\n--- Tipo de publicaci�n ---\n";
		cout << "Seleccione el tipo de publicaci�n (1=Feed, 2=Foto, 3=Video, 4=Story): ";
		cin >> tipode;

		switch (tipode)
		{
		case 1:
			cout << "Tipo de publicaci�n: Feed.\n";
			break;
		case 2:
			cout << "Tipo de publicaci�n: Foto.\n";
			break;
		case 3:
			cout << "Tipo de publicaci�n: Video.\n";
			break;
		case 4:
			cout << "Tipo de publicaci�n: Story.\n";
			break;
		default:
			cout << "Tipo no v�lido.\n";
			break;
		}
	};

	void agregarComentario()
	{
		numComentarios++;
		cout << "\nSe agreg� un nuevo comentario. Total de comentarios: " << numComentarios << ".\n";
	};

	void agregarReaccion()
	{
		numReacciones++;
		cout << "\nSe agreg� una nueva reacci�n. Total de reacciones: " << numReacciones << ".\n";
	};

	void mostrarEstadisticas()
	{
		cout << "\n--- Estad�sticas de la publicaci�n ---\n";
		cout << "Comentarios: " << numComentarios << endl;
		cout << "Reacciones: " << numReacciones << endl;
		cout << "Etiquetas: " << tags << endl;
	};
};
