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

    // M�TODOS SEG�N EL DIAGRAMA UML
    void comentarPublicacion()
    {
        cout << "\n--- Comentar publicaci�n ---\n";
        string comentario;
        cin.ignore();
        cout << "Escribe tu comentario: ";
        getline(cin, comentario);
        cout << "Tu comentario ha sido publicado: \"" << comentario << "\".\n";
    };

    void reacciones()
    {
        cout << "\n--- Reaccionar a publicaci�n ---\n";
        cout << "Selecciona una reacci�n:\n";
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
            cout << "Opci�n inv�lida.\n";
            break;
        }
    };

    void devolverTipo()
    {
        cout << "\n--- Devolver tipo de interacci�n ---\n";
        cout << "Ingrese el tipo de interacci�n (por ejemplo: Comentario, Reacci�n, Guardado): ";
        cin >> tipoDe;
        cout << "Tipo de interacci�n registrado: " << tipoDe << endl;
    };
};
