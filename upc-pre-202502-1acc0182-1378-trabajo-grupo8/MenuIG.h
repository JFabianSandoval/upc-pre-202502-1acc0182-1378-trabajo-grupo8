#pragma once
#include <iostream>
#include <cstdlib>
#include "ControladoraIG.h"
using namespace std;

class MenuIG {
private:
    ControladoraIG sistema;

    void limpiarPantalla() {
        system("cls");
    }

    void pausa() {
        cout << "\nPresiona ENTER para continuar...";
        cin.ignore();
        cin.get();
    }

    void mostrarEncabezado(string titulo) {
        cout << "+";
        for (int i = 0; i < 50; i++) cout << "-";
        cout << "+\n";

        cout << "|";
        int espacios = (50 - titulo.length()) / 2;
        for (int i = 0; i < espacios; i++) cout << " ";
        cout << titulo;
        for (int i = 0; i < 50 - espacios - titulo.length(); i++) cout << " ";
        cout << "|\n";

        cout << "+";
        for (int i = 0; i < 50; i++) cout << "-";
        cout << "+\n\n";
    }

public:
    MenuIG() {
        limpiarPantalla();
        mostrarEncabezado("CARGANDO SISTEMA");

        sistema.cargarUsuariosDesdeArchivo();
        sistema.cargarPostsDesdeArchivo();
        sistema.cargarComentariosDesdeArchivo();
        sistema.cargarAmigosDesdeArchivo();

        cout << "\n[OK] Sistema cargado exitosamente\n";
        pausa();
    }

    void inicio() {
        limpiarPantalla();
        string user, pass;

        mostrarEncabezado("LOGIN");
        cout << "Usuario: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (!sistema.login(user, pass)) {
            pausa();
            return;
        }

        menuUsuario();
    }

    void menuUsuario() {
        int opc;

        do {
            limpiarPantalla();
            cout << "+------------------------------------------+\n";
            cout << "|          MENU PRINCIPAL                  |\n";
            cout << "+------------------------------------------+\n";
            cout << "|  1. Publicar                             |\n";
            cout << "|  2. Editar Post                          |\n";
            cout << "|  3. Eliminar Post                        |\n";
            cout << "|  4. Ver mis Posts                        |\n";
            cout << "|  5. Ver TODOS los Posts                  |\n";
            cout << "|  6. Comentar Post                        |\n";
            cout << "|  7. Ver Comentarios de Post              |\n";
            cout << "|  8. Agregar Amigo                        |\n";
            cout << "|  9. Ver Amigos                           |\n";
            cout << "| 10. Buscar Usuario                       |\n";
            cout << "| 11. Buscar Posts                         |\n";
            cout << "| 12. Editar Perfil                        |\n";
            cout << "| 13. Estadisticas                         |\n";
            cout << "| 14. Salir                                |\n";
            cout << "+------------------------------------------+\n";

            cout << "\nOpcion: ";
            cin >> opc;

            limpiarPantalla();

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
                mostrarEncabezado("MIS POSTS");
                sistema.mostrarMisPosts();
                pausa();
                break;
            case 5:
                mostrarEncabezado("TODOS LOS POSTS");
                sistema.mostrarTodosLosPostsEnumerados();
                pausa();
                break;
            case 6:
                comentar();
                break;
            case 7:
                verComentariosDePost();
                break;
            case 8:
                agregarAmigo();
                break;
            case 9:
                mostrarEncabezado("MIS AMIGOS");
                sistema.mostrarAmigos();
                pausa();
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
                mostrarEncabezado("ESTADISTICAS");
                sistema.mostrarEstadisticasGenerales();
                pausa();
                break;
            case 14:
                limpiarPantalla();
                cout << "\n\n         Hasta luego!\n\n";
                break;
            default:
                cout << "\n[ERROR] Opcion invalida\n";
                pausa();
            }
        } while (opc != 14);
    }

    void publicar() {
        mostrarEncabezado("PUBLICAR POST");
        string contenido;
        cout << "Contenido: ";
        cin.ignore();
        getline(cin, contenido);
        sistema.publicarPost(contenido, "2025");
        pausa();
    }

    void editar() {
        mostrarEncabezado("EDITAR POST");
        int id;
        string contenido;
        cout << "ID del Post: ";
        cin >> id;
        cout << "Nuevo contenido: ";
        cin.ignore();
        getline(cin, contenido);

        if (sistema.editarPost(id, contenido)) {
            cout << "\n[OK] Post editado exitosamente\n";
        }
        else {
            cout << "\n[ERROR] No se pudo editar el post\n";
        }
        pausa();
    }

    void eliminar() {
        mostrarEncabezado("ELIMINAR POST");
        int id;
        cout << "ID del Post: ";
        cin >> id;

        if (sistema.eliminarPost(id)) {
            cout << "\n[OK] Post eliminado\n";
        }
        else {
            cout << "\n[ERROR] No se pudo eliminar el post\n";
        }
        pausa();
    }

    void comentar() {
        mostrarEncabezado("COMENTAR POST");
        int id;
        string texto;
        cout << "ID del Post: ";
        cin >> id;
        cout << "Comentario: ";
        cin.ignore();
        getline(cin, texto);
        sistema.comentarPost(id, texto, "2025");
        pausa();
    }

    void verComentariosDePost() {
        mostrarEncabezado("VER COMENTARIOS");
        int id;
        cout << "ID del Post: ";
        cin >> id;
        sistema.mostrarComentariosDePost(id);
        pausa();
    }

    void agregarAmigo() {
        mostrarEncabezado("AGREGAR AMIGO");
        string amigo;
        cout << "Nombre de usuario: ";
        cin >> amigo;
        sistema.agregarAmigo(amigo);
        pausa();
    }

    void buscarUsuario() {
        mostrarEncabezado("BUSCAR USUARIO");
        string username;
        cout << "Nombre de usuario: ";
        cin >> username;
        sistema.buscarYMostrarUsuario(username);
        pausa();
    }

    void buscarPosts() {
        mostrarEncabezado("BUSCAR POSTS");
        string palabra;
        cout << "Palabra clave: ";
        cin.ignore();
        getline(cin, palabra);
        sistema.mostrarResultadosBusquedaPosts(palabra);
        pausa();
    }

    void editarPerfil() {
        mostrarEncabezado("EDITAR PERFIL");
        string nuevoUser, nuevoPass;
        cout << "Nuevo username: ";
        cin >> nuevoUser;
        cout << "Nueva password: ";
        cin >> nuevoPass;
        sistema.editarPerfil(nuevoUser, nuevoPass);

        cout << "\n[NOTA] Los cambios se aplicaran en esta sesion.\n";
        cout << "       Para persistir, actualizar Usuarios.txt\n";
        pausa();
    }
};