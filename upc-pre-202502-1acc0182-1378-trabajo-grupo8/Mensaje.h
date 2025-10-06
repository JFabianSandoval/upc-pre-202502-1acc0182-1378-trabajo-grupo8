#pragma once
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;

class Mensaje
{
private:
	string remitente;
	string destinatario;
	string contenido;

public:

	// MÉTODOS SEGÚN EL DIAGRAMA UML
	void enviarMensaje()
	{
		cout << "\n--- Enviar mensaje ---\n";
		cout << "Ingrese el nombre del destinatario: ";
		cin >> destinatario;
		cin.ignore();
		cout << "Escribe tu mensaje: ";
		getline(cin, contenido);

		cout << "\nMensaje enviado a \"" << destinatario << "\": " << contenido << endl;
	};

	void recibirMensaje()
	{
		cout << "\nHas recibido un nuevo mensaje de \"" << remitente << "\": " << contenido << endl;
	};

	void crearGruposDeChat()
	{
		cout << "\n--- Crear grupo de chat ---\n";
		cout << "Ingrese el nombre del grupo: ";
		string nombreGrupo;
		cin.ignore();
		getline(cin, nombreGrupo);
		cout << "El grupo \"" << nombreGrupo << "\" ha sido creado exitosamente.\n";
	};

	void eliminarMensaje()
	{
		cout << "\nIngrese el contenido o ID del mensaje que desea eliminar: ";
		string mensaje;
		cin.ignore();
		getline(cin, mensaje);
		cout << "El mensaje \"" << mensaje << "\" ha sido eliminado correctamente.\n";
	};
};
