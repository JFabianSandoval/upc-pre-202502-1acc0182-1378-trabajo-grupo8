#pragma once
#include <iostream>
#include "ControladoraIG.h"
using namespace std;

class MenuIG {
private:
    ControladoraIG sistema;

public:

    MenuIG() {
        cout << "\n╔════════════════════════════════════════╗\n";
        cout << "║    CARGANDO SISTEMA...                 ║\n";
        cout << "╚════════════════════════════════════════╝\n";

        sistema.cargarUsuariosDesdeArchivo();
        sistema.cargarPostsDesdeArchivo();
        sistema.cargarComentariosDesdeArchivo();
        sistema.cargarAmigosDesdeArchivo();

        cout << "\n✓ Sistema cargado exitosamente\n";
    }

    void inicio() {
        string user, pass;

        cout << "\n===== LOGIN =====\n";
        cout << "Usuario: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (!sistema.login(user, pass)) {
            return;
        }

        menuUsuario();
    }
    void menuUsuario() {
        int opc;

        do {
            cout << "\n╔═══════════════════════════════╗\n";
            cout << "║         MENÚ PRINCIPAL        ║\n";
            cout << "╠═══════════════════════════════╣\n";
            cout << "║  1.  Publicar                 ║\n";
            cout << "║  2.   Editar Post             ║\n";
            cout << "║  3.   Eliminar Post           ║\n";
            cout << "║  4.  Ver mis Posts            ║\n";
            cout << "║  5.  Ver TODOS los Posts      ║\n";  // ⭐ NUEVO
            cout << "║  6.  Comentar Post            ║\n";
            cout << "║  7.   Ver Comentarios         ║\n";  // ⭐ NUEVO
            cout << "║  8.  Agregar Amigo            ║\n";
            cout << "║  9.  Ver Amigos               ║\n";
            cout << "║ 10.  Buscar Usuario           ║\n";
            cout << "║ 11.  Buscar Posts             ║\n";
            cout << "║ 12.   Editar Perfil           ║\n";
            cout << "║ 13.  Estadísticas             ║\n";
            cout << "║ 14.  Salir                    ║\n";
            cout << "╚═══════════════════════════════╝\n";
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
                sistema.mostrarTodosLosPostsEnumerados();  // ⭐ NUEVO
                break;
            case 6:
                comentar();
                break;
            case 7:
                verComentariosDePost();  // ⭐ NUEVO
                break;
            case 8:
                agregarAmigo();
                break;
            case 9:
                sistema.mostrarAmigos();
                break;
            case 10:
                buscarUsuario();
                break;
            case 11:
                buscarPosts();
                break;
            case 12:
                editarPerfil();
                break;
            case 13:
                sistema.mostrarEstadisticasGenerales();
                break;
            case 14:
                cout << "\n👋 ¡Hasta luego!\n";
                break;
            default:
                cout << "\n✗ Opción inválida\n";
            }
        } while (opc != 14);
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
    // ⭐ NUEVOS MÉTODOS PARA REQUISITOS FUNCIONALES

    void buscarUsuario() {
        string username;
        cout << "\n===== BUSCAR USUARIO =====\n";
        cout << "Nombre de usuario: ";
        cin >> username;
        sistema.buscarYMostrarUsuario(username);
    }

    void buscarPosts() {
        string palabra;
        cout << "\n===== BUSCAR POSTS =====\n";
        cout << "Palabra clave: ";
        cin.ignore();
        getline(cin, palabra);
        sistema.mostrarResultadosBusquedaPosts(palabra);
    }

    void editarPerfil() {
        string nuevoUser, nuevoPass;
        cout << "\n===== EDITAR PERFIL =====\n";
        cout << "Nuevo username: ";
        cin >> nuevoUser;
        cout << "Nueva contraseña: ";
        cin >> nuevoPass;
        sistema.editarPerfil(nuevoUser, nuevoPass);

        cout << "\n  NOTA: Los cambios se aplicarán en esta sesión.\n";
        cout << "   Para persistir los cambios, se requiere actualizar Usuarios.txt\n";
    }

    void verComentariosDePost() {
        int id;
        cout << "\nID del Post: ";
        cin >> id;
        sistema.mostrarComentariosDePost(id);
    }
   

};