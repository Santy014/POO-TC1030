#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include"jugador.h"
using namespace std;


class Item {
public:
    string nombre;
    string descripcion;
    int id;
    float precio;
    int maxCant; // a partir de si el objeto es acumulable establecemos un limite de acumulacion 
    int cantidad;  // este atributo lo utilizamos para mantener un recuento de cuanto falta para , ESTOS ATRIBUTOS SE USARAN DESPUES
    bool acumulable; // este atributo nos establecera si el objeto es acumulable o no 

    Item(string n, string d, int i, float p)
        : nombre(n), descripcion(d), id(i), precio(p) {}

    virtual void usar() {
        cout << "Usaste el item: " << nombre << endl;
    }

    void venderItem(Jugador& jugador) {
        cout << "Se vendio: " << nombre << " por " << precio << " monedas." << endl;
        jugador.agregarMonedas(precio);
    }

};

#endif