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

    // M�TODOS SEG�N EL DIAGRAMA UML
    void devolverTipo()
    {
        cout << "\n--- Reacci�n a publicaci�n ---\n";
        cout << "Ingrese el tipo de reacci�n (por ejemplo: Me gusta, Me encanta, Me enoja, Me sorprende): ";
        cin >> tipoDe;
        cout << "Has reaccionado con: " << tipoDe << ".\n";
    };

    void quitarReaccion()
    {
        cout << "\nSe ha quitado tu reacci�n de la publicaci�n.\n";
    };

    void mostrarReacciones()
    {
        cout << "\nMostrando lista de reacciones en esta publicaci�n (simulado)...\n";
        cout << "1. UsuarioA: Me gusta\n";
        cout << "2. UsuarioB: Me encanta\n";
        cout << "3. UsuarioC: Me sorprende\n";
        cout << "Fin de la lista de reacciones.\n";
    };
};
