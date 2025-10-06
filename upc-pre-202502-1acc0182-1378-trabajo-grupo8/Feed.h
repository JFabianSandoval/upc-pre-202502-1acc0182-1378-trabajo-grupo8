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
		cout << "\n--- Crear publicaci�n tipo Feed ---\n";
		cout << "Ingrese una breve descripci�n o texto para el feed: ";
		cin.ignore();
		getline(cin, contenido);

		tipode = "Feed";
		visualizaciones = 0;

		cout << "Publicaci�n tipo " << tipode << " creada correctamente.\n";
	};

	void mostrarFeed()
	{
		visualizaciones++;
		cout << "\n--- Visualizaci�n de Feed ---\n";
		cout << "Contenido: " << contenido << endl;
		cout << "Visualizaciones totales: " << visualizaciones << endl;
	};
};
