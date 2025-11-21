#pragma once
#include <string>
#include <iostream>
using namespace std;
class Cuenta {
public:
    virtual ~Cuenta() = default;
    // Acciones comunes
    virtual void iniciarSesion(const std::string& correo, const std::string& contra) = 0;
    virtual void cerrarSesion() = 0;

    virtual void crearPost(const std::string& contenido) = 0;
    virtual void editarPost(int idPost, const std::string& nuevoContenido) = 0;
    virtual void eliminarPost(int idPost) = 0;

    virtual void comentar(int idPost, const std::string& comentario) = 0;
    virtual void eliminarComentario(int idComentario) = 0;

    virtual void reportarUsuario(int idUsuario) = 0;

    // Permisos (polimorfismo por comportamiento)
    virtual bool puedeBanear() const { return false; }
    virtual void banearUsuario(int /*idUsuario*/) {
        cout << "[Cuenta] No tienes permisos para banear.\n";
    }

    // Panel (muestra diferencias entre perfiles)
    virtual void verPanel() const {
        cout << "Panel básico de usuario.\n";
    }
};
