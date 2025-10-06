#pragma once
#include "Publicacion.h"
#include <iostream>
#include <string>
using namespace std;

class Video : public Publicacion
{
public:
	void metodoPublicacion(ostream& os) override
	{
		os << "La publicacion es un video" << endl;
	}
};