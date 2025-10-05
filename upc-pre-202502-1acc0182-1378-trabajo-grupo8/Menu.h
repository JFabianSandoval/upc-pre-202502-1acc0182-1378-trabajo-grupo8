#pragma once
#include<iostream>
#include<functional>
#include<map>

using namespace std;
using namespace System;

int main() {
    int tipo;
    cout << "Ingrese tipo de usuario (1 = Usuario, 2 = Admin): ";
    cin >> tipo;

    if (tipo == 1) {
        cout << "\n--- Menu Usuario ---\n";
        cout << "1. Ver perfil\n";
        cout << "2. Ver amigos\n";
        cout << "3. Salir\n";

        map<int, function<void()>> menuUsuario = {
            {1, []() { cout << "Mostrando perfil del usuario...\n"; }},
            {2, []() { cout << "Listando de amigos agregados...\n"; }},
            {3, []() { cout << "Saliendo del menu de usuario...\n"; }}
        };

        int opcion;
        do {
            cout << "\nSeleccione una opcion: ";
            cin >> opcion;

            if (menuUsuario.count(opcion))
                menuUsuario[opcion]();
            else
                cout << "Opcion invalida.\n";

        } while (opcion != 3);
    }
    else if (tipo == 2) {
        cout << "\n--- Menu Administrador ---\n";
        cout << "1. Ver reportes\n";
        cout << "2. Gestionar usuarios\n";
        cout << "3. Salir\n";

        map<int, function<void()>> menuAdmin = {
            {1, []() { cout << "Mostrando reportes del sistema...\n"; }},
            {2, []() { cout << "Gestionando usuarios...\n"; }},
            {3, []() { cout << "Saliendo del menu de administrador...\n"; }}
        };

        int opcion;
        do {
            cout << "\nSeleccione una opcion: ";
            cin >> opcion;

            if (menuAdmin.count(opcion))
                menuAdmin[opcion]();
            else
                cout << "Opcion invalida.\n";

        } while (opcion != 3);
    }
    else {
        cout << "Tipo de usuario invalido.\n";
    }

    return 0;
}