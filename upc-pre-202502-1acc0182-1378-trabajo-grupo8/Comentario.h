#pragma once
#include <iostream>
#include <string>
using namespace std;

class Comentario {
private:
    int idPost;
    string autor;
    string texto;
    string fecha;

public:
    Comentario(int idPost, string autor, string texto, string fecha) {
        this->idPost = idPost;
        this->autor = autor;
        this->texto = texto;
        this->fecha = fecha;
    }

    int getIdPost() { return idPost; }
    string getAutor() { return autor; }
    string getTexto() { return texto; }
    string getFecha() { return fecha; }

    void mostrar() {
        cout << autor << ": " << texto << " (" << fecha << ")" << endl;
    }
};
