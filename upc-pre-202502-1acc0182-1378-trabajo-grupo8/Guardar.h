#pragma once
#include "Interacciones.h"

template <typename TTipo>
class Guardar : public Interacciones<int, TTipo> {
private:
    TTipo tipoDe;

public:
#if 0
    // M�todos seg�n el diagrama UML (vac�os)
    void devolverTipo() {};
#endif
};
