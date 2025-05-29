#include<iostream>
#include"consumible.h"

using namespace std;
class PocionSalud : public Consumible  { 
    private: 
    int cantVida; 
    public: 
    PocionSalud(string n, string d, int id, float p, float dur, int cV) 
        : Consumible(n, d, id, p, dur), cantVida(cV) {};
        void usar() {  
            cout << "La pocion se ha consumido, curandote " << cantVida << " puntos de vida " << endl;
        };
};

