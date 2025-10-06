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
		cout << "\n--- Crear publicación tipo Video ---\n";
		cout << "Ingrese el título del video: ";
		cin.ignore();
		getline(cin, titulo);

		cout << "Ingrese la duración del video (en segundos): ";
		cin >> duracion;

		tipode = "Video";
		reproducciones = 0;
		likes = 0;

		cout << "Publicación tipo " << tipode << " creada correctamente.\n";
	};

	void reproducir()
	{
		reproducciones++;
		cout << "\nReproduciendo video: " << titulo << endl;
		cout << "Duración: " << duracion << " segundos." << endl;
		cout << "Total de reproducciones: " << reproducciones << endl;
	};

	void darLike()
	{
		likes++;
		cout << "\nHas dado 'Me gusta' a este video. Total de likes: " << likes << ".\n";
	};

	void mostrarEstadisticas()
	{
		cout << "\n--- Estadísticas del Video ---\n";
		cout << "Título: " << titulo << endl;
		cout << "Duración: " << duracion << " segundos" << endl;
		cout << "Reproducciones: " << reproducciones << endl;
		cout << "Likes: " << likes << endl;
	};
};
