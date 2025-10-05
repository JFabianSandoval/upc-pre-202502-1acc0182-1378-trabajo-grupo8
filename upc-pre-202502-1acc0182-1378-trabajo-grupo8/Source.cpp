#include <iostream>
#include "Librerias.h"
#include "Menu.h"
using namespace std;

int main() {
    int tipo;
    cout << "Ingrese tipo de usuario (1 = Usuario, 2 = Admin): ";
    cin >> tipo;

    if (tipo == 1)
        mostrarMenuUsuario();
    else if (tipo == 2)
        mostrarMenuAdministrador();
    else
        cout << "Tipo de usuario invalido.\n";

    return 0;
}