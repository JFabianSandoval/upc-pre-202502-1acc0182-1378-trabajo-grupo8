#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Usuario.h"
#include "Post.h"
#include "Comentario.h"
#include "HashTable.h"
#include "Grafo.h"
#include "Lista.h"
using namespace std;

class ControladoraIG {
private:
    HashTable<Usuario*> usuarios;
    Lista<Post*> posts;
    Lista<Comentario*> comentarios;
    Grafo amigos;
    Usuario* usuarioActual = nullptr;

public:
    ControladoraIG() {}

    // ================= LOGIN =====================
    bool login(string username, string password) {
        ifstream file("usuarios.txt");
        if (!file.is_open()) {
            cout << "Error: No se pudo abrir usuarios.txt\n";
            return false;
        }

        string user, pass;

        auto limpiar = [&](string& s) {
            while (!s.empty() && (s.back() == '\r' || s.back() == '\n' || s.back() == ' '))
                s.pop_back();
            while (!s.empty() && s.front() == ' ')
                s.erase(0, 1);
            };

        while (getline(file, user, '|') && getline(file, pass)) {
            limpiar(user);
            limpiar(pass);
            limpiar(username);
            limpiar(password);

            if (user == username && pass == password) {
                usuarioActual = new Usuario(username, password);
                return true;
            }
        }

        cout << "\n Usuario o contraseña incorrectos.\n";
        return false;
    }


    Usuario* getUsuarioActual() { return usuarioActual; }

    // ================= POSTS =====================
    void publicarPost(string contenido, string fecha) {
        int id = posts.longitud() + 1;
        Post* p = new Post(id, usuarioActual->getUsername(), contenido, fecha);
        posts.insertarFinal(p);
        usuarioActual->posts.insertarFinal(p);

        guardarPost(p);
    }

    void guardarPost(Post* p) {
        ofstream file("posts.txt", ios::app);
        file << p->getAutor() << "|" << p->getId() << "|" << p->getContenido() << "|" << p->getFecha() << "\n";
    }

    void mostrarMisPosts() {
        usuarioActual->posts.recorrer([](Post* p) { p->mostrar(); });
    }

    bool editarPost(int idBuscar, string nuevoContenido) {
        bool cambiado = false;
        usuarioActual->posts.recorrer([&](Post* p) {
            if (p->getId() == idBuscar) {
                p->setContenido(nuevoContenido);
                cambiado = true;
            }
            });
        return cambiado;
    }

    bool eliminarPost(int id) {
        return usuarioActual->posts.eliminar([&](Post* p) { return p->getId() == id; });
    }

    // ================= COMENTARIOS =====================
    void comentarPost(int idPost, string texto, string fecha) {
        Comentario* c = new Comentario(idPost, usuarioActual->getUsername(), texto, fecha);
        comentarios.insertarFinal(c);

        guardarComentario(c);
    }

    void guardarComentario(Comentario* c) {
        ofstream file("comentarios.txt", ios::app);
        file << c->getIdPost() << "|" << c->getAutor() << "|" << c->getTexto() << "|" << c->getFecha() << "\n";
    }

    // ================= AMIGOS =====================
    void agregarAmigo(string amigo) {
        amigos.agregarAmigo(usuarioActual->getUsername(), amigo);
    }

    void mostrarAmigos() {
        auto lista = amigos.obtenerAmigos(usuarioActual->getUsername());
        for (string a : lista) cout << "- " << a << endl;
    }
};
