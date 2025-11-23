#include <iostream>
#include <string>
#include "Archivo.h"
#include "ListaDoble.h"
using namespace std;

// Este main SOLO carga los txt y muestra todo para verificar que funciona.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // -------------------------------
    // 1. Crear el administrador de archivos
    // -------------------------------
    Archivo<string> archivo;

    // -------------------------------
    // 2. Crear la lista de usuarios
    // -------------------------------
    ListaDoble<Usuario<string>> listaUsuarios;

    // -------------------------------
    // 3. Cargar todos los datos
    // -------------------------------
    archivo.cargarUsuarios(listaUsuarios);
    archivo.cargarPosts(listaUsuarios);
    archivo.cargarComentarios(listaUsuarios);
    archivo.cargarAmigos(listaUsuarios);

    // -------------------------------
    // 4. Mostrar todo lo cargado
    // -------------------------------
    cout << "\n======= USUARIOS CARGADOS =======\n";
    NodoDoble<Usuario<string>>* u = listaUsuarios.GetCabeza();

    while (u != nullptr) {

        Usuario<string>& usr = u->GetDato();  // referencia al usuario

        cout << "\nID: " << usr.obtenerId()
            << " | Nombre: " << usr.obtenerNombres()
            << " | Correo: " << usr.obtenercorreo() << "\n";

        // --------- MOSTRAR POSTS ---------
        cout << "  Posts:\n";
        NodoDoble<Post>* p = usr.posts.GetCabeza();
        while (p != nullptr) {
            cout << "    - " << p->GetDato().GetContenido() << "\n";
            p = p->GetSiguiente();
        }

        // --------- MOSTRAR COMENTARIOS ---------
        cout << "  Comentarios:\n";
        NodoDoble<Comentario>* c = usr.comentarios.GetCabeza();
        while (c != nullptr) {
            cout << "    * " << c->GetDato().GetContenido() << "\n";
            c = c->GetSiguiente();
        }

        // --------- MOSTRAR AMIGOS ---------
        cout << "  Amigos:\n";
        NodoDoble<string>* a = usr.amigos.GetCabeza();
        while (a != nullptr) {
            cout << "    -> " << a->GetDato() << "\n";
            a = a->GetSiguiente();
        }

        u = u->GetSiguiente();
    }

    cout << "\n\nFIN DE CARGA\n";
    system("pause");
    return 0;
}
