#pragma once
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;
template <class S>
class Seguidores : public Persona<S>
{
private:
	bool estado; // 1 = solicitud aceptada, 0 = pendiente o rechazada

public:

	// SEGUIDORES SEGUN SOLICITUDES
	void aceptarSolicitud()
	{
		estado = 1;
		cout << "\nHas aceptado la solicitud de seguimiento. Ahora esta persona puede ver tus publicaciones.\n";
	};

	void rechazarSolicitud()
	{
		estado = 0;
		cout << "\nHas rechazado la solicitud de seguimiento.\n";
	};

	void bloquearUsuario()
	{
		cout << "\nIngrese el nombre del usuario que desea bloquear: ";
		string usuario;
		cin >> usuario;
		cout << "El usuario \"" << usuario << "\" ha sido bloqueado y ya no podrá seguirte ni enviarte solicitudes.\n";
	};
};
