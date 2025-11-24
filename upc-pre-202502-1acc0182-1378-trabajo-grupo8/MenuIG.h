#pragma once
#include <iostream>
#include "ControladoraIG.h"
using namespace std;

class MenuIG {
private:
    ControladoraIG sistema;

public:
    void inicio() {
        string user, pass;

        cout << "===== LOGIN =====\n";
        cout << "Usuario: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (!sistema.login(user, pass)) {
            cout << "Credenciales incorrectas.\n";
            return;
        }

        menuUsuario();
    }

    void menuUsuario() {
        int opc;

        do {
            cout << "\n===== MENU USUARIO =====\n";
            cout << "1. Publicar\n";
            cout << "2. Editar Post\n";
            cout << "3. Eliminar Post\n";
            cout << "4. Ver mis Posts\n";
            cout << "5. Comentar Post\n";
            cout << "6. Agregar Amigo\n";
            cout << "7. Ver Amigos\n";
            cout << "8. Salir\n";
            cout << "Opción: ";
            cin >> opc;

            switch (opc) {
            case 1:
                publicar();
                break;
            case 2:
                editar();
                break;
            case 3:
                eliminar();
                break;
            case 4:
                sistema.mostrarMisPosts();
                break;
            case 5:
                comentar();
                break;
            case 6:
                agregarAmigo();
                break;
            case 7:
                sistema.mostrarAmigos();
                break;
            }
        } while (opc != 8);
    }

    void publicar() {
        string contenido;
        cout << "Contenido: ";
        cin.ignore();
        getline(cin, contenido);
        sistema.publicarPost(contenido, "2025");
    }

    void editar() {
        int id;
        string contenido;
        cout << "ID del Post: ";
        cin >> id;
        cout << "Nuevo contenido: ";
        cin.ignore();
        getline(cin, contenido);
        sistema.editarPost(id, contenido);
    }

    void eliminar() {
        int id;
        cout << "ID del Post: ";
        cin >> id;
        sistema.eliminarPost(id);
    }

    void comentar() {
        int id;
        string texto;
        cout << "ID del Post: ";
        cin >> id;
        cout << "Comentario: ";
        cin.ignore();
        getline(cin, texto);
        sistema.comentarPost(id, texto, "2025");
    }

    void agregarAmigo() {
        string amigo;
        cout << "Agregar amigo: ";
        cin >> amigo;
        sistema.agregarAmigo(amigo);
    }
};
