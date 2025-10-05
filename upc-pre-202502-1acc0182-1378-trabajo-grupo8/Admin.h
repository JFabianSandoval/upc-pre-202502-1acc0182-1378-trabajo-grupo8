#pragma once
#include"Persona.h"

template<class A>
class Admin : public Persona<A>
{
private:
	bool esAdmin;
	int amigos;
public:
#if 1
	//ADMIN SEGUN USUARIO
	void gestionarUsuarios() {

	};
	void banearUsuario() {

	};
	void suspenderUsuario() {

	};
	void restaurarUsuario() {

	};
	//ADMIN SEGUN ELIMINAR
	void eliminarComentario()
	{

	};
	void eliminarPost()
	{

	};
	//ADMIN SEGUN REPORTES
	void revisarReportes()
	{

	};
	void resolverReportes() {

	};
	//ADMIN SEGUN CONTENIDO
	void gestionarContenido() {

	};
	void gestionarPublicidad() {

	};
	void validadContenido() {

	};
#endif

};