#pragma once
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;
class Interaccion
{
public:
	virtual void metodoInteraccion(ostream& os)
	{
		os << "Interaccion sin definir" << endl;
	}
};
