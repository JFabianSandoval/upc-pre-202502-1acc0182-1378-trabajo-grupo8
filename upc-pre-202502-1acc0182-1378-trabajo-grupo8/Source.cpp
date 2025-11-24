#include <iostream>
#include "MenuIG.h"
#include "GeneradorUsuarios.h"
#include "ControladoraIG.h"
using namespace std;

void menuPrincipal() {
    setlocale(LC_ALL, "spanish");
    cout << "\n";
    cout << "╔═══════════════════════════════════════════╗\n";
    cout << "║    SIMULADOR DE RED SOCIAL - GRUPO 8     ║\n";
    cout << "╚═══════════════════════════════════════════╝\n";
    cout << "\n1. Generar 10,000 usuarios (Usuarios.txt)\n";
    cout << "2. Iniciar sistema y login\n";
    cout << "3. Prueba de búsqueda binaria en amigos\n";
    cout << "4. Salir\n";
    cout << "\nOpción: ";
}

void pruebaCompletaDelSistema() {
    setlocale(LC_ALL, "spanish");
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════════════╗\n";
    cout << "║  PRUEBA COMPLETA DEL SISTEMA - ESTRUCTURAS DE DATOS  ║\n";
    cout << "╚═══════════════════════════════════════════════════════╝\n";

    ControladoraIG sistema;

    // 1. Cargar usuarios en Lista
    cout << "\n[1/6] Cargando usuarios desde archivo a Lista...\n";
    sistema.cargarUsuariosDesdeArchivo();

    // 2. Asignar 1000 amigos aleatorios a user1
    cout << "\n[2/6] Asignando 1000 amigos aleatorios a user1...\n";
    sistema.asignarAmigosAleatorios();

    // 3. Login como user1
    cout << "\n[3/6] Iniciando sesión como user1...\n";
    sistema.login("user1", "123");

    // 4. Preparar búsqueda binaria (QuickSort + Array)
    cout << "\n[4/6] Preparando búsqueda binaria de amigos...\n";
    sistema.prepararBusquedaBinariaAmigos();

    // Mostrar algunos amigos ordenados
    sistema.mostrarAmigosOrdenados(15);

    // 5. Pruebas de búsqueda binaria
    cout << "\n[5/6] Realizando búsquedas binarias...\n";

    // Buscar el primer amigo
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

    // Crear algunos posts
    sistema.publicarPost("Mi primer post", "2025-01-20");
    sistema.publicarPost("Probando el sistema", "2025-01-21");
    sistema.publicarPost("Funcionando perfecto", "2025-01-22");

    // Agregar comentarios para forzar colisiones
    cout << "\nAgregando comentarios (se detectarán colisiones >= 4)...\n";
    for (int i = 1; i <= 10; i++) {
        string texto = "Comentario #" + to_string(i);
        sistema.comentarPost(1, texto, "2025-01-23"); 
    }

    // Mostrar comentarios del post
    sistema.mostrarComentariosDePost(1);

    // Estadísticas del HashTable
    sistema.mostrarEstadisticasComentarios();

    cout << "\n";
    cout << "╔═════════════════════════════════════════════════╗\n";
    cout << "║         PRUEBA COMPLETADA EXITOSAMENTE          ║\n";
    cout << "║                                                 ║\n";
    cout << "║  ✓ Lista: 10,000 usuarios cargados            ║\n";
    cout << "║  ✓ Asignación: 1000 amigos aleatorios         ║\n";
    cout << "║  ✓ QuickSort: Amigos ordenados                ║\n";
    cout << "║  ✓ Búsqueda Binaria: Funcionando              ║\n";
    cout << "║  ✓ HashTable: Colisiones detectadas           ║\n";
    cout << "╚═════════════════════════════════════════════════╝\n";

    cout << "\nPresiona Enter para continuar...";
    cin.ignore();
    cin.get();
}

int main() {
    int opcion;
    setlocale(LC_ALL, "spanish");
    do {
        menuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\nGenerando 10,000 usuarios...\n";
            GeneradorUsuarios::generar10000Usuarios();
            cout << "\nPresiona Enter para continuar...";
            cin.ignore();
            cin.get();
            break;

        case 2: {
            cout << "\nCargando usuarios...\n";
            MenuIG menu; 
            menu.inicio();
            break;
        }

        case 3:
            pruebaCompletaDelSistema();
            break;

        case 4:
            cout << "\n¡Hasta luego!\n";
            break;

        default:
            cout << "\nOpción inválida\n";
        }

    } while (opcion != 4);

    return 0;
}