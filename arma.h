#ifndef ARMA_H
#define ARMA_H

#include "equipamiento.h"
#include <iostream>
using namespace std;

class Arma : public Equipamiento {
public:
    int dano;
    int municion; 
    string tipoDano; 
    string tipoArma;


    Arma(string n, string d, int id, float p, int dura, int da, int mun, string tD, string tA)
        : Equipamiento(n, d, id, p, dura), dano(da), municion(mun), tipoDano(tD), tipoArma(tA) {}

    Arma(string n, float p, int da)
        : Equipamiento(n, ".", 0, p, 100), dano(da), municion(0), tipoDano(""), tipoArma("") {}

    void usar() {
        cout << "Atacaste con " << nombre << " causando " << dano << " de dano." << endl;
        durabilidad--;
    }
};

#endif
