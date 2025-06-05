#ifndef CONSUMIBLE_H
#define CONSUMIBLE_H
#include"item.h"
#include<iostream>

using namespace std;

class Consumible : public Item {
    private:
        float duracion; 
    public: 
        Consumible(string n, string d, int id, float p, int maxC, float dur)
            :Item(n, d, id, p, maxC), duracion(dur) {}
        Consumible(string n, string d, int id, float p, int maxC)
            : Item(n, d, id, p, maxC), duracion(0) {}
        
        };
        
class PocionSalud : public Consumible  { 
    private: 
    int cantVida; 
    public: 
    PocionSalud(string n, string d, int id, float p,int maxC, int cV) 
        : Consumible(n, d, id, p, maxC), cantVida(cV) {};
        void usar() {  
            cout << "La pocion se ha consumido, curandote " << cantVida << " puntos de vida " << endl;
        };
};


#endif

