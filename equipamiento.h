#ifndef EQUIPAMIENTO_H
#define EQUIPAMIENTO_H

#include "item.h"
#include <iostream>
using namespace std;

class Equipamiento : public Item {
    protected: //en tipo protected para que las clases hijas puedan acceder a los atributos 
    int durabilidad;
    string tipoSlot;
    
    public:


        Equipamiento(string n, string d, int id, float p,bool ac, int maxC, int dura, string slot)
        : Item(n,d, id, p, ac, maxC), durabilidad(dura), tipoSlot(slot) {}
    
        Equipamiento(string n, string d, int id, float p, int maxC, int dura)
        : Item(n, d, id, p, maxC), durabilidad(dura), tipoSlot(".") {}

        int getDurabilidad() const {
        return durabilidad;
    }
        void usar()  {
        cout << "Equipaste " << nombre << " en el slot: " << tipoSlot << endl;
    }
};

using namespace std;

class Arma : public Equipamiento {
public:
    int dano;
    int municion; 
    string tipoDano; 
    string tipoArma;

    Arma(string n, string d, int id, float p, bool ac, int maxC, int dura, int da, int mun, string tD, string tA, string slot)
    : Equipamiento(n, d, id, p, ac, maxC, dura, slot), dano(da), municion(mun), tipoDano(tD), tipoArma(tA) {}
    Arma(string n, float p, int da)
    : Equipamiento(n, ".", 0, p, 100, 100), dano(da), municion(0), tipoDano(""), tipoArma("") {}

    void usar() {
        cout << "Atacaste con " << nombre << " causando " << dano << " de dano." << endl;
        durabilidad--;
    }
};

using namespace std;

class Armadura : public Equipamiento {
    private:
        string tipoDefensa;
        float reducDano; 
        string parteArmor; 
    public:
    Armadura(string n , string d, int id, float p, bool ac, int maxC, int dura, string slot, float rD, string pA)
        : Equipamiento(n, d, id, p, ac, maxC, dura, slot), reducDano(rD), parteArmor(pA) {}

        void usar()  {
        cout << "Te equipaste la armadura " << nombre << " que reduce " << reducDano * 100 << " porciento del dano." << endl;
        }
};


#endif
