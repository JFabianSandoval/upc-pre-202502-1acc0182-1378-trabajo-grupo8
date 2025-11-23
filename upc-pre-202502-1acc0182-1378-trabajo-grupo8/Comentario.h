#pragma once
#include <string>
using namespace std;

class Comentario {
private:
    string contenido;

public:
    Comentario() {}
    Comentario(string c) { contenido = c; }

    string GetContenido() { return contenido; }
    void SetContenido(string c) { contenido = c; }
};
