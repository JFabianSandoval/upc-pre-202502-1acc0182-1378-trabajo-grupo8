#pragma once
#include "Interacciones.h"
#include <iostream>
#include <string>
using namespace std;

template <typename TTipo>
class Compartir : public Interacciones<int, TTipo>
{
private:
    TTipo tipoDe;

public:

    // MÉTODOS SEGÚN EL DIAGRAMA UML
    void devolverTipo()
    {
        cout << "\n--- Compartir publicación ---\n";
        cout << "Ingrese el tipo de publicación que desea compartir (por ejemplo: Foto, Video, Historia): ";
        cin >> tipoDe;
        cout << "Has compartido un contenido del tipo: " << tipoDe << ".\n";
    };

    void compartirEnPerfil()
    {
        cout << "\nHas compartido la publicación en tu perfil.\n";
    };

    void compartirPorMensaje()
    {
        cout << "\nHas compartido la publicación por mensaje privado.\n";
    };

    void compartirPorLink()
    {
        cout << "\nSe ha generado un enlace para compartir esta publicación.\n";
    };
};
