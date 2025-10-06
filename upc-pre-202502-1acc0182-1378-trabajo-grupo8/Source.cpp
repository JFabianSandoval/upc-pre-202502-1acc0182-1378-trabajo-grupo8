#include <iostream>
#include "Librerias.h"
#include "Menu.h"
#include "Usuario.h"
#include "Admin.h"
#include "Windows.h"
using namespace std;
using namespace System;
int main() {
    short tipo,op;
    while (true)
    {

    cout << "Ingrese tipo de usuario (1 = Usuario, 2 = Admin): ";
    cout << "Credenciales de Usuario: pepito@upc.edu.pe | Contraseña: upc2020";


    cin >> tipo;
    string email, contrasenia;
    Usuario<string> usuario1;
    Admin<string> admin1;

    ListaSimple<Usuario<string>> listauser;
    ListaSimple<Seguidores<string>> listafollowers;

    if (tipo == 1)
    {
        iniciarsesion(email,contrasenia);
        mostrarMenuUsuario(usuario1);

    }
    else if (tipo == 2)
    {
        mostrarMenuAdministrador(admin1);
    }
    else
    {
        cout << "Tipo de usuario invalido.\n";
        system("pause");
        system("cls");
    }


    }
    return 0;
}
