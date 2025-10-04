#pragma once
#include "Persona.h"

/*El usuario es publicador y tambien viewer*/
template <class U>
class Usuario : public Persona<U>
{
private:
	bool esAdmin;
	int amigos;
public:
#if 0
	//USUARIO SEGUN PUBLICACIONES
	void crearPost()
	{
		
	};
	void publicarPost()
	{
	};
	void eliminarPost()
	{
	};
	void reportar()
	{
	};
	// USUARIO SEGUN SOLICITUDES DE AMISTAD
	void enviarSoli()
	{
	};
	void eliminarSoli()
	{
	};
	void aceptarAmigo()
	{
	};
	eliminarAmigo()
	{
	};
	bloquearAmigo()
	{
	};
	// VIEWERS SEGUN PUBLICACIONES
	comentar()
	{

	};
	eliminarComentario()
	{

	};
	responderComentario()
	{

	};
#endif

};