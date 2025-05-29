#ifndef EQUIPAMIENTO_H
#define EQUIPAMIENTO_H

#include "item.h"

class Equipamiento : public Item {
protected: //en tipo protected para que las clases hijas puedan acceder a los atributos 
    int durabilidad;
    string tipoSlot;
public:


    Equipamiento(string n, string d, int id, float p, int dura, string slot)
        : Item(n, d, id, p), durabilidad(dura), tipoSlot(slot) {}
    
    Equipamiento(string n, string d, int id, float p, int dura)
    : Item(n, d, id, p), durabilidad(dura), tipoSlot(".") {}

    int getDurabilidad() const {
        return durabilidad;
    }
     void usar()  {
        cout << "Equipaste " << nombre << " en el slot: " << tipoSlot << endl;
    }
};

#endif
