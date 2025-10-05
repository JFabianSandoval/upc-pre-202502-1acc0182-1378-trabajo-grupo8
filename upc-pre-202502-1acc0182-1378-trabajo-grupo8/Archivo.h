#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void escribir()
{
	srand(time(NULL));
	ofstream ARCHuser;
	ARCHuser.open("Usuarios.txt", ios::out);//abriendo archivo

	if (ARCHuser.fail()) // envia un mensaje si no se pudo crear el archivo
	{
		cout << "No se pudo abrir el archivo de usuarios";
		exit(1);
	}
	//si se pudo

	//escribir el contenido del archivo
	ARCHuser << "ID: "<<(rand()%99999 + 1000)<<" | "<< "Nombre: Juan | Email: juanpa@gwdaq.com | Contraseña: 21dasuhd"<<endl;

	ARCHuser.close(); //cerrando archivo
}