
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "MenuIG.h"
#include "GeneradorUsuarios.h"
#include "ControladoraIG.h"
using namespace std;

void configurarConsola() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, "es_ES.UTF-8");
    SetConsoleTitleA("Red Social - Grupo 8 | UPC 2025-2");
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

void limpiarPantalla() {
    system("cls");
}

void pausa() {
    cout << "\n" << CYAN << " Presiona ENTER para continuar..." << RESET;
    cin.ignore();
    cin.get();
}

void imprimirLinea(char caracter, int longitud, string color = WHITE) {
    cout << color;
    for (int i = 0; i < longitud; i++) {
        cout << caracter;
    }
    cout << RESET << "\n";
}

void imprimirEncabezado(string titulo, string colorBorde = CYAN, string colorTitulo = YELLOW) {
    int anchoTotal = 70;
    int espaciosTitulo = (anchoTotal - titulo.length() - 2) / 2;

    cout << "\n";
    imprimirLinea('-', anchoTotal, colorBorde);

    cout << colorBorde << "|" << RESET;
    for (int i = 0; i < espaciosTitulo; i++) cout << " ";
    cout << BOLD << colorTitulo << titulo << RESET;
    for (int i = 0; i < anchoTotal - espaciosTitulo - titulo.length() - 2; i++) cout << " ";
    cout << colorBorde << "|" << RESET << "\n";

    imprimirLinea('-', anchoTotal, colorBorde);
    cout << "\n";
}

void imprimirBanner() {
    cout << BOLD << CYAN;
    cout << "\n BANNER REMOVIDO PARA ASCII SEGURO \n";
    cout << RESET;
}

void imprimirCargando(string texto, int duracion = 500) {
    cout << YELLOW << "... " << texto;
    for (int i = 0; i < 3; i++) {
        Sleep(duracion);
        cout << ".";
        cout.flush();
    }
    cout << RESET << "\n";
}

void menuPrincipal() {
    limpiarPantalla();
    imprimirBanner();

    cout << "\n -------- MENU PRINCIPAL -------- \n";
    cout << " 1. Generar 10,000 usuarios (Usuarios.txt)\n";
    cout << " 2. Iniciar sistema y login\n";
    cout << " 3. Prueba completa del sistema (DEMO)\n";
    cout << " 4. Salir\n";
    cout << "\n Selecciona una opcion: ";
}

void mostrarExito(string mensaje) {
    cout << "\n OK: " << mensaje << "\n";
}

void mostrarError(string mensaje) {
    cout << "\n ERROR: " << mensaje << "\n";
}

void mostrarInfo(string mensaje) {
    cout << "\n INFO: " << mensaje << "\n";
}

void pruebaCompletaDelSistema() {
    limpiarPantalla();
    cout << "\n ---- PRUEBA COMPLETA DEL SISTEMA ---- \n";

    ControladoraIG sistema;

    imprimirEncabezado("PASO 1/6: CARGA DE USUARIOS", CYAN, YELLOW);
    imprimirCargando("Cargando usuarios", 300);
    sistema.cargarUsuariosDesdeArchivo();

    imprimirEncabezado("PASO 2/6: ASIGNACION DE AMIGOS", CYAN, YELLOW);
    imprimirCargando("Asignando amigos", 300);
    sistema.asignarAmigosAleatorios();

    imprimirEncabezado("PASO 3/6: AUTENTICACION", CYAN, YELLOW);
    mostrarInfo("Iniciando sesion como user1...");
    sistema.login("user1", "123");

    imprimirEncabezado("PASO 4/6: ORDENAMIENTO", CYAN, YELLOW);
    imprimirCargando("Ordenando amigos", 300);
    sistema.prepararBusquedaBinariaAmigos();
    sistema.mostrarAmigosOrdenados(15);

    imprimirEncabezado("PASO 5/6: BUSQUEDA BINARIA", CYAN, YELLOW);

    Usuario* user = sistema.getUsuarioActual();
    string primerAmigo;
    user->amigos.recorrer([&](string amigo) {
        if (primerAmigo.empty()) primerAmigo = amigo;
        });

    cout << "\n Buscando amigo existente: " << primerAmigo << "\n";
    sistema.buscarAmigoBinario(primerAmigo);

    cout << "\n Buscando amigo inexistente: UsuarioInexistente999 \n";
    sistema.buscarAmigoBinario("UsuarioInexistente999");

    imprimirEncabezado("PASO 6/6: HASHTABLE", CYAN, YELLOW);

    mostrarInfo("Creando posts de prueba...");
    sistema.publicarPost("Mi primer post de prueba", "2025-01-20");
    sistema.publicarPost("Probando sistema", "2025-01-21");
    sistema.publicarPost("Todo OK", "2025-01-22");

    for (int i = 1; i <= 10; i++) {
        string texto = "Comentario #" + to_string(i);
        sistema.comentarPost(1, texto, "2025-01-23");
        Sleep(100);
    }

    sistema.mostrarComentariosDePost(1);
    sistema.mostrarEstadisticasComentarios();

    cout << "\n PRUEBA COMPLETADA CON EXITO \n";

    pausa();
}

void animacionCarga() {
    limpiarPantalla();
    imprimirBanner();

    imprimirCargando("Inicializando sistema", 400);
    imprimirCargando("Cargando modulos", 400);
    imprimirCargando("Preparando entorno", 400);

    mostrarExito("Sistema listo");
    Sleep(800);
}

int main() {
    configurarConsola();

    int opcion;

    do {
        menuPrincipal();
        cin >> opcion;

        if (opcion == 1) {
            limpiarPantalla();
            imprimirEncabezado("GENERADOR DE USUARIOS", MAGENTA, YELLOW);
            imprimirCargando("Inicializando generador", 300);
            GeneradorUsuarios::generar10000Usuarios();
            mostrarExito("Usuarios generados");
            pausa();
        }
        else if (opcion == 2) {
            animacionCarga();
            limpiarPantalla();
            MenuIG menu;
            menu.inicio();
        }
        else if (opcion == 3) {
            pruebaCompletaDelSistema();
        }
        else if (opcion == 4) {
            mostrarInfo("Saliendo del sistema...");
            Sleep(1000);
        }
        else {
            mostrarError("Opcion invalida.");
            pausa();
        }

    } while (opcion != 4);

    return 0;
}
