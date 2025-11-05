#pragma once
#include <iostream>
#include <vector>
#include "Nodo.h"
using namespace std;

template <class T, class LessT = less<T>>
class ArbolBinario
{
private:
    Nodo<T>* raiz = nullptr;
    LessT less{};

    // Vector temporal (para modo posicional)
    vector<Nodo<T>*> nodos;

    // ---------- MODO ABB ----------
    void insertarRecursivo(Nodo<T>*& nodo, const T& valor) {
        if (nodo == nullptr)
            nodo = new Nodo<T>(valor);
        else if (less(valor, nodo->dato))
            insertarRecursivo(nodo->left, valor);
        else
            insertarRecursivo(nodo->right, valor);
    }

    // ---------- RECORRIDOS ----------
    void preOrderRecursivo(Nodo<T>* nodo) const {
        if (!nodo) return;
        cout << nodo->dato << endl;
        preOrderRecursivo(nodo->left);
        preOrderRecursivo(nodo->right);
    }

    void inOrderRecursivo(Nodo<T>* nodo) const {
        if (!nodo) return;
        inOrderRecursivo(nodo->left);
        cout << nodo->dato << endl;
        inOrderRecursivo(nodo->right);
    }

    void postOrderRecursivo(Nodo<T>* nodo) const {
        if (!nodo) return;
        postOrderRecursivo(nodo->left);
        postOrderRecursivo(nodo->right);
        cout << nodo->dato << endl;
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    // ====================================================
    // ===============    MODO ABB NORMAL   ================
    // ====================================================
    void insertar(const T& valor) {
        insertarRecursivo(raiz, valor);
    }

    bool vacio() const { return raiz == nullptr; }

    void mostrarPreOrder() const {
        cout << "\n--- RECORRIDO PRE ORDER ---\n";
        preOrderRecursivo(raiz);
    }

    void mostrarInOrder() const {
        cout << "\n--- RECORRIDO IN ORDER ---\n";
        inOrderRecursivo(raiz);
    }

    void mostrarPostOrder() const {
        cout << "\n--- RECORRIDO POST ORDER ---\n";
        postOrderRecursivo(raiz);
    }

    // ====================================================
    // ============   MODO POSICIONAL IMPLÍCITO   =========
    // ====================================================
    void construirPosicional(const vector<T>& datos) {
        if (datos.empty()) return;

        // limpiar si había datos anteriores
        nodos.clear();
        raiz = nullptr;

        int cantidad = datos.size();
        nodos.resize(cantidad + 1, nullptr);

        // crear nodos
        for (int i = 1; i <= cantidad; ++i)
            nodos[i] = new Nodo<T>(datos[i - 1]);

        // enlazar hijos según posición
        for (int i = 1; i <= cantidad; ++i) {
            int izq = 2 * i;
            int der = 2 * i + 1;
            if (izq <= cantidad) nodos[i]->left = nodos[izq];
            if (der <= cantidad) nodos[i]->right = nodos[der];
        }

        raiz = nodos[1];
    }

    Nodo<T>* getRaiz() const { return raiz; }

    void mostrarPosicionalPreOrder() const {
        cout << "\n--- PRE ORDER (ÁRBOL POSICIONAL) ---\n";
        preOrderRecursivo(raiz);
    }

    void mostrarPosicionalInOrder() const {
        cout << "\n--- IN ORDER (ÁRBOL POSICIONAL) ---\n";
        inOrderRecursivo(raiz);
    }

    void mostrarPosicionalPostOrder() const {
        cout << "\n--- POST ORDER (ÁRBOL POSICIONAL) ---\n";
        postOrderRecursivo(raiz);
    }
};
