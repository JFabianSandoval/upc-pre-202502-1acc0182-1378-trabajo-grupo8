#pragma once
#include "Publicacion.h"
#include <iostream>
#include <string>
using namespace std;
class Feed : public Publicacion
{
public:
	void metodoPublicacion(ostream& os) override
	{
		os << "ElLa publicacion es un Feed" << endl;
	}
};