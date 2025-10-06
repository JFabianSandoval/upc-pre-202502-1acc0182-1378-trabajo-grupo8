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
    string email;
    P contrasenia;

public:

    Persona() : id(0), nombres(" "), paterno(" "), materno(" "), email(" "), contrasenia(" ") {}
 
    Persona(short id, P nom, P ape1, P ape2, P contra, string email)
        : id(id), nombres(nom), paterno(ape1), materno(ape2), contrasenia(contra), email(email) {
    }


    ~Persona() {}

   
    void establecerId(short nuevoId) { id = nuevoId; }
    void establecerNombres(P nom) { nombres = nom; }
    void establecerApellidoPaterno(P ape1) { paterno = ape1; }
    void establecerApellidoMaterno(P ape2) { materno = ape2; }
    void estableceremail(string email) { email = email; }
    void establecerContrasenia(P contra) { contrasenia = contra; }


    short obtenerId() const { return id; }
    P obtenerNombres() const { return nombres; }
    P obtenerApellidoPaterno() const { return paterno; }
    P obtenerApellidoMaterno() const { return materno; }
    string obteneremail() const { return email; }
    P obtenerContrasenia() const { return contrasenia; }


    void mostrarInformacion() const
    {
        cout << "\n--- Información personal ---" << endl;
        cout << "ID: " << id << endl;
        cout << "Nombre completo: " << nombres << " " << paterno<< " " << materno<< endl;
        cout << "email: " << email << endl;
    }

  
    bool validarInicioSesion(const string& emailIngresado, const P& contraseniaIngresada) const
    {
        return (email == emailIngresado && contrasenia == contraseniaIngresada);
    }
};
