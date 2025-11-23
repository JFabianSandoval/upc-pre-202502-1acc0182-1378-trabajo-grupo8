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
    Lista<Comentario*> comentarios; // comentarios en mis posts

    Usuario(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string getUsername() { return username; }
    string getPassword() { return password; }

    void mostrar() {
        cout << "Usuario: " << username << endl;
    }
};
