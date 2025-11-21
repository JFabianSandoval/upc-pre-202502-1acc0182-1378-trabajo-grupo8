#pragma once
#include "Persona.h"
#include "Cuenta.h"
#include <iostream>
#include <string>
using namespace std;
template <class T>
class Admin : public Persona<T>, public Cuenta
{
private:
    bool estado; // Sesión activa o no
    bool validarInicioSesion(const string& correoIngresado, const T& contraIngresada) const
    {
        return (this->correo == correoIngresado) && (this->contrasenia == contraIngresada);
    }
public:
    // CONSTRUCTORES
    Admin() : Persona<T>(0, "", "", "", "", ""), estado(false) {}
    Admin(short id, T nom, T ape1, T ape2, string email, T contra)
        : Persona<T>(id, nom, ape1, ape2, email, contra), estado(false) {}
    // AUTENTICACIÓN
    void iniciarSesion(const string& correo, const T& contra) override
    {
        if (validarInicioSesion(correo, contra))
        {
            estado = true;
            cout << "[Admin] Inicio de sesión exitoso.\n";
        }
        else
        {
            cout << "[Admin] Credenciales incorrectas.\n";
        }
    }
    void cerrarSesion() override
    {
        if (estado)
        {
            estado = false;
            cout << "[Admin] Sesión cerrada.\n";
        }
        else
        {
            cout << "[Admin] No hay sesión activa.\n";
        }
    }
    // PERMISOS DE ADMINISTRADOR
    bool puedeBanear() const override { return true; }
    void banearUsuario(int idUsuario) override
    {
        if (estado)
        {
            cout << "[Admin] Usuario " << idUsuario << " ha sido baneado.\n";
        }
        else
        {
            cout << "[Admin] Debes iniciar sesión para banear usuarios.\n";
        }
    }
    // PUBLICACIONES
    void crearPost(const string& contenido) override
    {
        if (!estado)
        {
            cout << "[Admin] Debes iniciar sesión.\n";
            return;
        }
        cout << "[Admin] Post creado: " << contenido << endl;
    }
    void editarPost(int idPost, const string& nuevoContenido) override
    {
        if (!estado)
        {
            cout << "[Admin] Debes iniciar sesión.\n";
            return;
        }
        cout << "[Admin] Post " << idPost << " editado a:\n" << nuevoContenido << endl;
    }
    void eliminarPost(int idPost) override
    {
        if (!estado)
        {
            cout << "[Admin] Debes iniciar sesión.\n";
            return;
        }
        cout << "[Admin] Post " << idPost << " eliminado.\n";
    }
    // COMENTARIOS
    void comentar(int idPost, const string& comentario) override
    {
        if (!estado)
        {
            cout << "[Admin] Debes iniciar sesión.\n";
            return;
        }
        cout << "[Admin] Comentaste en post " << idPost << ": " << comentario << endl;
    }
    void eliminarComentario(int idComentario) override
    {
        if (!estado)
        {
            cout << "[Admin] Debes iniciar sesión.\n";
            return;
        }
        cout << "[Admin] Comentario " << idComentario << " eliminado.\n";
    }
    // REPORTES
    void reportarUsuario(int idUsuario) override
    {
        cout << "[Admin] El usuario " << idUsuario << " ha sido reportado y evaluado.\n";
    }
    // PANEL PERSONALIZADO
    void verPanel() const override
    {
        cout << "\n===== PANEL DE ADMINISTRADOR =====\n";
        cout << "• Gestionar posts\n";
        cout << "• Eliminar comentarios\n";
        cout << "• Banear usuarios\n";
        cout << "• Supervisar actividad\n";
        cout << "• Edición global del sistema\n";
        cout << "==================================\n\n";
    }
};
