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
};
