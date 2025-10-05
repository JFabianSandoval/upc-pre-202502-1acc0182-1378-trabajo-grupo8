#pragma once
#include"Usuario.h"	
template <class PU>
class Publicacion {

private:
	PU idPublicaciones;
	PU numComentarios;
	PU numReacciones;
	PU tags;
	PU tipode; // 1=feed, 2=foto, 3=video, 4=story		
public:
	void contenido();
	void devolvertipo();
};