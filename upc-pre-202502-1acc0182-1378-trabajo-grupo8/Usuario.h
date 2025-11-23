#pragma once
#include "Persona.h"
#include "Cuenta.h"
#include <iostream>
#include <string>
using namespace std;

template <class U>
class Usuario : public Persona<U>, public Cuenta
{
private:
	int amigos;
	bool estado; // 1 = activo | 0 = inactivo
	bool validarInicioSesion(const U& correoIngresado, const U contraIngresada)const
	{
		return(this->getCorreo() == correoIngresado) && (this->getContrasenia() == contraIngresada);
	}
public:
	//CONSTRUCTORES
	Usuario() :Persona<U>(0, "", "", "", "", "") {};
	Usuario(short _id, U _nombres, U _paterno, U _materno, string _correo, U _contrasenia)
		: Persona<U>(_id, _nombres, _paterno, _materno, _correo, _contrasenia) {};

	void iniciarSesion(const string& _correo, const U& _contra) override
	{
		if (validarInicioSesion(_correo, _contra))
		{
			estado = true;
			cout << "[User] Inicio de Sesion Exitoso" << endl;
		}
		else
		{
			cout << "[User] Correo o Contraseña son incorrectos" << endl;
		}
	}
	void cerrarSesion()override
	{
		if (estado)
		{
			estado = false;
			cout << "[User] Sesión Cerrada" << endl;
		}
		else
		{
			cout << "[User] No hay Sesion Activa" << endl;
		}
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

		this->setNombres(nombre);
		this->setApellidoPaterno(ape1);
		this->setApellidoMaterno(ape2);
		this->setcorreo(correo);
		this->setContrasenia(contra);

		estado = 1;

		cout << "\nUsuario registrado correctamente.\n";
	};
	void crearPost(string contenido)override
	{
		if (!estado)
		{
			cout << "[User] Debes Iniciar Sesión" << endl;
		}
		else
		{
			cout << "[User] Post Creado con Exito" << endl;
			cout << "Contenido:" << endl;
			cout << contenido;
		}
	};
	void editarPost(int idPos,const string& nuevoContenido)override
	{
		if(!estado)
		{
			cout << "[User] Debes Iniciar Sesion" << endl;
		}
		else
		{
			cout << "[User] Post Editado con Exito" << endl;
			cout << "[User] Post " << idPos << " editado a: " <<endl<< nuevoContenido << endl;
		}
	};
	void eliminarPost(int idPos)override
	{
		if (!estado)
		{
			cout << "[User] Debes Iniciar Sesion" << endl;
		}
		else
		{
			cout << "[User] Eliminaste tu Post " << idPos << endl;
		}
	};
	void comentar(int idPos, const string& comentario)override
	{
		if (!estado)
		{
			cout << "[User] Debes Iniciar Sesion" << endl;
		}
		else
		{
			cout << "[User] Comentaste este Post " << idPos << endl << "Comentario: " << comentario << endl;
		}
	};
	void eliminarComentario(int idComentario)override
	{
		if (!estado)
		{
			cout << "[User] Debes Iniciar Sesion" << endl;
		}
		else
		{
			cout << "[User] Eliminaste tu comentario " << idComentario << ".\n";
		}
	};
	void reportarUsuario(int idUsuario) override
	{
		cout << "[User] Reportaste al usuario " << idUsuario << ".\n";
	};
	void agregarAmigo()
	{
		++amigos;
		cout << "Ahora tienes " << amigos << " amigos.\n";
	};
	void eliminarAmigo()
	{
		if (amigos > 0)
		{
			--amigos;
			cout << "Ahora tienes " << amigos << " amigos.\n";
		}
		else
		{
			cout << "No tienes amigos que eliminar.\n";
		}
	};
	void verPanel() const override
	{
		cout << "Panel de Usuario (básico): crear/editar/eliminar tus posts, comentar y reportar.\n";
	}


	/*
	void cambiarContrasenia(const string& nueva)
	{
		this->setContrasenia(nueva);
		cout << "[User] Contraseña actualizada.\n";
	};
	*/
};