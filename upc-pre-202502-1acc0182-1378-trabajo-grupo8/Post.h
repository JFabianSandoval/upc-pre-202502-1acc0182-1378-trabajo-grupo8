#pragma once
#include <string>
using namespace std;

class Post {
private:
    string contenido;

public:
    Post() {}
    Post(string c) { contenido = c; }

    string GetContenido() { return contenido; }
    void SetContenido(string c) { contenido = c; }
};
