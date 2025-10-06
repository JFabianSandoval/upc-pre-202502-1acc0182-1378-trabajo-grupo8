
/*Publicacion* feed = new Feed();
Publicacion* foto = new Foto();
Publicacion* video = new Video();
Publicacion* story = new Story(); */

#include <iostream>
#include <string>
#include "Librerias.h"
#include "Archivo.h"
#include "ListaSimple.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Archivo<string> archivo;
    archivo.crearArchivoInicial();

    ListaSimple<Usuario<string>> listaUsuarios;
    archivo.cargarUsuarios(listaUsuarios);



    while(true){

    cout << "Seleccione tipo de usuario:\n";
    cout << "1) Administrador\n";
    cout << "2) Usuario\n";

    cout << "\n--- Credenciales DEMO ---\n";
    cout << "Usuarios:\n";
    cout << "  - cami@prueba.com / cami123\n";
    cout << "  - sergio@prueba.com / sergio123\n";
    cout << "  - fabian@prueba.com / fabian123\n";
    cout << "--------------------------\n";

    int tipo;
    cout << "Opcion: ";
    cin >> tipo;

    if (tipo == 1) {
        Admin<string> admin;
        mostrarMenuAdministrador(admin);
        return 0;
    }

    // LOGIN USUARIO
    string correo, contrasenia;
    cout << "\n=== Iniciar sesion ===\n";
    cout << "Correo: ";
    cin >> correo;
    cout << "Contrasena: ";
    cin >> contrasenia;

    bool valido = false;
    Nodo<Usuario<string>>* actual = listaUsuarios.GetCabeza();
    Usuario<string> usuarioActual;

    while (actual != nullptr) {
        Usuario<string> u = actual->GetDato();
        if (u.obtenerCorreo() == correo && u.obtenerContrasenia() == contrasenia) {
            usuarioActual = u;
            valido = true;
            break;
        }
        actual = actual->GetSiguiente();
    }

    if (!valido) {
        cout << "Credenciales invalidas.\n";
        return 0;
    }

    // Ingreso al menú real de tu sistema (desde Menu.h)
    mostrarMenuUsuario(usuarioActual);

    // Si durante el menú se agregan nuevos usuarios, puedes guardar:
    archivo.guardarUsuarios(listaUsuarios);
    };

    return 0;
}
