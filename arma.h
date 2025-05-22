#ifndef ARMA_H
#define ARMA_H

#include "equipamiento.h"
#include <iostream>
using namespace std;

class Arma : public Equipamiento {
public:
    int dano;

    // Constructor completo
    Arma(string n, string d, int id, float p, int dura, int dano)
        : Equipamiento(n, d, id, p, dura ), dano(dano) {}

    // Constructor sobrecargado (versión mínima)
    Arma(string n, float p, int dano)
        : Equipamiento(n, ".", 0, p, 100), dano(dano) {}

    void usararma() {
        cout << "Atacaste con " << nombre << " causando " << dano << " de dano." << endl;
        durabilidad--;
    }
};

#endif
