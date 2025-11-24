#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Usuario.h"
#include "Post.h"
#include "Comentario.h"
#include "HashTable.h"
#include "Grafo.h"
#include "Lista.h"
#include "QuickSort.h"
#include "BusquedaBinaria.h"
using namespace std;

class ControladoraIG {
private:
    Lista<Usuario*> listaUsuarios;  //Lista de todos los usuarios
    HashTable<Comentario*> hashComentarios;  // HashTable para comentarios por ID post
    Lista<Post*> posts;
    Grafo amigos;
    Usuario* usuarioActual = nullptr;

    // Array para búsqueda binaria de amigos
    string* amigosOrdenados = nullptr;
    int cantidadAmigosArray = 0;

public:
    ControladoraIG() : hashComentarios(100) {
        srand(time(0));
    }

    //Cargar usuarios desde archivo a lista
    void cargarUsuariosDesdeArchivo() {
        ifstream file("Usuarios.txt");
        if (!file.is_open()) {
            cout << "Error: No se pudo abrir Usuarios.txt\n";
            return;
        }

        string linea;
        int contador = 0;

        while (getline(file, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string user, pass;

            getline(ss, user, '|');
            getline(ss, pass);

            // Limpiar espacios y saltos de línea
            while (!user.empty() && (user.back() == '\r' || user.back() == '\n' || user.back() == ' '))
                user.pop_back();
            while (!pass.empty() && (pass.back() == '\r' || pass.back() == '\n' || pass.back() == ' '))
                pass.pop_back();

            Usuario* nuevoUsuario = new Usuario(user, pass);
            listaUsuarios.insertarFinal(nuevoUsuario);
            contador++;
        }

        file.close();
        cout << "\n✓ " << contador << " usuarios cargados en memoria (Lista)\n";
    }

    // Asignar 1000 amigos aleatorios al primer usuario
    void asignarAmigosAleatorios() {
        if (listaUsuarios.longitud() < 1000) {
            cout << "Error: Se necesitan al menos 1000 usuarios en el sistema\n";
            return;
        }

        // Obtener el primer usuario (user1)
        Usuario* primerUsuario = nullptr;
        listaUsuarios.recorrer([&](Usuario* u) {
            if (primerUsuario == nullptr && u->getUsername() == "user1") {
                primerUsuario = u;
            }
            });

        if (primerUsuario == nullptr) {
            cout << "Error: No se encontró user1\n";
            return;
        }

        // Crear arreglo temporal con todos los usuarios excepto user1
        string* todosUsuarios = new string[listaUsuarios.longitud() - 1];
        int indice = 0;

        listaUsuarios.recorrer([&](Usuario* u) {
            if (u->getUsername() != "user1") {
                todosUsuarios[indice++] = u->getUsername();
            }
            });

        // Seleccionar 1000 usuarios aleatorios únicos
        bool* seleccionados = new bool[indice]();
        int amigosAgregados = 0;

        while (amigosAgregados < 1000 && amigosAgregados < indice) {
            int pos = rand() % indice;
            if (!seleccionados[pos]) {
                primerUsuario->agregarAmigo(todosUsuarios[pos]);
                seleccionados[pos] = true;
                amigosAgregados++;
            }
        }

        delete[] todosUsuarios;
        delete[] seleccionados;

        cout << "✓ Se asignaron " << amigosAgregados << " amigos aleatorios a user1\n";
    }

    // Preparar arreglo ordenado de amigos para búsqueda binaria
    void prepararBusquedaBinariaAmigos() {
        if (usuarioActual == nullptr) {
            cout << "Error: No hay usuario actual\n";
            return;
        }

        cantidadAmigosArray = usuarioActual->cantidadAmigos();

        if (cantidadAmigosArray == 0) {
            cout << "El usuario no tiene amigos\n";
            return;
        }

        // Crear array con los amigos
        amigosOrdenados = new string[cantidadAmigosArray];
        int idx = 0;

        usuarioActual->amigos.recorrer([&](string amigo) {
            amigosOrdenados[idx++] = amigo;
            });

        // Ordenar con QuickSort
        cout << "\nOrdenando " << cantidadAmigosArray << " amigos con QuickSort...\n";
        quicksortStrings(amigosOrdenados, 0, cantidadAmigosArray - 1);
        cout << "✓ Amigos ordenados alfabéticamente\n";
    }

    //Buscar amigo usando búsqueda binaria
    bool buscarAmigoBinario(string nombreAmigo) {
        if (amigosOrdenados == nullptr) {
            cout << "Error: Primero debes preparar la búsqueda binaria\n";
            return false;
        }

        int resultado = BusquedaBinaria::buscar(amigosOrdenados, 0, cantidadAmigosArray - 1, nombreAmigo);

        if (resultado != -1) {
            cout << "\n✓ AMIGO ENCONTRADO: \"" << nombreAmigo << "\" en posición " << resultado << "\n";
            return true;
        }
        else {
            cout << "\n✗ Amigo \"" << nombreAmigo << "\" NO encontrado\n";
            return false;
        }
    }

    //Mostrar primeros N amigos ordenados
    void mostrarAmigosOrdenados(int cantidad = 20) {
        if (amigosOrdenados == nullptr) {
            cout << "Error: Primero debes preparar la búsqueda binaria\n";
            return;
        }

        cout << "\n===== PRIMEROS " << min(cantidad, cantidadAmigosArray) << " AMIGOS (ORDENADOS) =====\n";
        for (int i = 0; i < min(cantidad, cantidadAmigosArray); i++) {
            cout << (i + 1) << ". " << amigosOrdenados[i] << endl;
        }
        cout << "==========================================\n";
    }

    // LOGIN 
    bool login(string username, string password) {
        bool encontrado = false;

        listaUsuarios.recorrer([&](Usuario* u) {
            if (u->getUsername() == username && u->getPassword() == password) {
                usuarioActual = u;
                encontrado = true;
            }
            });

        if (encontrado) {
            cout << "\n✓ Login exitoso: " << username << "\n";
            return true;
        }
        else {
            cout << "\n✗ Usuario o contraseña incorrectos\n";
            return false;
        }
    }

    Usuario* getUsuarioActual() { return usuarioActual; }

    // POSTS 
    void publicarPost(string contenido, string fecha) {
        if (usuarioActual == nullptr) return;

        int id = posts.longitud() + 1;
        Post* p = new Post(id, usuarioActual->getUsername(), contenido, fecha);
        posts.insertarFinal(p);
        usuarioActual->posts.insertarFinal(p);

        guardarPost(p);
        cout << "✓ Post #" << id << " publicado\n";
    }

    void guardarPost(Post* p) {
        ofstream file("posts.txt", ios::app);
        file << p->getAutor() << "|" << p->getId() << "|" << p->getContenido() << "|" << p->getFecha() << "\n";
        file.close();
    }

    void mostrarMisPosts() {
        if (usuarioActual == nullptr) return;

        cout << "\n===== MIS POSTS =====\n";
        usuarioActual->posts.recorrer([](Post* p) {
            p->mostrar();
            });
    }

    bool editarPost(int idBuscar, string nuevoContenido) {
        if (usuarioActual == nullptr) return false;

        bool cambiado = false;
        usuarioActual->posts.recorrer([&](Post* p) {
            if (p->getId() == idBuscar) {
                p->setContenido(nuevoContenido);
                cambiado = true;
            }
            });
        return cambiado;
    }

    bool eliminarPost(int id) {
        if (usuarioActual == nullptr) return false;
        return usuarioActual->posts.eliminar([&](Post* p) { return p->getId() == id; });
    }

    // COMENTARIOS CON HASHTABLE 
    void comentarPost(int idPost, string texto, string fecha) {
        if (usuarioActual == nullptr) return;

        Comentario* c = new Comentario(idPost, usuarioActual->getUsername(), texto, fecha);

        //Insertar en HashTable usando idPost como clave
        string clave = to_string(idPost);
        hashComentarios.insertar(clave, c);

        guardarComentario(c);
        cout << "✓ Comentario agregado al post #" << idPost << "\n";
    }

    void guardarComentario(Comentario* c) {
        ofstream file("comentarios.txt", ios::app);
        file << c->getIdPost() << "|" << c->getAutor() << "|" << c->getTexto() << "|" << c->getFecha() << "\n";
        file.close();
    }

    //  Mostrar comentarios de un post desde HashTable
    void mostrarComentariosDePost(int idPost) {
        cout << "\n===== COMENTARIOS DEL POST #" << idPost << " =====\n";

        bool hayComentarios = false;
        hashComentarios.buscar([&](Comentario* c) {
            if (c->getIdPost() == idPost) {
                c->mostrar();
                hayComentarios = true;
            }
            return false;  // Seguir buscando todos
            });

        if (!hayComentarios) {
            cout << "No hay comentarios en este post.\n";
        }
        cout << "==========================================\n";
    }

    // Mostrar estadísticas de HashTable
    void mostrarEstadisticasComentarios() {
        hashComentarios.mostrarEstadisticas();
    }

    // AMIGOS 
    void agregarAmigo(string amigo) {
        if (usuarioActual == nullptr) return;

        usuarioActual->agregarAmigo(amigo);
        amigos.agregarAmigo(usuarioActual->getUsername(), amigo);
        cout << "✓ Amigo \"" << amigo << "\" agregado\n";
    }

    void mostrarAmigos() {
        if (usuarioActual == nullptr) return;

        cout << "\n===== MIS AMIGOS =====\n";
        int contador = 0;
        usuarioActual->amigos.recorrer([&](string a) {
            cout << ++contador << ". " << a << endl;
            });
        cout << "Total: " << contador << " amigos\n";
        cout << "======================\n";
    }

	// Liberar memoria
    ~ControladoraIG() {
        if (amigosOrdenados != nullptr) {
            delete[] amigosOrdenados;
        }
    }
};