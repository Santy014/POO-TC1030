#ifndef ARMADURA_H
#define ARMADURA_H

#include "equipamiento.h"
#include <iostream>

using namespace std;

class Armadura : public Equipamiento {
    private:
        string tipoDefensa;
        float reducDano; 
        string parteArmor; 
    public:
        Armadura(string n , string d, int id, float p, int dura, string tS, float rD, string pA)
            : Equipamiento(n, d, id, p, dura), reducDano(rD), parteArmor(pA) {}

        void usar()  {
        cout << "Te equipaste la armadura " << nombre << " que reduce " << reducDano * 100 << " porciento del dano." << endl;
        }
};

#endif
