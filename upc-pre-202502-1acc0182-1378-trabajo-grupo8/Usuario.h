#pragma once
#include <iostream>
#include <string>
#include "Lista.h"
using namespace std;

class Post;
class Comentario;

class Usuario {
private:
    string username;
    string password;

public:
    Lista<Post*> posts;          // posts del usuario
    Lista<Comentario*> comentarios; // comentarios de mis posts
    Lista<string> amigos;        // Lista de amigos para búsqueda binaria

    Usuario(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string getUsername() { return username; }
    string getPassword() { return password; }


    void setUsername(string nuevoUsername) {
        username = nuevoUsername;
    }

    void setPassword(string nuevoPassword) {
        password = nuevoPassword;
    }

    void mostrar() {
        cout << "Usuario: " << username << endl;
    }

    // Agregar amigo a la lista
    void agregarAmigo(string nombreAmigo) {
        amigos.insertarFinal(nombreAmigo);
    }

    // Obtener cantidad de amigos
    int cantidadAmigos() {
        return amigos.longitud();
    }
};