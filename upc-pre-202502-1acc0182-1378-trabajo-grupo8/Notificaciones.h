#pragma once
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;

template <class N>
class Notificaciones
{
private:
	string usuarioDestino;
	string tipoNotificacion;
	N fechaNotificacion; // tipo gen�rico para la fecha
	bool notificacionLeida;

public:

	//USUARIO SEGUN PUBLICACIONES
	void notificarUsuario()
	{
		cout << "\nIngrese el nombre del usuario a notificar: ";
		cin >> usuarioDestino;
		cout << "Ingrese el tipo de notificaci�n (por ejemplo: comentario, reacci�n, nuevo seguidor): ";
		cin >> tipoNotificacion;
		cout << "Notificaci�n enviada a " << usuarioDestino << " sobre \"" << tipoNotificacion << "\".\n";
		notificacionLeida = 0;
	};

	void marcarComoLeido()
	{
		notificacionLeida = 1;
		cout << "\nLa notificaci�n ha sido marcada como le�da.\n";
	};

	void esLeido()
	{
		if (notificacionLeida == 1)
			cout << "\nLa notificaci�n ya fue le�da.\n";
		else
			cout << "\nLa notificaci�n a�n no ha sido le�da.\n";
	};
};
