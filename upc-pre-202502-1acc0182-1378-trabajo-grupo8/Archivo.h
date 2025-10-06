#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Usuario.h"
#include "ListaSimple.h"
using namespace std;

template <class T>
class Archivo {
private:
    string ruta = "Usuarios.txt";

public:
    // ✅ Crear archivo inicial con usuarios demo
    void crearArchivoInicial() {
        ifstream test(ruta);
        if (test.good()) return; // ya existe

        ofstream out(ruta, ios::out);
        if (!out.is_open()) {
            cout << "Error al crear archivo inicial.\n";
            return;
        }

        // formato: id|nombre|correo|contrasenia|seguidores
        out << "1001|Camila|cami@prueba.com|cami123|\n";
        out << "1002|Sergio|sergio@prueba.com|sergio123|\n";
        out << "1003|Fabian|fabian@prueba.com|fabian123|\n";
        out.close();
    }

    // ✅ Cargar usuarios en lista simple
    void cargarUsuarios(ListaSimple<Usuario<T>>& listaUsuarios) {
        ifstream in(ruta);
        if (!in.is_open()) {
            cout << "No se pudo abrir " << ruta << endl;
            return;
        }

        string linea;
        while (getline(in, linea)) {
            if (linea.empty()) continue;
            stringstream ss(linea);
            string sid, nombre, correo, pass, seguidores;

            getline(ss, sid, '|');
            getline(ss, nombre, '|');
            getline(ss, correo, '|');
            getline(ss, pass, '|');
            getline(ss, seguidores, '|');

            Usuario<T> u;
            u.establecerId(stoi(sid));
            u.establecerNombres(nombre);
            u.establecercorreo(correo);
            u.establecerContrasenia(pass);

            listaUsuarios.InsertarAlFinal(u);
        }
        in.close();
    }

    // ✅ Guardar lista actualizada (sobrescribe el TXT)
    void guardarUsuarios(ListaSimple<Usuario<T>>& listaUsuarios) {
        ofstream out(ruta, ios::trunc);
        if (!out.is_open()) {
            cout << "Error al guardar archivo.\n";
            return;
        }

        Nodo<Usuario<T>>* actual = listaUsuarios.GetCabeza();
        while (actual != nullptr) {
            Usuario<T> u = actual->GetDato();
            out << u.obtenerId() << "|"
                << u.obtenerNombres() << "|"
                << u.obtenercorreo() << "|"
                << u.obtenerContrasenia() << "|\n";
            actual = actual->GetSiguiente();
        }

        out.close();
    }
};
