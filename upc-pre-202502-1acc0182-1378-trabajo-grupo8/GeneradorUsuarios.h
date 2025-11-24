#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class GeneradorUsuarios {
private:
    static string nombres[100];
    static string apellidos[100];

    static void inicializarNombres() {
        nombres[0] = "Ana"; nombres[1] = "Luis"; nombres[2] = "Maria"; nombres[3] = "Carlos";
        nombres[4] = "Sofia"; nombres[5] = "Diego"; nombres[6] = "Lucia"; nombres[7] = "Miguel";
        nombres[8] = "Valentina"; nombres[9] = "Andres"; nombres[10] = "Camila"; nombres[11] = "Juan";
        nombres[12] = "Isabella"; nombres[13] = "Jose"; nombres[14] = "Daniela"; nombres[15] = "Pedro";
        nombres[16] = "Mariana"; nombres[17] = "Ricardo"; nombres[18] = "Paula"; nombres[19] = "Jorge";
        nombres[20] = "Fernanda"; nombres[21] = "Alberto"; nombres[22] = "Laura"; nombres[23] = "Manuel";
        nombres[24] = "Carolina"; nombres[25] = "Roberto"; nombres[26] = "Andrea"; nombres[27] = "Fernando";
        nombres[28] = "Gabriela"; nombres[29] = "Javier"; nombres[30] = "Natalia"; nombres[31] = "Sergio";
        nombres[32] = "Alejandra"; nombres[33] = "Eduardo"; nombres[34] = "Diana"; nombres[35] = "Guillermo";
        nombres[36] = "Patricia"; nombres[37] = "Raul"; nombres[38] = "Monica"; nombres[39] = "Oscar";
        nombres[40] = "Elena"; nombres[41] = "Antonio"; nombres[42] = "Rosa"; nombres[43] = "Victor";
        nombres[44] = "Beatriz"; nombres[45] = "Enrique"; nombres[46] = "Claudia"; nombres[47] = "Francisco";
        nombres[48] = "Sandra"; nombres[49] = "Hector"; nombres[50] = "Alicia"; nombres[51] = "Rodrigo";
        nombres[52] = "Julia"; nombres[53] = "Martin"; nombres[54] = "Carmen"; nombres[55] = "Rafael";
        nombres[56] = "Teresa"; nombres[57] = "Alfredo"; nombres[58] = "Silvia"; nombres[59] = "Pablo";
        nombres[60] = "Gloria"; nombres[61] = "Leonardo"; nombres[62] = "Veronica"; nombres[63] = "Arturo";
        nombres[64] = "Angela"; nombres[65] = "Ramon"; nombres[66] = "Cristina"; nombres[67] = "Cesar";
        nombres[68] = "Adriana"; nombres[69] = "Julio"; nombres[70] = "Lorena"; nombres[71] = "Mauricio";
        nombres[72] = "Susana"; nombres[73] = "Daniel"; nombres[74] = "Marcela"; nombres[75] = "Felipe";
        nombres[76] = "Paola"; nombres[77] = "Gustavo"; nombres[78] = "Ines"; nombres[79] = "Mario";
        nombres[80] = "Olga"; nombres[81] = "Hugo"; nombres[82] = "Pilar"; nombres[83] = "Emilio";
        nombres[84] = "Marta"; nombres[85] = "Ruben"; nombres[86] = "Cecilia"; nombres[87] = "Ivan";
        nombres[88] = "Jimena"; nombres[89] = "Salvador"; nombres[90] = "Raquel"; nombres[91] = "Emiliano";
        nombres[92] = "Irene"; nombres[93] = "Marcos"; nombres[94] = "Rocio"; nombres[95] = "Agustin";
        nombres[96] = "Clara"; nombres[97] = "Nicolas"; nombres[98] = "Miriam"; nombres[99] = "Ignacio";
    }

    static void inicializarApellidos() {
        apellidos[0] = "Garcia"; apellidos[1] = "Rodriguez"; apellidos[2] = "Martinez"; apellidos[3] = "Lopez";
        apellidos[4] = "Gonzalez"; apellidos[5] = "Hernandez"; apellidos[6] = "Perez"; apellidos[7] = "Sanchez";
        apellidos[8] = "Ramirez"; apellidos[9] = "Torres"; apellidos[10] = "Flores"; apellidos[11] = "Rivera";
        apellidos[12] = "Gomez"; apellidos[13] = "Diaz"; apellidos[14] = "Cruz"; apellidos[15] = "Morales";
        apellidos[16] = "Reyes"; apellidos[17] = "Gutierrez"; apellidos[18] = "Ortiz"; apellidos[19] = "Chavez";
        apellidos[20] = "Ruiz"; apellidos[21] = "Mendoza"; apellidos[22] = "Castillo"; apellidos[23] = "Vargas";
        apellidos[24] = "Romero"; apellidos[25] = "Silva"; apellidos[26] = "Castro"; apellidos[27] = "Ramos";
        apellidos[28] = "Jimenez"; apellidos[29] = "Fernandez"; apellidos[30] = "Medina"; apellidos[31] = "Aguilar";
        apellidos[32] = "Guerrero"; apellidos[33] = "Vazquez"; apellidos[34] = "Nunez"; apellidos[35] = "Santiago";
        apellidos[36] = "Moreno"; apellidos[37] = "Carrillo"; apellidos[38] = "Delgado"; apellidos[39] = "Rojas";
        apellidos[40] = "Herrera"; apellidos[41] = "Soto"; apellidos[42] = "Pena"; apellidos[43] = "Contreras";
        apellidos[44] = "Guzman"; apellidos[45] = "Luna"; apellidos[46] = "Mendez"; apellidos[47] = "Rios";
        apellidos[48] = "Salazar"; apellidos[49] = "Campos"; apellidos[50] = "Cortes"; apellidos[51] = "Cabrera";
        apellidos[52] = "Leon"; apellidos[53] = "Vega"; apellidos[54] = "Estrada"; apellidos[55] = "Alvarado";
        apellidos[56] = "Sandoval"; apellidos[57] = "Vazquez"; apellidos[58] = "Velazquez"; apellidos[59] = "Maldonado";
        apellidos[60] = "Espinoza"; apellidos[61] = "Valencia"; apellidos[62] = "Navarro"; apellidos[63] = "Cervantes";
        apellidos[64] = "Palacios"; apellidos[65] = "Santos"; apellidos[66] = "Galvan"; apellidos[67] = "Dominguez";
        apellidos[68] = "Solis"; apellidos[69] = "Benitez"; apellidos[70] = "Ochoa"; apellidos[71] = "Miranda";
        apellidos[72] = "Figueroa"; apellidos[73] = "Vega"; apellidos[74] = "Fuentes"; apellidos[75] = "Trujillo";
        apellidos[76] = "Serrano"; apellidos[77] = "Blanco"; apellidos[78] = "Parra"; apellidos[79] = "Montoya";
        apellidos[80] = "Lara"; apellidos[81] = "Ibarra"; apellidos[82] = "Zamora"; apellidos[83] = "Arias";
        apellidos[84] = "Duran"; apellidos[85] = "Bautista"; apellidos[86] = "Calderon"; apellidos[87] = "Acosta";
        apellidos[88] = "Galindo"; apellidos[89] = "Meza"; apellidos[90] = "Rosales"; apellidos[91] = "Villarreal";
        apellidos[92] = "Villanueva"; apellidos[93] = "Barrera"; apellidos[94] = "Avila"; apellidos[95] = "Roman";
        apellidos[96] = "Escobar"; apellidos[97] = "Mora"; apellidos[98] = "Mercado"; apellidos[99] = "Mejia";
    }

public:
    static void generar10000Usuarios() {
        srand(time(0));
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