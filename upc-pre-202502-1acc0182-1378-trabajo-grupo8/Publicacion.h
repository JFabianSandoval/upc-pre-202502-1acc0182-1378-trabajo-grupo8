#pragma once
#include"Usuario.h"	
template <class PU>
class Publicacion {

private:
	PU idPublicaciones;
	int numComentarios;
	int numReacciones;
	PU tags;
	int tipode; // 1=feed, 2=foto, 3=video, 4=story		
public:
	void contenido();
	void devolvertipo();
};