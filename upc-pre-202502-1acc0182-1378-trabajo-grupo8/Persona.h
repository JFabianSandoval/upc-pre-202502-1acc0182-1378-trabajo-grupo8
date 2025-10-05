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
	Persona<P>(short id, P nom, P ape1, P ape2, P contra, bool rol, int amigos,string email) :id(id), nombres(nom), apellidopaterno(ape1), apellidomaterno(ape2), contraseña(contra), email(email) {};
	~Persona<P>() {};
};
