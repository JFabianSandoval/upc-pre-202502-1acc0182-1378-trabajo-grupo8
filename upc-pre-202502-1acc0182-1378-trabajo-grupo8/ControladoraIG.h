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
        srand(time(NULL));
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
        cout << "\n " << contador << " usuarios cargados en memoria (Lista)\n";
    }
    // ============= CARGAR POSTS DESDE ARCHIVO =============
    void cargarPostsDesdeArchivo() {
        ifstream file("Posts.txt");
        if (!file.is_open()) {
            cout << " No se pudo abrir Posts.txt (el archivo puede no existir aún)\n";
            return;
        }

        string linea;
        int contador = 0;

        while (getline(file, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string autor, idStr, contenido, fecha;

            getline(ss, autor, '|');
            getline(ss, idStr, '|');
            getline(ss, contenido, '|');
            getline(ss, fecha);

            // Limpiar espacios y saltos de línea
            while (!autor.empty() && (autor.back() == '\r' || autor.back() == '\n' || autor.back() == ' '))
                autor.pop_back();
            while (!fecha.empty() && (fecha.back() == '\r' || fecha.back() == '\n' || fecha.back() == ' '))
                fecha.pop_back();

            int id = stoi(idStr);

            // Crear post y agregarlo a la lista global
            Post* p = new Post(id, autor, contenido, fecha);
            posts.insertarFinal(p);

            // Buscar el usuario autor y agregar el post a su lista personal
            listaUsuarios.recorrer([&](Usuario* u) {
                if (u->getUsername() == autor) {
                    u->posts.insertarFinal(p);
                }
                });

            contador++;
        }

        file.close();
        cout << " " << contador << " posts cargados desde Posts.txt\n";
    }

    // ============= CARGAR COMENTARIOS DESDE ARCHIVO =============
    void cargarComentariosDesdeArchivo() {
        ifstream file("Comentarios.txt");
        if (!file.is_open()) {
            cout << " No se pudo abrir Comentarios.txt (el archivo puede no existir aún)\n";
            return;
        }

        string linea;
        int contador = 0;

        while (getline(file, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string idPostStr, autor, texto, fecha;

            getline(ss, idPostStr, '|');
            getline(ss, autor, '|');
            getline(ss, texto, '|');
            getline(ss, fecha);

            // Limpiar espacios
            while (!autor.empty() && (autor.back() == '\r' || autor.back() == '\n' || autor.back() == ' '))
                autor.pop_back();
            while (!fecha.empty() && (fecha.back() == '\r' || fecha.back() == '\n' || fecha.back() == ' '))
                fecha.pop_back();

            int idPost = stoi(idPostStr);

            // Crear comentario e insertar en HashTable
            Comentario* c = new Comentario(idPost, autor, texto, fecha);
            string clave = to_string(idPost);
            hashComentarios.insertar(clave, c);

            contador++;
        }

        file.close();
        cout << " " << contador << " comentarios cargados desde Comentarios.txt\n";
    }

    // ============= CARGAR AMIGOS DESDE ARCHIVO =============
    void cargarAmigosDesdeArchivo() {
        ifstream file("amigos.txt");
        if (!file.is_open()) {
            cout << " No se pudo abrir Amigos.txt (el archivo puede no existir aún)\n";
            return;
        }

        string linea;
        int contador = 0;

        while (getline(file, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string usuario, amigo;

            getline(ss, usuario, '|');
            getline(ss, amigo);

            // Limpiar espacios
            while (!usuario.empty() && (usuario.back() == '\r' || usuario.back() == '\n' || usuario.back() == ' '))
                usuario.pop_back();
            while (!amigo.empty() && (amigo.back() == '\r' || amigo.back() == '\n' || amigo.back() == ' '))
                amigo.pop_back();

            // Buscar usuario y agregar amigo
            listaUsuarios.recorrer([&](Usuario* u) {
                if (u->getUsername() == usuario) {
                    u->agregarAmigo(amigo);
                }
                });

            contador++;
        }

        file.close();
        cout << " " << contador << " relaciones de amistad cargadas desde Amigos.txt\n";
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

        cout << " Se asignaron " << amigosAgregados << " amigos aleatorios a user1\n";
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
        cout << " Amigos ordenados alfabéticamente\n";
    }

    //Buscar amigo usando búsqueda binaria
    bool buscarAmigoBinario(string nombreAmigo) {
        if (amigosOrdenados == nullptr) {
            cout << "Error: Primero debes preparar la búsqueda binaria\n";
            return false;
        }

        int resultado = BusquedaBinaria::buscar(amigosOrdenados, 0, cantidadAmigosArray - 1, nombreAmigo);

        if (resultado != -1) {
            cout << "\n AMIGO ENCONTRADO: \"" << nombreAmigo << "\" en posición " << resultado << "\n";
            return true;
        }
        else {
            cout << "\n Amigo \"" << nombreAmigo << "\" NO encontrado\n";
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
            cout << "\n Login exitoso: " << username << "\n";
            return true;
        }
        else {
            cout << "\n Usuario o contraseña incorrectos\n";
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
        cout << " Post #" << id << " publicado\n";
    }

    void guardarPost(Post* p) {
        ofstream file("posts.txt", ios::app);
        file << p->getAutor() << "|" << p->getId() << "|" << p->getContenido() << "|" << p->getFecha() << "\n";
        file.close();
    }

    void mostrarMisPosts() {
        if (usuarioActual == nullptr) return;

        cout << "\n";
        for (int i = 0; i < 40; i++) cout << "=";
        cout << "\n       MIS POSTS\n";
        for (int i = 0; i < 40; i++) cout << "=";
        cout << "\n\n";

        if (usuarioActual->posts.longitud() == 0) {
            cout << "No tienes posts publicados\n";
        }
        else {
            usuarioActual->posts.recorrer([](Post* p) {
                p->mostrar();
                });
        }
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

    void mostrarTodosLosPostsEnumerados() {
        if (posts.longitud() == 0) {
            cout << "\nNo hay posts en el sistema\n";
            return;
        }

        cout << "\n+";
        for (int i = 0; i < 50; i++) cout << "-";
        cout << "+\n";

        cout << "|         TODOS LOS POSTS DEL SISTEMA           |\n";

        cout << "+";
        for (int i = 0; i < 50; i++) cout << "-";
        cout << "+\n";

        int contador = 1;
        posts.recorrer([&](Post* p) {
            cout << "\n[" << contador << "] ";
            p->mostrar();
            contador++;
            });

        cout << "\nTotal de posts: " << posts.longitud() << endl;
    }

    bool eliminarPost(int id) {
        if (usuarioActual == nullptr) return false;
        return usuarioActual->posts.eliminar([&](Post* p) { return p->getId() == id; });
    }


// COMENTARIOS CON HASHTABLE 
    void comentarPost(int idPost, string texto, string fecha) {
        if (usuarioActual == nullptr) return;

       
        Post* postEncontrado = nullptr;
        posts.recorrer([&](Post* p) {
            if (p->getId() == idPost) {
                postEncontrado = p;
            }
            });

        if (postEncontrado == nullptr) {
            cout << "\n Post #" << idPost << " no encontrado\n";
            return;
        }

        // Mostrar el post
        cout << "\n-----------------------------------\n";
        cout << "Vas a comentar en este post:\n";
        postEncontrado->mostrar();
        cout << "-----------------------------------\\n";

        Comentario* c = new Comentario(idPost, usuarioActual->getUsername(), texto, fecha);

        string clave = to_string(idPost);
        hashComentarios.insertar(clave, c);

        guardarComentario(c);
        cout << "\n Comentario agregado al post #" << idPost << "\n";

        mostrarComentariosDePost(idPost);
    }

    void guardarComentario(Comentario* c) {
        ofstream file("comentarios.txt", ios::app);
        file << c->getIdPost() << "|" << c->getAutor() << "|" << c->getTexto() << "|" << c->getFecha() << "\n";
        file.close();
    }

    //  Mostrar comentarios de un post desde HashTable
    void mostrarComentariosDePost(int idPost) {
        cout << "\n";
        for (int i = 0; i < 50; i++) cout << "=";
        cout << "\n  COMENTARIOS DEL POST #" << idPost << "\n";
        for (int i = 0; i < 50; i++) cout << "=";
        cout << "\n\n";

        bool hayComentarios = false;
        hashComentarios.buscar([&](Comentario* c) {
            if (c->getIdPost() == idPost) {
                c->mostrar();
                hayComentarios = true;
            }
            return false;
            });

        if (!hayComentarios) {
            cout << "No hay comentarios en este post.\n";
        }

        for (int i = 0; i < 50; i++) cout << "=";
        cout << "\n";
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

        // ⭐ NUEVO: Guardar en archivo
        ofstream file("Amigos.txt", ios::app);
        file << usuarioActual->getUsername() << "|" << amigo << "\n";
        file.close();

        cout << " Amigo \"" << amigo << "\" agregado\n";
    }

    void mostrarAmigos() {
        if (usuarioActual == nullptr) return;

        cout << "\n";
        for (int i = 0; i < 40; i++) cout << "=";
        cout << "\n       MIS AMIGOS\n";
        for (int i = 0; i < 40; i++) cout << "=";
        cout << "\n\n";

        int contador = 0;
        usuarioActual->amigos.recorrer([&](string a) {
            cout << ++contador << ". " << a << endl;
            });
        cout << "\nTotal: " << contador << " amigos\n";
        for (int i = 0; i < 40; i++) cout << "=";
        cout << "\n";
    }
    //Editar perfil
    
    void editarPerfil(string nuevoUsername, string nuevoPassword) {
        if (usuarioActual == nullptr) {
            cout << "Error: No hay usuario actual\n";
            return;
        }
        usuarioActual->setUsername(nuevoUsername);
        usuarioActual->setPassword(nuevoPassword);

        cout << "\n Perfil actualizado exitosamente\n";
        cout << "  Nuevo usuario: " << nuevoUsername << endl;
    }

    Usuario* buscarUsuarioPorNombre(string username) {
        Usuario* encontrado = nullptr;

        listaUsuarios.recorrer([&](Usuario* u) {
            if (u->getUsername() == username) {
                encontrado = u;
            }
            });

        return encontrado;
    }

    void buscarYMostrarUsuario(string username) {
        cout << "\nBuscando usuario \"" << username << "\"...\n";

        Usuario* user = buscarUsuarioPorNombre(username);

        if (user != nullptr) {
            cout << "\n[OK] USUARIO ENCONTRADO:\n";
            cout << "----------------------------\n";
            cout << "Username: " << user->getUsername() << endl;
            cout << "Posts publicados: " << user->posts.longitud() << endl;
            cout << "Amigos: " << user->cantidadAmigos() << endl;
            cout << "----------------------------\n";
        }
        else {
            cout << "\n[ERROR] Usuario \"" << username << "\" no encontrado\n";
        }
    }

    Lista<Post*> buscarPostsPorContenido(string palabraClave) {
        Lista<Post*> resultados;

        posts.recorrer([&](Post* p) {
           
            string contenido = p->getContenido();
            string palabra = palabraClave;

            // Búsqueda simple (contiene la palabra)
            if (contenido.find(palabra) != string::npos) {
                resultados.insertarFinal(p);
            }
            });

        return resultados;
    }

    void mostrarResultadosBusquedaPosts(string palabraClave) {
        cout << "\nBuscando posts con: \"" << palabraClave << "\"...\n";

        Lista<Post*> resultados = buscarPostsPorContenido(palabraClave);

        cout << "\n";
        for (int i = 0; i < 50; i++) cout << "=";
        cout << "\n  RESULTADOS DE BUSQUEDA\n";
        for (int i = 0; i < 50; i++) cout << "=";
        cout << "\n\n";

        if (resultados.longitud() == 0) {
            cout << "No se encontraron posts con esa palabra.\n";
        }
        else {
            cout << "[OK] Se encontraron " << resultados.longitud() << " posts:\n";
            resultados.recorrer([](Post* p) {
                p->mostrar();
                });
        }

        for (int i = 0; i < 50; i++) cout << "=";
        cout << "\n";
    }

   
    void mostrarEstadisticasGenerales() {
        int totalUsuarios = listaUsuarios.longitud();
        int totalPosts = posts.longitud();

        int totalComentarios = 0;
        hashComentarios.buscar([&](Comentario* c) {
            totalComentarios++;
            return false;
            });

        cout << "\n+";
        for (int i = 0; i < 52; i++) cout << "-";
        cout << "+\n";

        cout << "|     ESTADISTICAS DEL SISTEMA                     |\n";

        cout << "+";
        for (int i = 0; i < 52; i++) cout << "-";
        cout << "+\n";

        cout << "|                                                  |\n";
        cout << "|  DATOS GLOBALES:                                 |\n";
        cout << "|  - Usuarios registrados: " << totalUsuarios;
        for (int i = 0; i < 24; i++) cout << " ";
        cout << "|\n";

        cout << "|  - Posts totales: " << totalPosts;
        for (int i = 0; i < 32; i++) cout << " ";
        cout << "|\n";

        cout << "|  - Comentarios totales: " << totalComentarios;
        for (int i = 0; i < 28; i++) cout << " ";
        cout << "|\n";

        if (usuarioActual) {
            int misPostsCount = usuarioActual->posts.longitud();
            int totalAmigos = usuarioActual->cantidadAmigos();

            int misComentarios = 0;
            hashComentarios.buscar([&](Comentario* c) {
                if (c->getAutor() == usuarioActual->getUsername()) {
                    misComentarios++;
                }
                return false;
                });

            cout << "|                                                  |\n";
            cout << "|  TUS ESTADISTICAS:                               |\n";
            cout << "|  - Posts publicados: " << misPostsCount;
            for (int i = 0; i < 29; i++) cout << " ";
            cout << "|\n";

            cout << "|  - Amigos: " << totalAmigos;
            for (int i = 0; i < 39; i++) cout << " ";
            cout << "|\n";

            cout << "|  - Comentarios realizados: " << misComentarios;
            for (int i = 0; i < 24; i++) cout << " ";
            cout << "|\n";
        }

        cout << "|                                                  |\n";

        cout << "+";
        for (int i = 0; i < 52; i++) cout << "-";
        cout << "+\n";
    }
	// Liberar memoria
    ~ControladoraIG() {
        if (amigosOrdenados != nullptr) {
            delete[] amigosOrdenados;
        }
    }
};