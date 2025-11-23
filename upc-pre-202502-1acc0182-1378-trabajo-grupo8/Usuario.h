#pragma once
#include <string>
#include "ListaDoble.h"
#include "Post.h"
#include "Comentario.h"

using namespace std;

template <class T>
class Usuario {
private:
    int id;
    string nombre;
    string correo;
    string contrasenia;

public:
    ListaDoble<Post> posts;
    ListaDoble<Comentario> comentarios;
    ListaDoble<string> amigos;

    Usuario() {}

    void establecerId(int x) { id = x; }
    void establecerNombres(string n) { nombre = n; }
    void establecercorreo(string c) { correo = c; }
    void establecerContrasenia(string p) { contrasenia = p; }

    int obtenerId() { return id; }
    string obtenerNombres() { return nombre; }
    string obtenercorreo() { return correo; }
    string obtenerContrasenia() { return contrasenia; }
    // ===============================
// MÉTODOS DEL MENÚ DE USUARIO
// ===============================

    void verPerfil() {
        cout << "\n--- PERFIL DEL USUARIO ---\n";
        cout << "ID: " << id << "\n";
        cout << "Nombre: " << nombre << "\n";
        cout << "Correo: " << correo << "\n";
    }

    // ===============================
    // AMIGOS
    // ===============================
    void verAmigos() {
        cout << "\n--- LISTA DE AMIGOS ---\n";

        NodoDoble<string>* a = amigos.GetCabeza();
        if (!a) {
            cout << "No tienes amigos registrados.\n";
            return;
        }

        while (a != nullptr) {
            cout << "- " << a->GetDato() << "\n";
            a = a->GetSiguiente();
        }
    }

    void agregarAmigo() {
        string nuevo;
        cout << "\nIngrese el nombre del amigo que desea agregar: ";
        cin.ignore();
        getline(cin, nuevo);

        amigos.InsertarAlFinal(nuevo);

        cout << "Amigo agregado con éxito.\n";
    }

    void eliminarAmigo() {
        string nombreEliminar;
        cout << "\nIngrese el nombre del amigo que desea eliminar: ";
        cin.ignore();
        getline(cin, nombreEliminar);

        NodoDoble<string>* actual = amigos.GetCabeza();

        while (actual != nullptr) {
            if (actual->GetDato() == nombreEliminar) {

                NodoDoble<string>* ant = actual->GetAnterior();
                NodoDoble<string>* sig = actual->GetSiguiente();

                if (ant) ant->SetSiguiente(sig);
                else amigos.GetCabeza() = sig;

                if (sig) sig->SetAnterior(ant);

                delete actual;

                cout << "Amigo eliminado correctamente.\n";
                return;
            }
            actual = actual->GetSiguiente();
        }

        cout << "El amigo no existe en tu lista.\n";
    }

    // ===============================
    // POSTS
    // ===============================
    void crearPost() {
        string txt;
        cout << "\nIngrese el contenido del nuevo post: ";
        cin.ignore();
        getline(cin, txt);

        posts.InsertarAlFinal(Post(txt));
        cout << "Post creado exitosamente.\n";
    }

    void editarPost() {
        cout << "\n--- EDITAR POST ---\n";

        NodoDoble<Post>* p = posts.GetCabeza();
        if (!p) {
            cout << "No tienes posts para editar.\n";
            return;
        }

        int i = 1;
        while (p != nullptr) {
            cout << i << ". " << p->GetDato().GetContenido() << "\n";
            p = p->GetSiguiente();
            i++;
        }

        int seleccion;
        cout << "Seleccione el número de post a editar: ";
        cin >> seleccion;

        p = posts.GetCabeza();
        for (int j = 1; j < seleccion && p != nullptr; j++) {
            p = p->GetSiguiente();
        }

        if (!p) {
            cout << "Opción inválida.\n";
            return;
        }

        cin.ignore();
        string nuevo;
        cout << "Nuevo contenido: ";
        getline(cin, nuevo);

        p->GetDato().SetContenido(nuevo);

        cout << "Post editado correctamente.\n";
    }

    void eliminarPost() {
        cout << "\n--- ELIMINAR POST ---\n";

        NodoDoble<Post>* p = posts.GetCabeza();
        if (!p) {
            cout << "No tienes posts para eliminar.\n";
            return;
        }

        int i = 1;
        while (p != nullptr) {
            cout << i << ". " << p->GetDato().GetContenido() << "\n";
            p = p->GetSiguiente();
            i++;
        }

        int seleccion;
        cout << "Seleccione el número de post a eliminar: ";
        cin >> seleccion;

        p = posts.GetCabeza();
        for (int j = 1; j < seleccion && p != nullptr; j++) {
            p = p->GetSiguiente();
        }

        if (!p) {
            cout << "Opción inválida.\n";
            return;
        }

        NodoDoble<Post>* anterior = p->GetAnterior();
        NodoDoble<Post>* siguiente = p->GetSiguiente();

        if (anterior) anterior->SetSiguiente(siguiente);
        else posts.GetCabeza() = siguiente;

        if (siguiente) siguiente->SetAnterior(anterior);

        delete p;

        cout << "Post eliminado correctamente.\n";
    }

    void compartirPost() {
        cout << "Función simple: Post compartido en tu muro.\n";
    }

    // ===============================
    // SEGURIDAD
    // ===============================
    void cambiarContrasenia() {
        string nueva;
        cout << "Ingrese su nueva contraseña: ";
        cin >> nueva;

        contrasenia = nueva;

        cout << "Contraseña actualizada!\n";
    }

    void bloquearAmigo() {
        string nombrebloq;
        cout << "Nombre del usuario a bloquear: ";
        cin.ignore();
        getline(cin, nombrebloq);

        cout << "Usuario '" << nombrebloq << "' bloqueado.\n";
    }

    void cerrarSesion() {
        cout << "Cerrando sesión...\n";
    }

};
