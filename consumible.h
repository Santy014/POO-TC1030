#ifndef CONSUMIBLE_H
#define CONSUMIBLE_H
#include"item.h"
#include<iostream>

using namespace std;

class Consumible : public Item {
    private:
        float duracion; 
    public: 
        Consumible(string n, string d, int id, float p, float dur)
            :Item(n, d, id, p), duracion(dur) {}
        Consumible(string n, string d, int id, float p)
            : Item(n, d, id, p), duracion(0) {}
        
        };

#endif

