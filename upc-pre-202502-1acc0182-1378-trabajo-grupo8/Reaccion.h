#pragma once
#include "Interacciones.h"
#include <iostream>
#include <string>
using namespace std;

template <typename TTipo>
class Reaccion : public Interacciones<TTipo>
{
private:
    TTipo tipoDe;

public:

    // MÉTODOS SEGÚN EL DIAGRAMA UML
    void devolverTipo()
    {
        cout << "\n--- Reacción a publicación ---\n";
        cout << "Ingrese el tipo de reacción (por ejemplo: Me gusta, Me encanta, Me enoja, Me sorprende): ";
        cin >> tipoDe;
        cout << "Has reaccionado con: " << tipoDe << ".\n";
    };

    void quitarReaccion()
    {
        cout << "\nSe ha quitado tu reacción de la publicación.\n";
    };

    void mostrarReacciones()
    {
        cout << "\nMostrando lista de reacciones en esta publicación (simulado)...\n";
        cout << "1. UsuarioA: Me gusta\n";
        cout << "2. UsuarioB: Me encanta\n";
        cout << "3. UsuarioC: Me sorprende\n";
        cout << "Fin de la lista de reacciones.\n";
    };
};
