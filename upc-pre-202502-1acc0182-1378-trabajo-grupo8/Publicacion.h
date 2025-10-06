#pragma once
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;
class Publicacion
{
public:
	virtual void metodoPublicacion(ostream& os)
	{
		os << "Metodo de Publicacion sin definir" << endl;
	}
};