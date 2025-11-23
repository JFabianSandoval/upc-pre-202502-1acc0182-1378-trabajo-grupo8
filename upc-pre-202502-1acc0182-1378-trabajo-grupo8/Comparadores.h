#pragma once
#include "Post.h"

// Comparador para ordenar posts por fecha (string)
auto cmpPostFecha = [](Post* a, Post* b) -> bool {
    return a->getFecha() < b->getFecha();
    };
