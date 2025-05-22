#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Jugador {
private:
    float monedas;
public:
    Jugador(float m) : monedas(m) {}

    void agregarMonedas(float cantidad) {
        monedas += cantidad;
    }

    void mostrarMonedas() const {
        cout << "Monedas actuales: " << monedas << endl;
    }
};

class Item {
public:
    string nombre;
    string descripcion;
    int id;
    float precio;

    Item(string n, string d, int i, float p)
        : nombre(n), descripcion(d), id(i), precio(p) {}

    void usar() {
        cout << "Usaste el item: " << nombre << endl;
    }

    void venderItem(Jugador& jugador) {
        cout << "Se vendio: " << nombre << " por " << precio << " monedas." << endl;
        jugador.agregarMonedas(precio);
    }
};

#endif