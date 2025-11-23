#include <iostream>
#include "ListaDoble.h"   // Tu lista doble
using namespace std;

void menuUsuario();
void menuPosts();
void menuComentarios();
void mostrarMenuPrincipal();

int main() {
    int opcion;

    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuUsuario();
            break;
        case 2:
            menuPosts();
            break;
        case 3:
            menuComentarios();
            break;
        case 0:
            cout << "\nSaliendo del programa...\n";
            break;
        default:
            cout << "Opción inválida. Intenta nuevamente.\n";
        }

    } while (opcion != 0);

    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n======= MENU PRINCIPAL =======\n";
    cout << "1. Gestionar Usuarios\n";
    cout << "2. Gestionar Posts\n";
    cout << "3. Gestionar Comentarios\n";
    cout << "0. Salir\n";
    cout << "Selecciona una opción: ";
}

/* ---------------------------
   MENÚS SECUNDARIOS
   (versiones simples)
----------------------------*/

void menuUsuario() {
    int op;
    do {
        cout << "\n--- MENU DE USUARIOS ---\n";
        cout << "1. Registrar usuario\n";
        cout << "2. Mostrar usuarios\n";
        cout << "3. Buscar usuario\n";
        cout << "0. Volver\n";
        cout << "Selecciona: ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "(aquí irá registrar usuario)\n";
            break;
        case 2:
            cout << "(aquí irá mostrar usuarios)\n";
            break;
        case 3:
            cout << "(aquí irá buscar usuario)\n";
            break;
        case 0:
            break;
        default:
            cout << "Opción inválida.\n";
        }

    } while (op != 0);
}

void menuPosts() {
    int op;
    do {
        cout << "\n--- MENU DE POSTS ---\n";
        cout << "1. Crear Post\n";
        cout << "2. Mostrar Posts\n";
        cout << "3. Buscar Post\n";
        cout << "0. Volver\n";
        cout << "Selecciona: ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "(aquí irá crear post)\n";
            break;
        case 2:
            cout << "(aquí irá mostrar posts)\n";
            break;
        case 3:
            cout << "(aquí irá buscar post)\n";
            break;
        case 0:
            break;
        default:
            cout << "Opción inválida.\n";
        }

    } while (op != 0);
}

void menuComentarios() {
    int op;
    do {
        cout << "\n--- MENU DE COMENTARIOS ---\n";
        cout << "1. Crear comentario\n";
        cout << "2. Mostrar comentarios\n";
        cout << "3. Buscar comentario\n";
        cout << "0. Volver\n";
        cout << "Selecciona: ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "(aquí irá crear comentario)\n";
            break;
        case 2:
            cout << "(aquí irá mostrar comentarios)\n";
            break;
        case 3:
            cout << "(aquí irá buscar comentario)\n";
            break;
        case 0:
            break;
        default:
            cout << "Opción inválida.\n";
        }

    } while (op != 0);
}
