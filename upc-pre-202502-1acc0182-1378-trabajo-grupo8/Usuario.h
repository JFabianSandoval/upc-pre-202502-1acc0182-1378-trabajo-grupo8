﻿#pragma once
#include "Persona.h"

/*El usuario es publicador y tambien viewer*/
template <class U>
class Usuario : public Persona<U>
{
private:
	bool esAdmin;
	int amigos;
	string nombre;
	string email;
	bool estado; // si es 1 esta activo si es 0 inactivo
	U contraseña;

public:
#if 0
	//USUARIO SEGUN PUBLICACIONES
	void crearPost()
	{

	};
	void editarPost(){

	};
	void compartirPost() {

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
	void reportarUsuario() {

	}
	void eliminarSoli()
	{
	};
	void aceptarAmigo()
	{
	};
	void eliminarAmigo()
	{
	};
	void bloquearAmigo()
	{
	};
	// VIEWERS SEGUN PUBLICACIONES
	comentar()
	{

	};
	eliminarComentario()
	{

#endif

	};