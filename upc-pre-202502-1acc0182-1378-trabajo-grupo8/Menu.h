#pragma once
#include<iostream>
#include<functional>
#include<map>

#include"Usuario.h"
#include"Admin.h"

using namespace std;
using namespace System;

void iniciarsesion(string &email, string &contrasenia)
{
    cout << "Nombre: " << email << endl;
    cout << "Contraseña: " << contrasenia;
}


template <class U>
void mostrarMenuUsuario(Usuario<U>& usuario) {

    cout << "\n--- Menu Usuario ---\n";
    cout << "1. Ver perfil\n";
    cout << "2. Ver amigos\n";
    cout << "3. Agregar amigos\n";
    cout << "4. Eliminar amigos\n";
    cout << "5. Crear post\n";
    cout << "6. Editar post\n";
    cout << "7. Compartir post\n";
    cout << "8. Eliminar post\n";
    cout << "9. Cambiar contrasenia\n";
    cout << "10. Bloquear usuario\n";
    cout << "11. Cerrar sesion\n";

    map<int, function<void()>> menuUsuario = {
        {1, []() { cout << "Mostrando perfil del usuario...\n"; }},
        {2, [&usuario]() { usuario.verSeguidores(); }},
        {3, [&usuario]() { usuario.agregarAmigo(); }},
        {4, [&usuario]() { usuario.eliminarAmigo(); }},
        {5, [&usuario]() { usuario.crearPost(); }},
        {6, [&usuario]() { usuario.editarPost(); }},
        {7, [&usuario]() { usuario.compartirPost(); }},
        {8, [&usuario]() { usuario.eliminarPost(); }},
       // {9, [&usuario]() { usuario.cambiarContraseña(); }}, en conflicto
        {10, [&usuario]() { usuario.bloquearAmigo(); }},
        {11, [&usuario]() { usuario.cerrarSesion(); }}
    };

    int opcion;
    do {
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        if (menuUsuario.count(opcion))
            menuUsuario[opcion]();
        else
            cout << "Opcion invalida.\n";

    } while (opcion != 11);
}

template <class Ad>
void mostrarMenuAdministrador(Admin<Ad>& admin) {
    cout << "\n--- Menu Administrador ---\n";
    cout << "1. Gestionar usuarios\n";
    cout << "2. Banear usuario\n";
    cout << "3. Restaurar usuario\n";
    cout << "4. Eliminar post\n";
    cout << "5. Ver reportes\n";
    cout << "6. Resolver reportes\n";
    cout << "7. Gestionar contenido\n";
    cout << "8. Gestionar publicidad\n";
    cout << "9. Validar contenido\n";
    cout << "10. Salir de administrador\n";

    map<int, function<void()>> menuAdmin = {
       // {1, [&admin]() { admin.gestionarUsuarios(); }}, en conflicto
        {2, [&admin]() { admin.banearUsuario(); }},
        {3, [&admin]() { admin.restaurarUsuario(); }},
        {4, [&admin]() { admin.eliminarPost(); }},
        {5, [&admin]() { admin.revisarReportes(); }},
        {6, [&admin]() { admin.resolverReportes(); }},
        {7, [&admin]() { admin.gestionarContenido(); }},
        {8, [&admin]() { admin.gestionarPublicidad(); }},
        {9, [&admin]() { admin.validadContenido(); }},
        {10, []() { cout << "Saliendo del menu de administrador...\n"; }}
    };

    int opcion;
    do {
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        if (menuAdmin.count(opcion))
            menuAdmin[opcion]();
        else
            cout << "Opcion invalida.\n";

    } while (opcion != 10);
}
