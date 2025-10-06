#pragma once
#include "Persona.h"
#include <iostream>
#include <string>
using namespace std;

template <class U>
class Usuario : public Persona<U>
{
private:
	int amigos;
	bool estado; // si es 1 esta activo si es 0 inactivo

public:
	Usuario(int id, string nombres, string correo, string contrasenia,
		bool estadoUsuario, string tipo, int numSeguidores, int numPublicaciones)
		: Persona<U>(id, nombres, correo, contrasenia) 
	{
		estado = estadoUsuario;
		tipoUsuario = tipo;
		seguidores = numSeguidores;
		publicaciones = numPublicaciones;
	}
	Usuario()
	{
		amigos = 0;
		estado = 0;
	}

	//USUARIO SEGUN PUBLICACIONES
	void registrarse()
	{
		cout << "\n--- Registro de nuevo usuario ---\n";
		string correo;
		U nombre, ape1, ape2, contra;

		cout << "Nombre: ";
		cin >> nombre;
		cout << "Apellido paterno: ";
		cin >> ape1;
		cout << "Apellido materno: ";
		cin >> ape2;
		cout << "Correo: ";
		cin >> correo;
		cout << "Contraseña: ";
		cin >> contra;

		this->establecerNombres(nombre);
		this->establecerApellidoPaterno(ape1);
		this->establecerApellidoMaterno(ape2);
		this->establecerCorreo(correo);
		this->establecerContrasenia(contra);
		estado = 1;

		cout << "\nUsuario registrado correctamente.\n";
	};

	void iniciarSesion()
	{
		cout << "\n--- Inicio de sesión ---\n";
		string correoIngresado;
		U contraIngresada;

		cout << "Correo: ";
		cin >> correoIngresado;
		cout << "Contrasenia: ";
		cin >> contraIngresada;

		if (this->validarInicioSesion(correoIngresado, contraIngresada))
		{
			estado = 1;
			cout << "Inicio de sesion exitoso.\n";
		}
		else
		{
			cout << "Correo o contraseña incorrectos.\n";
		}
	};

	void cerrarSesion()
	{
		if (estado == 1)
		{
			estado = 0;
			cout << "Sesión cerrada correctamente.\n";
		}
		else
		{
			cout << "No hay una sesión activa.\n";
		}
	};

	void crearPost()
	{
		cout << "\nEscribe el contenido de tu publicación: ";
		string contenido;
		cin.ignore();
		getline(cin, contenido);
		cout << "\nPublicación creada: \"" << contenido << "\"\n";
	};

	void editarPost()
	{
		cout << "\nSelecciona la publicación que deseas editar (simulado)...\n";
		cout << "Publicación editada correctamente.\n";
	};

	void compartirPost()
	{
		cout << "\nHas compartido una publicación.\n";
	};

	void publicarPost()
	{
		cout << "\nTu publicación ha sido publicada exitosamente.\n";
	};

	void eliminarPost()
	{
		cout << "\nPublicación eliminada correctamente.\n";
	};

	void reportar()
	{
		cout << "\nHas reportado una publicacion o usuario.\n";
	};
	void cambiarContraseña() {
		cout<<"Vas a cambiar contrasenia."
	};
	// USUARIO SEGUN SOLICITUDES DE AMISTAD
	void enviarSoli()
	{
		cout << "\nSolicitud de amistad enviada.\n";
	};

	void reportarUsuario()
	{
		cout << "\nHas reportado a un usuario.\n";
	};

	void eliminarSoli()
	{
		cout << "\nHas cancelado una solicitud de amistad.\n";
	};

	void aceptarAmigo()
	{
		amigos++;
		cout << "\nHas aceptado una solicitud. Ahora tienes " << amigos << " amigos.\n";
	};

	void agregarAmigo()
	{
		amigos++;
		cout << "\nHas agregado un nuevo amigo. Total: " << amigos << " amigos.\n";
	};

	void eliminarAmigo()
	{
		if (amigos > 0)
		{
			amigos--;
			cout << "\nHas eliminado un amigo. Ahora tienes " << amigos << " amigos.\n";
		}
		else
		{
			cout << "\nNo tienes amigos que eliminar.\n";
		}
	};

	void bloquearAmigo()
	{
		cout << "\nHas bloqueado a un usuario.\n";
	};

	// VIEWERS SEGUN PUBLICACIONES
	void comentar()
	{
		string comentario;
		cout << "\nEscribe tu comentario: ";
		cin.ignore();
		getline(cin, comentario);
		cout << "Comentario publicado: \"" << comentario << "\"\n";
	};

	void eliminarComentario()
	{
		cout << "\nComentario eliminado.\n";
	};

	void responderComentario()
	{
		string respuesta;
		cout << "\nEscribe tu respuesta: ";
		cin.ignore();
		getline(cin, respuesta);
		cout << "Respuesta enviada: \"" << respuesta << "\"\n";
	};

	//SEGUIDORES
	void verSeguidores()
	{
		cout << "\nMostrando lista de seguidores (simulado)...\n";
	};
	// --- Métodos Getters ---
	string obtenercorreo()
	{
		return correo;
	}
	string obtenerContrasenia()
	{
		return contrasenia;
	}




};