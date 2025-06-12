#ifndef CONSUMIBLE_H        
#define CONSUMIBLE_H

#include"item.h"              
#include<iostream>          
using namespace std;     

class Consumible : public Item {  // Clase base para ítems de un solo uso
private:
    float duracion;           // Duración del efecto del consumible (si aplica)

public: 
    // Constructor con duracion definida
    Consumible(string n, string d, int id, float p, int maxC, float dur)
        : Item(n, d, id, p, maxC), duracion(dur) {}

    // Constructor sin duracion 
    Consumible(string n, string d, int id, float p, int maxC)
        : Item(n, d, id, p, maxC), duracion(0) {}
};

// Clase hija: pocion de salud 
class PocionSalud : public Consumible  {
private: 
    int cantVida;             // Cantidad de vida que restaura

public: 
    // Constructor 
    PocionSalud(string n, string d, int id, float p,int maxC, int cV) 
        : Consumible(n, d, id, p, maxC), cantVida(cV) {}

    void usar() {
        // Efecto al consumir la poción
        cout << "La pocion se ha consumido, curandote " << cantVida << " puntos de vida " << endl;
    }
};

#endif  // Cierra el guardia de inclusión
