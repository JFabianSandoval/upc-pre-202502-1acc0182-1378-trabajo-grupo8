#pragma once
#include "Persona.h"
#include <iostream>
#include <string>
using namespace std;

template <class A>
class Admin : public Persona<A>
{
private:
	bool esAdmin;
	int amigos;

public:

	//ADMIN SEGUN USUARIO
	void banearUsuario()
	{
		cout << "\nIngrese el nombre del usuario que desea banear: ";
		string usuario;
		cin >> usuario;
		cout << "El usuario \"" << usuario << "\" ha sido baneado temporalmente del sistema.\n";
	};

	void suspenderUsuario()
	{
		cout << "\nIngrese el nombre del usuario a suspender: ";
		string usuario;
		cin >> usuario;
		cout << "El usuario \"" << usuario << "\" ha sido suspendido por incumplir las normas.\n";
	};

	void restaurarUsuario()
	{
		cout << "\nIngrese el nombre del usuario a restaurar: ";
		string usuario;
		cin >> usuario;
		cout << "El usuario \"" << usuario << "\" ha sido restaurado correctamente.\n";
	};

	//ADMIN SEGUN ELIMINAR
	void eliminarComentario()
	{
		cout << "\nIngrese el ID o contenido del comentario a eliminar: ";
		string comentario;
		cin.ignore();
		getline(cin, comentario);
		cout << "Comentario \"" << comentario << "\" eliminado correctamente del sistema.\n";
	};

	void eliminarPost()
	{
		cout << "\nIngrese el ID o título de la publicación a eliminar: ";
		string publicacion;
		cin.ignore();
		getline(cin, publicacion);
		cout << "La publicación \"" << publicacion << "\" ha sido eliminada correctamente.\n";
	};

	//ADMIN SEGUN REPORTES
	void revisarReportes()
	{
		cout << "\nMostrando lista de reportes recientes (simulado)...\n";
		cout << "1. Usuario reportado por lenguaje inapropiado.\n";
		cout << "2. Publicación con contenido ofensivo.\n";
		cout << "3. Comentario denunciado por spam.\n";
		cout << "\nFin de la lista de reportes.\n";
	};

	void resolverReportes()
	{
		cout << "\nIngrese el ID del reporte que desea resolver: ";
		int id;
		cin >> id;
		cout << "Reporte #" << id << " resuelto correctamente.\n";
	};

	//ADMIN SEGUN CONTENIDO
	void gestionarContenido()
	{
		cout << "\nAccediendo a las opciones de gestión de contenido...\n";
		cout << "1. Revisar publicaciones.\n";
		cout << "2. Revisar historias.\n";
		cout << "3. Revisar comentarios.\n";
		cout << "\nContenido revisado correctamente.\n";
	};

	void gestionarPublicidad()
	{
		cout << "\nMostrando panel de gestión de publicidad (simulado)...\n";
		cout << "1. Revisar campañas activas.\n";
		cout << "2. Aprobar nuevas solicitudes.\n";
		cout << "3. Eliminar anuncios inapropiados.\n";
		cout << "Publicidad actualizada exitosamente.\n";
	};

	void validadContenido()
	{
		cout << "\nIngrese el ID del contenido a validar: ";
		int id;
		cin >> id;
		cout << "El contenido #" << id << " ha sido validado y aprobado correctamente.\n";
	};
};
