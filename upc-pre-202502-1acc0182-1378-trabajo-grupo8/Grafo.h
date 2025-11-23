#pragma once
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Grafo {
private:
    unordered_map<string, vector<string>> amigos;

public:
    void agregarAmigo(string user, string amigo) {
        amigos[user].push_back(amigo);
    }

    vector<string> obtenerAmigos(string user) {
        if (amigos.count(user))
            return amigos[user];
        return {};
    }
};
