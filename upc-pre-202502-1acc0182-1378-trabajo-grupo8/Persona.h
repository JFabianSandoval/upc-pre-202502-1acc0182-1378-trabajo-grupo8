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
    Persona() : id(0), nombres(" "), paterno(" "), materno(" "), correo(" "), contrasenia(" ") {};

    Persona(short id, P nom, P ape1, P ape2, P contra, string email)
        : id(id), nombres(nom), paterno(ape1), materno(ape2), contrasenia(contra), correo(email) {};
    //GETTERS
    short getID() const;
    P getNombres()const;
    P getPaterno()const;
    P getMaterno()const;
    string getCorreo()const;
    P getContrasenia()const;
    //SETTERS
    void setId(short nuevoId);
    void setNombres(P nom);
    void setApellidoPaterno(P ape1);
    void setApellidoMaterno(P ape2);
    void setcorreo(string correo);
    void setContrasenia(P contra);
    //METODOS
    void imprimir(ostream &os)const;
   
};
//IMPLEMENTACION
template<class P>
short Persona<P>::getID() const{ return id; }
template<class P>
P Persona<P>::getNombres()const { return nombres; }
template<class P>
P Persona<P>::getPaterno()const { return paterno; }
template<class P>
P Persona<P>::getMaterno()const { return materno; }
template<class P>
string Persona<P>::getCorreo()const { return correo; }
template<class P>
P Persona<P>::getContrasenia()const { return contrasenia; }
template<class P>
void Persona<P>::setId(short nuevoId) { id = nuevoId; }
template<class P>
void Persona<P>::setNombres(P nom) { nombres = nom; }
template<class P>
void Persona<P>::setApellidoPaterno(P ape1) { paterno = ape1; }
template<class P>
void Persona<P>::setApellidoMaterno(P ape2) { materno = ape2; }
template<class P>
void Persona<P>::setcorreo(string email) { correo = email; }
template<class P>
void Persona<P>::setContrasenia(P contra) { contrasenia = contra; }
template<class P> 
void Persona<P>::imprimir(ostream& os)const
{
    os << "Nombres: " << this->nombres << endl <<
        "Apellido Paterno: " << this->paterno << endl <<
        "Apellido Materno: " << this->materno << endl <<
        "Correo: " << this->correo << endl;
}
template<class P>
ostream& operator<<(ostream& os, const Persona<P> &persona)
{
   persona.imprimir(os);
    return os;
}