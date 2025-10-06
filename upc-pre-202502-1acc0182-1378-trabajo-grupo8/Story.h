#pragma once
#include "Publicacion.h"
#include <iostream>
#include <string>
using namespace std;

template <class ST>
class Story
{
private:
	ST tipode;
	string titulo;
	double duracion; // en segundos
	int reproducciones;
	int likes;

public:

	// VIDEOS SEGUN TIPO DE PUBLICACION
	void devolverTipo()
	{
		cout << "\n--- Crear publicaci�n tipo Video ---\n";
		cout << "Ingrese el t�tulo del video: ";
		cin.ignore();
		getline(cin, titulo);

		cout << "Ingrese la duraci�n del video (en segundos): ";
		cin >> duracion;

		tipode = "Video";
		reproducciones = 0;
		likes = 0;

		cout << "Publicaci�n tipo " << tipode << " creada correctamente.\n";
	};

	void reproducir()
	{
		reproducciones++;
		cout << "\nReproduciendo video: " << titulo << endl;
		cout << "Duraci�n: " << duracion << " segundos." << endl;
		cout << "Total de reproducciones: " << reproducciones << endl;
	};

	void darLike()
	{
		likes++;
		cout << "\nHas dado 'Me gusta' a este video. Total de likes: " << likes << ".\n";
	};

	void mostrarEstadisticas()
	{
		cout << "\n--- Estad�sticas del Video ---\n";
		cout << "T�tulo: " << titulo << endl;
		cout << "Duraci�n: " << duracion << " segundos" << endl;
		cout << "Reproducciones: " << reproducciones << endl;
		cout << "Likes: " << likes << endl;
	};
};
