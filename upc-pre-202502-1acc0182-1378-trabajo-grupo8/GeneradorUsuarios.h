#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class GeneradorUsuarios {
private:
    static string nombres[100];
    static string apellidos[100];

public:
    static void generar10000Usuarios() {
        srand(static_cast<unsigned>(time(0)));

        // Lambda para inicializar nombres
        auto inicializarNombres = []() {
            string tempNombres[100] = {
                "Ana", "Luis", "Maria", "Carlos", "Sofia", "Diego", "Lucia", "Miguel", "Valentina", "Andres",
                "Camila", "Juan", "Isabella", "Jose", "Daniela", "Pedro", "Mariana", "Ricardo", "Paula", "Jorge",
                "Fernanda", "Alberto", "Laura", "Manuel", "Carolina", "Roberto", "Andrea", "Fernando", "Gabriela", "Javier",
                "Natalia", "Sergio", "Alejandra", "Eduardo", "Diana", "Guillermo", "Patricia", "Raul", "Monica", "Oscar",
                "Elena", "Antonio", "Rosa", "Victor", "Beatriz", "Enrique", "Claudia", "Francisco", "Sandra", "Hector",
                "Alicia", "Rodrigo", "Julia", "Martin", "Carmen", "Rafael", "Teresa", "Alfredo", "Silvia", "Pablo",
                "Gloria", "Leonardo", "Veronica", "Arturo", "Angela", "Ramon", "Cristina", "Cesar", "Adriana", "Julio",
                "Lorena", "Mauricio", "Susana", "Daniel", "Marcela", "Felipe", "Paola", "Gustavo", "Ines", "Mario",
                "Olga", "Hugo", "Pilar", "Emilio", "Marta", "Ruben", "Cecilia", "Ivan", "Jimena", "Salvador",
                "Raquel", "Emiliano", "Irene", "Marcos", "Rocio", "Agustin", "Clara", "Nicolas", "Miriam", "Ignacio"
            };
            copy(begin(tempNombres), end(tempNombres), begin(nombres));
            };

        // Lambda para inicializar apellidos
        auto inicializarApellidos = []() {
            string tempApellidos[100] = {
                "Garcia", "Rodriguez", "Martinez", "Lopez", "Gonzalez", "Hernandez", "Perez", "Sanchez", "Ramirez", "Torres",
                "Flores", "Rivera", "Gomez", "Diaz", "Cruz", "Morales", "Reyes", "Gutierrez", "Ortiz", "Chavez",
                "Ruiz", "Mendoza", "Castillo", "Vargas", "Romero", "Silva", "Castro", "Ramos", "Jimenez", "Fernandez",
                "Medina", "Aguilar", "Guerrero", "Vazquez", "Nunez", "Santiago", "Moreno", "Carrillo", "Delgado", "Rojas",
                "Herrera", "Soto", "Pena", "Contreras", "Guzman", "Luna", "Mendez", "Rios", "Salazar", "Campos",
                "Cortes", "Cabrera", "Leon", "Vega", "Estrada", "Alvarado", "Sandoval", "Vazquez", "Velazquez", "Maldonado",
                "Espinoza", "Valencia", "Navarro", "Cervantes", "Palacios", "Santos", "Galvan", "Dominguez", "Solis", "Benitez",
                "Ochoa", "Miranda", "Figueroa", "Vega", "Fuentes", "Trujillo", "Serrano", "Blanco", "Parra", "Montoya",
                "Lara", "Ibarra", "Zamora", "Arias", "Duran", "Bautista", "Calderon", "Acosta", "Galindo", "Meza",
                "Rosales", "Villarreal", "Villanueva", "Barrera", "Avila", "Roman", "Escobar", "Mora", "Mercado", "Mejia"
            };
            copy(begin(tempApellidos), end(tempApellidos), begin(apellidos));
            };

        // Ejecutar lambdas
        inicializarNombres();
        inicializarApellidos();

        ofstream archivo("Usuarios.txt");
        if (!archivo.is_open()) {
            cout << "ERROR: No se pudo crear Usuarios.txt\n";
            return;
        }

        // Usuario principal
        archivo << "user1|123\n";

        // Generar 9,999 usuarios adicionales
        for (int i = 2; i <= 10000; i++) {
            string nombre = nombres[rand() % 100];
            string apellido = apellidos[rand() % 100];
            string username = nombre + apellido + to_string(i);
            string password = "pass" + to_string(rand() % 9999);

            archivo << username << "|" << password << "\n";
        }

        archivo.close();
        cout << "\n✓ 10,000 usuarios generados exitosamente en Usuarios.txt\n";
    }
};

// Definición de arrays estáticos
string GeneradorUsuarios::nombres[100];
string GeneradorUsuarios::apellidos[100];
