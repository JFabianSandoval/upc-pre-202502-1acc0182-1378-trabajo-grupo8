#pragma once
#include "Publicacion.h"
#include <iostream>
#include <string>
using namespace std;

class Foto : public Publicacion
{
public:
	void metodoPublicacion(ostream& os) override
	{
		os << "La publicacion es una foto" << endl;
	}
};