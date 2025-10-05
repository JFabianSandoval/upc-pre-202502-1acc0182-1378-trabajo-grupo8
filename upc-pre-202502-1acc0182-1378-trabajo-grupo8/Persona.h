#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class P>
class Persona
{
private:
    short id;
    P nombres;
    P apellidopaterno;
    P apellidomaterno;
    string email;
    P contraseña;

public:
    // 🔹 Constructor por defecto
    Persona() : id(0), nombres(""), apellidoPaterno(""), apellidoMaterno(""), correo(""), contrasenia("") {}

    // 🔹 Constructor con parámetros
    Persona(short id, P nom, P ape1, P ape2, P contra, string email)
        : id(id), nombres(nom), apellidoPaterno(ape1), apellidoMaterno(ape2), contrasenia(contra), correo(email) {
    }

    // 🔹 Destructor
    ~Persona() {}

    // 🔹 Métodos modificadores (setters)
    void establecerId(short nuevoId) { id = nuevoId; }
    void establecerNombres(P nom) { nombres = nom; }
    void establecerApellidoPaterno(P ape1) { apellidoPaterno = ape1; }
    void establecerApellidoMaterno(P ape2) { apellidoMaterno = ape2; }
    void establecerCorreo(string email) { correo = email; }
    void establecerContrasenia(P contra) { contrasenia = contra; }

    // 🔹 Métodos de acceso (getters)
    short obtenerId() const { return id; }
    P obtenerNombres() const { return nombres; }
    P obtenerApellidoPaterno() const { return apellidoPaterno; }
    P obtenerApellidoMaterno() const { return apellidoMaterno; }
    string obtenerCorreo() const { return correo; }
    P obtenerContrasenia() const { return contrasenia; }

    // 🔹 Mostrar información de la persona
    void mostrarInformacion() const
    {
        cout << "\n--- Información personal ---" << endl;
        cout << "ID: " << id << endl;
        cout << "Nombre completo: " << nombres << " " << apellidoPaterno << " " << apellidoMaterno << endl;
        cout << "Correo: " << correo << endl;
    }

    // 🔹 Validar inicio de sesión (simple)
    bool validarInicioSesion(const string& correoIngresado, const P& contraseniaIngresada) const
    {
        return (correo == correoIngresado && contrasenia == contraseniaIngresada);
    }
};
