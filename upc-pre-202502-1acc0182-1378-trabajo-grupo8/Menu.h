#pragma once
#include<iostream>
#include<functional>
#include<map>

using namespace std;
using namespace System;

void mostrarMenuUsuario() {

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
        {2, []() { cout << "Mostrar listado de amigos...\n"; }},
        {3, []() { cout << "Agregar amigos...\n"; }},
        {4, []() { cout << "Eliminar amigos...\n"; }},
        {5, []() { cout << "Creando nuevo post...\n"; }},
        {6, []() { cout << "Editando post...\n"; }},
        {7, []() { cout << "Compartiendo post...\n"; }},
        {8, []() { cout << "Eliminando post...\n"; }},
        {9, []() { cout << "Cambiando contrasenia...\n"; }},
        {10, []() { cout << "Bloqueando usuario...\n"; }},
        {11, []() { cout << "Cerrando sesion del usuario...\n"; }}
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

void mostrarMenuAdministrador() {
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
        {1, []() { cout << "Mostrando reportes del sistema...\n"; }},
        {2, []() { cout << "Gestionando usuarios...\n"; }},
        {3, []() { cout << "Baneando usuario...\n"; }},
        {4, []() { cout << "Restaurando usuario...\n"; }},
        {5, []() { cout << "Eliminando post...\n"; }},
        {6, []() { cout << "Mostrando reportes...\n"; }},
        {7, []() { cout << "Resolviendo reportes...\n"; }},
        {8, []() { cout << "Gestionando contenido...\n"; }},
        {9, []() { cout << "Gestionando publicidad...\n"; }},
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
