#pragma once
#include <iostream>
#include <string>
using namespace std;

class Post {
private:
    int id;
    string autor;
    string contenido;
    string fecha;

public:
    Post(int id, string autor, string contenido, string fecha) {
        this->id = id;
        this->autor = autor;
        this->contenido = contenido;
        this->fecha = fecha;
    }

    int getId() { return id; }
    string getAutor() { return autor; }
    string getContenido() { return contenido; }
    string getFecha() { return fecha; }

    void setContenido(string nuevo) { contenido = nuevo; }

    void mostrar() {
        cout << "\n--- Post #" << id << " ---\n";
        cout << "Autor: " << autor << endl;
        cout << "Contenido: " << contenido << endl;
        cout << "Fecha: " << fecha << endl;
    }
};
