#pragma once
#include "Persona.h"

/*El usuario es publicador y tambien viewer*/
template <class U>
class Usuario : public Persona<U>
{
private:
	int amigos;
	bool estado; // si es 1 esta activo si es 0 inactivo

public:
#if 1
	//USUARIO SEGUN PUBLICACIONES
	void registrarse() {

	};
	void iniciarSesion() {

	};
	void cerrarSesion() {

	};
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
	void cambiarContraseña() {
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
	void aceptarAmigo()// creo que este void es lo mismo que agregar amigo
	{
	};
	void agregarAmigo(){

	};
	void eliminarAmigo()
	{
	};
	void bloquearAmigo()
	{
	};
	// VIEWERS SEGUN PUBLICACIONES
	void comentar()
	{

	};
	void eliminarComentario()
	{

	};
	void responderComentario()
	{

	};
	//SEGUIDORES
	void verSeguidores() {

	}
#endif

};