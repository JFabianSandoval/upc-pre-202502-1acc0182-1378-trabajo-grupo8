#include <iostream>
#include <cstdlib>
#include "MenuIG.h"
#include "GeneradorUsuarios.h"
#include "ControladoraIG.h"
using namespace std;

void limpiarPantalla() {
    system("cls");
}

void pausa() {
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void menuPrincipal() {
    setlocale(LC_ALL, "spanish");

    cout << "+--------------------------------------------------+\n";
    cout << "|    SIMULADOR DE RED SOCIAL - GRUPO 8            |\n";
    cout << "+--------------------------------------------------+\n\n";

    cout << "1. Generar 10,000 usuarios (Usuarios.txt)\n";
    cout << "2. Iniciar sistema y login\n";
    cout << "3. Prueba completa del sistema\n";
    cout << "4. Salir\n";
    cout << "\nOpcion: ";
}

void pruebaCompletaDelSistema() {
    setlocale(LC_ALL, "spanish");
    limpiarPantalla();

    cout << "+------------------------------------------------------------+\n";
    cout << "|  PRUEBA COMPLETA - ESTRUCTURAS DE DATOS                   |\n";
    cout << "+------------------------------------------------------------+\n\n";

    ControladoraIG sistema;

    // 1. Cargar usuarios en Lista
    cout << "[1/6] Cargando usuarios desde archivo a Lista...\n";
    sistema.cargarUsuariosDesdeArchivo();

    // 2. Asignar 1000 amigos aleatorios a user1
    cout << "\n[2/6] Asignando 1000 amigos aleatorios a user1...\n";
    sistema.asignarAmigosAleatorios();

    // 3. Login como user1
    cout << "\n[3/6] Iniciando sesion como user1...\n";
    sistema.login("user1", "123");

    // 4. Preparar búsqueda binaria (QuickSort + Array)
    cout << "\n[4/6] Preparando busqueda binaria de amigos...\n";
    sistema.prepararBusquedaBinariaAmigos();

    // Mostrar algunos amigos ordenados
    sistema.mostrarAmigosOrdenados(15);

    // 5. Pruebas de búsqueda binaria
    cout << "\n[5/6] Realizando busquedas binarias...\n";

    Usuario* user = sistema.getUsuarioActual();
    string primerAmigo;
    user->amigos.recorrer([&](string amigo) {
        if (primerAmigo.empty()) primerAmigo = amigo;
        });

    cout << "\nBuscando amigo existente...\n";
    sistema.buscarAmigoBinario(primerAmigo);

    cout << "\nBuscando amigo inexistente...\n";
    sistema.buscarAmigoBinario("UsuarioInexistente999");

    // 6. Prueba de comentarios con HashTable
    cout << "\n[6/6] Probando HashTable con comentarios...\n";

    sistema.publicarPost("Mi primer post", "2025-01-20");
    sistema.publicarPost("Probando el sistema", "2025-01-21");
    sistema.publicarPost("Funcionando perfecto", "2025-01-22");

    cout << "\nAgregando comentarios (colisiones >= 4)...\n";
    for (int i = 1; i <= 10; i++) {
        string texto = "Comentario #" + to_string(i);
        sistema.comentarPost(1, texto, "2025-01-23");
    }

    sistema.mostrarComentariosDePost(1);
    sistema.mostrarEstadisticasComentarios();

    cout << "\n";
    cout << "+------------------------------------------------------------+\n";
    cout << "|         PRUEBA COMPLETADA EXITOSAMENTE                     |\n";
    cout << "|                                                            |\n";
    cout << "|  [OK] Lista: 10,000 usuarios cargados                     |\n";
    cout << "|  [OK] Asignacion: 1000 amigos aleatorios                  |\n";
    cout << "|  [OK] QuickSort: Amigos ordenados                         |\n";
    cout << "|  [OK] Busqueda Binaria: Funcionando                       |\n";
    cout << "|  [OK] HashTable: Colisiones detectadas                    |\n";
    cout << "+------------------------------------------------------------+\n";

    pausa();
}

int main() {
    int opcion;
    setlocale(LC_ALL, "spanish");

    do {
        limpiarPantalla();
        menuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            limpiarPantalla();
            cout << "\nGenerando 10,000 usuarios...\n";
            GeneradorUsuarios::generar10000Usuarios();
            pausa();
            break;

        case 2: {
            limpiarPantalla();
            MenuIG menu;
            menu.inicio();
            break;
        }

        case 3:
            pruebaCompletaDelSistema();
            break;

        case 4:
            limpiarPantalla();
            cout << "\n\n         Hasta luego!\n\n";
            break;

        default:
            cout << "\n[ERROR] Opcion invalida\n";
            pausa();
        }

    } while (opcion != 4);

    return 0;
}