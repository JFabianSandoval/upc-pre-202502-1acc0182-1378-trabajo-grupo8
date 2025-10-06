#pragma once
#include "Interacciones.h"
#include <iostream>
#include <string>
using namespace std;

template <typename TTipo>
class Guardar : public Interacciones<int, TTipo>
{
private:
    TTipo tipoDe;

public:

    // M�TODOS SEG�N EL DIAGRAMA UML
    void devolverTipo()
    {
        cout << "\n--- Guardar publicaci�n ---\n";
        cout << "Ingrese el tipo de publicaci�n que desea guardar (por ejemplo: Foto, Video, Historia): ";
        cin >> tipoDe;
        cout << "Has guardado una publicaci�n del tipo: " << tipoDe << ".\n";
    };

    void guardarEnColeccion()
    {
        cout << "\nIngrese el nombre de la colecci�n donde desea guardar esta publicaci�n: ";
        string nombreColeccion;
        cin.ignore();
        getline(cin, nombreColeccion);
        cout << "La publicaci�n fue guardada en la colecci�n \"" << nombreColeccion << "\".\n";
    };

    void mostrarGuardados()
    {
        cout << "\nMostrando todas las publicaciones guardadas (simulado)...\n";
        cout << "1. Publicaci�n de tipo Foto.\n";
        cout << "2. Publicaci�n de tipo Video.\n";
        cout << "3. Publicaci�n de tipo Historia.\n";
        cout << "Fin de la lista de publicaciones guardadas.\n";
    };
};
