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

    // M�TODOS SEG�N EL DIAGRAMA UML
    void devolverTipo()
    {
        cout << "\n--- Compartir publicaci�n ---\n";
        cout << "Ingrese el tipo de publicaci�n que desea compartir (por ejemplo: Foto, Video, Historia): ";
        cin >> tipoDe;
        cout << "Has compartido un contenido del tipo: " << tipoDe << ".\n";
    };

    void compartirEnPerfil()
    {
        cout << "\nHas compartido la publicaci�n en tu perfil.\n";
    };

    void compartirPorMensaje()
    {
        cout << "\nHas compartido la publicaci�n por mensaje privado.\n";
    };

    void compartirPorLink()
    {
        cout << "\nSe ha generado un enlace para compartir esta publicaci�n.\n";
    };
};
