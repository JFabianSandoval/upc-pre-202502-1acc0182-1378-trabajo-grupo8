#pragma once
#include <iostream>
<<<<<<< HEAD
#include <cstdlib>
#include <Windows.h>
=======
#include <cstdlib>  // Para system("cls")
>>>>>>> parent of e835b99 (menu listo)
#include "ControladoraIG.h"
using namespace std;

// COLORES ANSI
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class MenuIG {
private:
    ControladoraIG sistema;

    // Funciones auxiliares para UI
    void limpiarPantalla() {
        system("cls");
    }

    void pausa() {
        cout << "\n" << CYAN << "  Presiona ENTER para continuar..." << RESET;
        cin.ignore();
        cin.get();
    }

    void imprimirLinea(char caracter, int longitud, string color = CYAN) {
        cout << color;
        for (int i = 0; i < longitud; i++) {
            cout << caracter;
        }
        cout << RESET << "\n";
    }

    void mostrarEncabezado(string titulo) {
<<<<<<< HEAD
        int anchoTotal = 60;
        int espaciosTitulo = (anchoTotal - titulo.length() - 2) / 2;

        cout << "\n";
        imprimirLinea('-', anchoTotal, CYAN);

        cout << CYAN << "|" << RESET;
        for (int i = 0; i < espaciosTitulo; i++) cout << " ";
        cout << BOLD << YELLOW << titulo << RESET;
        for (int i = 0; i < anchoTotal - espaciosTitulo - titulo.length() - 2; i++) cout << " ";
        cout << CYAN << "|" << RESET << "\n";

        imprimirLinea('-', anchoTotal, CYAN);
        cout << "\n";
    }

    void mostrarExito(string mensaje) {
        cout << "\n" << GREEN << "  " << BOLD << mensaje << RESET << "\n";
    }

    void mostrarError(string mensaje) {
        cout << "\n" << RED << "  " << BOLD << mensaje << RESET << "\n";
    }

    void mostrarInfo(string mensaje) {
        cout << "\n" << CYAN << "  " << mensaje << RESET << "\n";
    }

    void imprimirCargando(string texto) {
        cout << YELLOW << "  " << texto;
        for (int i = 0; i < 3; i++) {
            Sleep(200);
            cout << ".";
            cout.flush();
        }
        cout << RESET << "\n";
=======
        cout << char(201);  // ╔
        for (int i = 0; i < 50; i++) cout << char(205);  // ═
        cout << char(187) << "\n";  // ╗

        cout << char(186);  // ║
        int espacios = (50 - titulo.length()) / 2;
        for (int i = 0; i < espacios; i++) cout << " ";
        cout << titulo;
        for (int i = 0; i < 50 - espacios - titulo.length(); i++) cout << " ";
        cout << char(186) << "\n";  // ║

        cout << char(200);  // ╚
        for (int i = 0; i < 50; i++) cout << char(205);  // ═
        cout << char(188) << "\n\n";  // ╝
>>>>>>> parent of e835b99 (menu listo)
    }

public:
    MenuIG() {
        limpiarPantalla();
        imprimirCargando("Cargando usuarios...");
        sistema.cargarUsuariosDesdeArchivo();
        imprimirCargando("Cargando posts...");
        sistema.cargarPostsDesdeArchivo();
        imprimirCargando("Cargando comentarios...");
        sistema.cargarComentariosDesdeArchivo();
        imprimirCargando("Cargando amigos...");
        sistema.cargarAmigosDesdeArchivo();
        mostrarExito("Sistema cargado");
        pausa();
    }

    void inicio() {
        limpiarPantalla();
        string user, pass;

        mostrarEncabezado("INICIO DE SESION");

        cout << YELLOW << "Usuario: " << RESET;
        cin >> user;
        cout << YELLOW << "Password: " << RESET;
        cin >> pass;

        if (!sistema.login(user, pass)) {
            mostrarError("Credenciales incorrectas");
            pausa();
            return;
        }

        mostrarExito("Bienvenido " + user);
        Sleep(800);
        menuUsuario();
    }

    void menuUsuario() {
        int opc;

        do {
            limpiarPantalla();
<<<<<<< HEAD
            mostrarEncabezado("MENU PRINCIPAL");

            cout << " 1. Publicar\n";
            cout << " 2. Editar Post\n";
            cout << " 3. Eliminar Post\n";
            cout << " 4. Ver mis Posts\n";
            cout << " 5. Ver todos los Posts\n";
            cout << " 6. Comentar Post\n";
            cout << " 7. Ver Comentarios\n";
            cout << " 8. Agregar Amigo\n";
            cout << " 9. Ver Amigos\n";
            cout << "10. Buscar Usuario\n";
            cout << "11. Buscar Posts\n";
            cout << "12. Editar Perfil\n";
            cout << "13. Estadisticas\n";
            cout << "14. Salir\n";
=======
            cout << char(201);
            for (int i = 0; i < 40; i++) cout << char(205);
            cout << char(187) << "\n";

            cout << char(186) << "          MENU PRINCIPAL              " << char(186) << "\n";

            cout << char(204);
            for (int i = 0; i < 40; i++) cout << char(205);
            cout << char(185) << "\n";

            cout << char(186) << "  1. Publicar                        " << char(186) << "\n";
            cout << char(186) << "  2. Editar Post                     " << char(186) << "\n";
            cout << char(186) << "  3. Eliminar Post                   " << char(186) << "\n";
            cout << char(186) << "  4. Ver mis Posts                   " << char(186) << "\n";
            cout << char(186) << "  5. Ver TODOS los Posts             " << char(186) << "\n";
            cout << char(186) << "  6. Comentar Post                   " << char(186) << "\n";
            cout << char(186) << "  7. Ver Comentarios de Post         " << char(186) << "\n";
            cout << char(186) << "  8. Agregar Amigo                   " << char(186) << "\n";
            cout << char(186) << "  9. Ver Amigos                      " << char(186) << "\n";
            cout << char(186) << " 10. Buscar Usuario                  " << char(186) << "\n";
            cout << char(186) << " 11. Buscar Posts                    " << char(186) << "\n";
            cout << char(186) << " 12. Editar Perfil                   " << char(186) << "\n";
            cout << char(186) << " 13. Estadisticas                    " << char(186) << "\n";
            cout << char(186) << " 14. Salir                           " << char(186) << "\n";

            cout << char(200);
            for (int i = 0; i < 40; i++) cout << char(205);
            cout << char(188) << "\n";
>>>>>>> parent of e835b99 (menu listo)

            cout << "\nOpcion: ";
            cin >> opc;

            limpiarPantalla();

            switch (opc) {
            case 1: publicar(); break;
            case 2: editar(); break;
            case 3: eliminar(); break;
            case 4: mostrarEncabezado("MIS POSTS"); sistema.mostrarMisPosts(); pausa(); break;
            case 5: mostrarEncabezado("TODOS LOS POSTS"); sistema.mostrarTodosLosPostsEnumerados(); pausa(); break;
            case 6: comentar(); break;
            case 7: verComentariosDePost(); break;
            case 8: agregarAmigo(); break;
            case 9: mostrarEncabezado("MIS AMIGOS"); sistema.mostrarAmigos(); pausa(); break;
            case 10: buscarUsuario(); break;
            case 11: buscarPosts(); break;
            case 12: editarPerfil(); break;
            case 13: mostrarEncabezado("ESTADISTICAS"); sistema.mostrarEstadisticasGenerales(); pausa(); break;
            case 14: mostrarExito("Sesion cerrada"); Sleep(800); break;
            default: mostrarError("Opcion invalida"); pausa();
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
        mostrarExito("Post publicado");
        pausa();
    }

    void editar() {
        mostrarEncabezado("EDITAR POST");
        int id;
        string contenido;
        cout << "ID: ";
        cin >> id;
        cout << "Nuevo contenido: ";
        cin.ignore();
        getline(cin, contenido);

        if (sistema.editarPost(id, contenido))
            mostrarExito("Post editado");
        else
            mostrarError("ID no encontrado");

        pausa();
    }

    void eliminar() {
        mostrarEncabezado("ELIMINAR POST");
        int id;
        cout << "ID: ";
        cin >> id;

        if (sistema.eliminarPost(id))
            mostrarExito("Post eliminado");
        else
            mostrarError("ID no encontrado");

        pausa();
    }

    void comentar() {
        mostrarEncabezado("COMENTAR POST");
        int id;
        string texto;
        cout << "ID: ";
        cin >> id;
        cout << "Comentario: ";
        cin.ignore();
        getline(cin, texto);
        sistema.comentarPost(id, texto, "2025");
        pausa();
    }

    void verComentariosDePost() {
        mostrarEncabezado("COMENTARIOS");
        int id;
        cout << "ID: ";
        cin >> id;
        sistema.mostrarComentariosDePost(id);
        pausa();
    }

    void agregarAmigo() {
        mostrarEncabezado("AGREGAR AMIGO");
        string amigo;
        cout << "Username: ";
        cin >> amigo;
        sistema.agregarAmigo(amigo);
        mostrarExito("Agregado");
        pausa();
    }

    void buscarUsuario() {
        mostrarEncabezado("BUSCAR USUARIO");
        string u;
        cout << "Username: ";
        cin >> u;
        sistema.buscarYMostrarUsuario(u);
        pausa();
    }

    void buscarPosts() {
        mostrarEncabezado("BUSCAR POSTS");
        string p;
        cout << "Palabra: ";
        cin.ignore();
        getline(cin, p);
        sistema.mostrarResultadosBusquedaPosts(p);
        pausa();
    }

    void editarPerfil() {
        mostrarEncabezado("EDITAR PERFIL");
        string u, p;
        cout << "Nuevo username: ";
        cin >> u;
        cout << "Nueva password: ";
        cin >> p;
        sistema.editarPerfil(u, p);
        mostrarExito("Perfil actualizado");
        pausa();
    }
};
