#ifndef EQUIPAMIENTO_H         
#define EQUIPAMIENTO_H

#include "item.h"             
#include <iostream>           
using namespace std;           

// Clase base para todo equipo equipable (armas, armaduras, etc.)
class Equipamiento : public Item {
protected:
    int durabilidad;           // Cantidad de uso antes de romperse
    string tipoSlot;           // Indica en qué parte se equipa (casco, pechera, etc)

public:
    // Constructor completo con acumulabilidad y tipo de slot
    Equipamiento(string n, string d, int id, float p,bool ac, int maxC, int dura, string slot)
    : Item(n,d, id, p, ac, maxC), durabilidad(dura), tipoSlot(slot) {}

    // Constructor sin acumulabilidad ni slot personalizado
    Equipamiento(string n, string d, int id, float p, int maxC, int dura)
    : Item(n, d, id, p, maxC), durabilidad(dura), tipoSlot(".") {}

    // Constructor con acumulabilidad pero slot predeterminado
    Equipamiento(string n, string d, int id, float p, bool ac, int maxC, int dura)
    : Item(n, d, id, p, ac, maxC), durabilidad(dura), tipoSlot(".") {}

    int getDurabilidad() const {
        return durabilidad;    // Devuelve la durabilidad del objeto
    }

    void usar() {
        cout << "Equipaste " << nombre << " en el slot: " << tipoSlot << endl;
    }
};

// Clase Arma: hereda de Equipamiento
class Arma : public Equipamiento {
public:
    int dano;                  // Daño que causa el arma
    int municion;              // Munición disponible

    // Constructor completo con todos los campos
    Arma(string n, string d, int id, float p, bool ac, int maxC, int dura, int da, int mun, string slot)
    : Equipamiento(n, d, id, p, ac, maxC, dura, slot), dano(da), municion(mun) {}

    // Constructor sin slot
    Arma(string n, string d, int id, float p, bool ac, int maxC, int dura, int da, int mun)
    : Equipamiento(n, d, id, p, ac, maxC, dura), dano(da), municion(mun) {}

    // Constructor simple 
    Arma(string n, float p, int da)
    : Equipamiento(n, ".", 0, p, 100, 100), dano(da), municion(0) {}

    void usar() {
        cout << "Atacaste con " << nombre << " causando " << dano << " de dano." << endl;
        durabilidad--;         // Reduce la durabilidad tras el uso
    }
};

// Clase Armadura: hereda de Equipamiento
class Armadura : public Equipamiento {
private:
    float reducDano;          // Porcentaje de reducción de daño (0 a 1)
    string parteArmor;        // Parte del cuerpo que cubre
    int mana;                 // Mana adicional que otorga

public:
    // Constructor completo con todos los atributos específicos
    Armadura(string n , string d, int id, float p, bool ac, int maxC, int dura, string slot, float rD, string pA, int m)
    : Equipamiento(n, d, id, p, ac, maxC, dura, slot), reducDano(rD), parteArmor(pA), mana(m) {}

    void usar() {
        // Acción de equipar una armadura y mostrar su efecto
        cout << "Te equipaste la armadura " << nombre << " que reduce " << reducDano * 100 << " porciento del dano." << endl;
    }

    int getMana() const {
        return mana;           // Devuelve el bono de mana que ofrece
    }
};

#endif  // Fin del guardia de inclusión
