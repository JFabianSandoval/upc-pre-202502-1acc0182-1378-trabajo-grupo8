#pragma once
#include "Publicacion.h"
#include <iostream>
#include <string>
using namespace std;

template <class ST>
class Feed
{
private:
	ST tipode;
	string contenido;
	int visualizaciones;

public:

	// FEED SEGUN TIPO DE PUBLICACION
	void devolverTipo()
	{
		cout << "\n--- Crear publicación tipo Feed ---\n";
		cout << "Ingrese una breve descripción o texto para el feed: ";
		cin.ignore();
		getline(cin, contenido);

		tipode = "Feed";
		visualizaciones = 0;

		cout << "Publicación tipo " << tipode << " creada correctamente.\n";
	};

	void mostrarFeed()
	{
		visualizaciones++;
		cout << "\n--- Visualización de Feed ---\n";
		cout << "Contenido: " << contenido << endl;
		cout << "Visualizaciones totales: " << visualizaciones << endl;
	};
};
