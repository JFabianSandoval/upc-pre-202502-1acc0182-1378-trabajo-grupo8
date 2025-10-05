#include <iostream>
#include "Librerias.h"
#include "Menu.h"
#include "Usuario.h"
using namespace std;

int main() {
    int tipo;
    cout << "Ingrese tipo de usuario (1 = Usuario, 2 = Admin): ";
    cin >> tipo;

    Usuario<string> usuario1;

    if (tipo == 1)
        mostrarMenuUsuario(usuario1); 
    else if (tipo == 2)
        mostrarMenuAdministrador();
    else
        cout << "Tipo de usuario invalido.\n";

    return 0;
}
