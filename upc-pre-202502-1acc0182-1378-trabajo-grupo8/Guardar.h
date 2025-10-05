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

    // MÉTODOS SEGÚN EL DIAGRAMA UML
    void devolverTipo()
    {
        cout << "\n--- Guardar publicación ---\n";
        cout << "Ingrese el tipo de publicación que desea guardar (por ejemplo: Foto, Video, Historia): ";
        cin >> tipoDe;
        cout << "Has guardado una publicación del tipo: " << tipoDe << ".\n";
    };

    void guardarEnColeccion()
    {
        cout << "\nIngrese el nombre de la colección donde desea guardar esta publicación: ";
        string nombreColeccion;
        cin.ignore();
        getline(cin, nombreColeccion);
        cout << "La publicación fue guardada en la colección \"" << nombreColeccion << "\".\n";
    };

    void mostrarGuardados()
    {
        cout << "\nMostrando todas las publicaciones guardadas (simulado)...\n";
        cout << "1. Publicación de tipo Foto.\n";
        cout << "2. Publicación de tipo Video.\n";
        cout << "3. Publicación de tipo Historia.\n";
        cout << "Fin de la lista de publicaciones guardadas.\n";
    };
};
