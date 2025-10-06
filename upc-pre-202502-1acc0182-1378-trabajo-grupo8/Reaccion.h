#pragma once
#include "Interacciones.h"
#include <iostream>
#include <string>
using namespace std;

class Reaccion : public Interaccion
{
public:
	void metodoInteraccion(ostream& os) override
	{
		os << "La Interaccion es una reaccion" << endl;
	}
};
