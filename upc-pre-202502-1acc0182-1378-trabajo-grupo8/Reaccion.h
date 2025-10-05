#pragma once
#include "Interacciones.h"

template <typename TTipo>
class Reaccion : public Interacciones<int, TTipo> {
private:
    TTipo tipoDe;

public:
#if 0
    // Métodos según el diagrama UML (vacíos)
    void devolverTipo() {};
#endif
};
