#pragma once
#include "Usuario.h"
template <class N>
class Notificaciones :
{
private:
	string usuarioDestino;
	string tipoNotificacion;
	N fechaNotificacion;    // tipo genérico para la fecha
	bool notificacionLeida;
public:
#if 0
	//USUARIO SEGUN PUBLICACIONES
	void notificarUsuario() {

	};
	void marcarComoLeido() {

	};
	void esLeido() {

	};
#endif

};