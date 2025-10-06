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
	N fechaNotificacion; // tipo genérico para la fecha
	bool notificacionLeida;

public:

	//USUARIO SEGUN PUBLICACIONES
	void notificarUsuario()
	{
		cout << "\nIngrese el nombre del usuario a notificar: ";
		cin >> usuarioDestino;
		cout << "Ingrese el tipo de notificación (por ejemplo: comentario, reacción, nuevo seguidor): ";
		cin >> tipoNotificacion;
		cout << "Notificación enviada a " << usuarioDestino << " sobre \"" << tipoNotificacion << "\".\n";
		notificacionLeida = 0;
	};

	void marcarComoLeido()
	{
		notificacionLeida = 1;
		cout << "\nLa notificación ha sido marcada como leída.\n";
	};

	void esLeido()
	{
		if (notificacionLeida == 1)
			cout << "\nLa notificación ya fue leída.\n";
		else
			cout << "\nLa notificación aún no ha sido leída.\n";
	};
};
