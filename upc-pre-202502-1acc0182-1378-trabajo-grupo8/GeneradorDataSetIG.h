#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class GeneradorDataSetIG {

    static string randomFecha() {
        int d = rand() % 28 + 1;
        int m = rand() % 12 + 1;
        int y = 2020 + rand() % 5;
        return to_string(d) + "/" + to_string(m) + "/" + to_string(y);
    }

    static string randomTexto() {
        vector<string> textos = {
            "Hoy fue un gran día",
            "Estoy probando esta red social",
            "Aprendiendo C++",
            "Proyecto final casi listo",
            "Amo programar",
            "Necesito café urgente",
            "Hoy entrené fuerte",
            "Estoy feliz con mis avances",
            "Probando funciones nuevas",
            "La vida es bella"
        };
        return textos[rand() % textos.size()];
    }

public:

    static void generarPostsYComentarios() {

        // =================== Leer usuarios ===================
        vector<string> usuarios;
        ifstream fu("usuarios.txt");
        string linea;

        while (getline(fu, linea)) {
            if (linea.size() > 1)
                usuarios.push_back(linea);
        }
        fu.close();

        if (usuarios.empty()) {
            cout << "ERROR: usuarios.txt esta vacio." << endl;
            return;
        }

        // =================== Generar posts ===================
        ofstream fp("posts.txt");
        int totalPosts = 10000;
        int id = 1;

        for (int i = 0; i < totalPosts; i++) {
            string autor = usuarios[rand() % usuarios.size()];
            fp << id << "|" << autor << "|" << randomTexto() << "|" << randomFecha() << "\n";
            id++;
        }
        fp.close();

        // =================== Generar comentarios ===================
        ofstream fc("comentarios.txt");
        int totalComentarios = 10000;

        for (int i = 0; i < totalComentarios; i++) {
            int postID = rand() % totalPosts + 1;
            string autor = usuarios[rand() % usuarios.size()];
            fc << postID << "|" << autor << "|" << randomTexto() << "|" << randomFecha() << "\n";
        }
        fc.close();

        cout << "\n*** DATASET GENERADO EXITOSAMENTE ***\n";
        cout << "Posts creados: " << totalPosts << endl;
        cout << "Comentarios creados: " << totalComentarios << endl;
    }
};
