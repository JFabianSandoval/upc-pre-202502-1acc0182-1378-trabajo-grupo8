#pragma once
#include "Usuario.h"

template <class C>
class Configuracion :
{
private:
	string privacidadPerfil;
	C idioma;
	bool permitirMensajesDesconocidos;
	bool permitirEtiqueta;
	bool permitir;

public:
#if 0
	void cuentaPublica() {
	};
	void cuentaPrivada() {
	};
	void privarVisualizacionDeContenido() {
	};
	void idiomaDelContenido() {
	};
#endif

};