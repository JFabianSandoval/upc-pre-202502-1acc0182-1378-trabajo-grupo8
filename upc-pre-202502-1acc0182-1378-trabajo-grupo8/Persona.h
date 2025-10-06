#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class P>
class Persona
{
protected:
    short id;
    P nombres;
    P paterno;
    P materno;
    string correo;
    P contrasenia;

public:

    Persona() : id(0), nombres(" "), paterno(" "), materno(" "), correo(" "), contrasenia(" ") {}
 
    Persona(short id, P nom, P ape1, P ape2, P contra, string email)
        : id(id), nombres(nom), paterno(ape1), materno(ape2), contrasenia(contra), correo(correo) {
    }


    ~Persona() {}

   
    void establecerId(short nuevoId) { id = nuevoId; }
    void establecerNombres(P nom) { nombres = nom; }
    void establecerApellidoPaterno(P ape1) { paterno = ape1; }
    void establecerApellidoMaterno(P ape2) { materno = ape2; }
    void establecercorreo(string correo) { correo = correo; }
    void establecerContrasenia(P contra) { contrasenia = contra; }


    short obtenerId() const { return id; }
    P obtenerNombres() const { return nombres; }
    P obtenerApellidoPaterno() const { return paterno; }
    P obtenerApellidoMaterno() const { return materno; }
    string obtenercorreo() const { return correo; }
    P obtenerContrasenia() const { return contrasenia; }


    void mostrarInformacion() const
    {
        cout << "\n--- Información personal ---" << endl;
        cout << "ID: " << id << endl;
        cout << "Nombre completo: " << nombres << " " << paterno<< " " << materno<< endl;
        cout << "correo: " << correo << endl;
    }

  
    bool validarInicioSesion(const string& correoIngresado, const P& contraseniaIngresada) const
    {
        return (correo == correolIngresado && contrasenia == contraseniaIngresada);
    }
};
