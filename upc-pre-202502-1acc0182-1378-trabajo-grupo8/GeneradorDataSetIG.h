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
        //Leer usuarios
        vector<string> usuarios;//1
        ifstream fu("usuarios.txt");//1
        string linea;//1
        while (getline(fu, linea)) {//1(n)
            if (linea.size() > 1)//1
                usuarios.push_back(linea);//1
        }
        fu.close();//1
        if (usuarios.empty()) {//1
            cout << "ERROR: usuarios.txt esta vacio." << endl;//1
            return;//1
        }
        //Generar posts
        ofstream fp("posts.txt");//1
        int totalPosts = 10000;//1
        int id = 1;//1
        for (int i = 0; i < totalPosts; i++) {//1+n(adentro)+1
            string autor = usuarios[rand() % usuarios.size()];//1
            fp << id << "|" << autor << "|" << randomTexto() << "|" << randomFecha() << "\n";//1
            id++;//1
        }//n
        fp.close();//1
        //Generar comentarios
        ofstream fc("comentarios.txt");//1
        int totalComentarios = 10000;//1
        for (int i = 0; i < totalComentarios; i++) {//1+ n(adentro) + 1
            int postID = rand() % totalPosts + 1;//1
            string autor = usuarios[rand() % usuarios.size()];//1
            fc << postID << "|" << autor << "|" << randomTexto() << "|" << randomFecha() << "\n";//1
        }//n
        fc.close();//1
        cout << "\n*** DATASET GENERADO EXITOSAMENTE ***\n";//1
        cout << "Posts creados: " << totalPosts << endl;//1
        cout << "Comentarios creados: " << totalComentarios << endl;//1
    }//Valoración O(n)
};
