#pragma once
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;

template <typename I>
class Interacciones
{
private:
    I tipoDe;

public:

    // MÉTODOS SEGÚN EL DIAGRAMA UML
    void comentarPublicacion()
    {
        cout << "\n--- Comentar publicación ---\n";
        string comentario;
        cin.ignore();
        cout << "Escribe tu comentario: ";
        getline(cin, comentario);
        cout << "Tu comentario ha sido publicado: \"" << comentario << "\".\n";
    };

    void reacciones()
    {
        cout << "\n--- Reaccionar a publicación ---\n";
        cout << "Selecciona una reacción:\n";
        cout << "1. Me gusta\n2. Me encanta\n3. Me enoja\n4. Me sorprende\n";
        int opcion;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Has reaccionado con: Me gusta.\n";
            break;
        case 2:
            cout << "Has reaccionado con: Me encanta.\n";
            break;
        case 3:
            cout << "Has reaccionado con: Me enoja.\n";
            break;
        case 4:
            cout << "Has reaccionado con: Me sorprende.\n";
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    };

    void devolverTipo()
    {
        cout << "\n--- Devolver tipo de interacción ---\n";
        cout << "Ingrese el tipo de interacción (por ejemplo: Comentario, Reacción, Guardado): ";
        cin >> tipoDe;
        cout << "Tipo de interacción registrado: " << tipoDe << endl;
    };
};
