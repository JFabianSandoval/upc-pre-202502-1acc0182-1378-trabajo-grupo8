#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "Usuario.h"
#include "ListaDoble.h"

using namespace std;

template <class T>
class Archivo {
private:
    string ufile = "Usuarios.txt";
    string pfile = "Posts.txt";
    string cfile = "Comentarios.txt";
    string afile = "Amigos.txt";

public:

    // ---------------------------
    // CARGAR USUARIOS
    // ---------------------------
    void cargarUsuarios(ListaDoble<Usuario<T>>& lista) {
        ifstream in(ufile);
        if (!in.is_open()) return;

        string linea;
        while (getline(in, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string sid, nom, mail, pass;

            getline(ss, sid, '|');
            getline(ss, nom, '|');
            getline(ss, mail, '|');
            getline(ss, pass, '|');

            Usuario<T> u;
            u.establecerId(stoi(sid));
            u.establecerNombres(nom);
            u.establecercorreo(mail);
            u.establecerContrasenia(pass);

            lista.InsertarAlFinal(u);
        }
        in.close();
    }

    // ---------------------------
    // CARGAR POSTS
    // ---------------------------
    void cargarPosts(ListaDoble<Usuario<T>>& lista) {
        ifstream in(pfile);
        if (!in.is_open()) return;

        string linea;
        while (getline(in, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string sid, contenido;

            getline(ss, sid, '|');
            getline(ss, contenido, '|');

            int id = stoi(sid);

            NodoDoble<Usuario<T>>* usr = lista.GetCabeza();
            while (usr) {
                if (usr->GetDato().obtenerId() == id) {
                    usr->GetDato().posts.InsertarAlFinal(Post(contenido));
                    break;
                }
                usr = usr->GetSiguiente();
            }
        }
        in.close();
    }

    // ---------------------------
    // CARGAR COMENTARIOS
    // ---------------------------
    void cargarComentarios(ListaDoble<Usuario<T>>& lista) {
        ifstream in(cfile);
        if (!in.is_open()) return;

        string linea;
        while (getline(in, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string sid, contenido;

            getline(ss, sid, '|');
            getline(ss, contenido, '|');

            int id = stoi(sid);

            NodoDoble<Usuario<T>>* usr = lista.GetCabeza();
            while (usr) {
                if (usr->GetDato().obtenerId() == id) {
                    usr->GetDato().comentarios.InsertarAlFinal(Comentario(contenido));
                    break;
                }
                usr = usr->GetSiguiente();
            }
        }
        in.close();
    }

    // ---------------------------
    // CARGAR AMIGOS
    // ---------------------------
    void cargarAmigos(ListaDoble<Usuario<T>>& lista) {
        ifstream in(afile);
        if (!in.is_open()) return;

        string linea;
        while (getline(in, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string sid, nombreAmigo;

            getline(ss, sid, '|');
            getline(ss, nombreAmigo, '|');

            int id = stoi(sid);

            NodoDoble<Usuario<T>>* usr = lista.GetCabeza();
            while (usr) {
                if (usr->GetDato().obtenerId() == id) {
                    usr->GetDato().amigos.InsertarAlFinal(nombreAmigo);
                    break;
                }
                usr = usr->GetSiguiente();
            }
        }
        in.close();
    }
};
