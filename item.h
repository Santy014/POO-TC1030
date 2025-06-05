#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

// En este caso item sería una clase abstracta, la cual me ayudaria a desarrollar items unicos
// como lo son los consumibles, equipamento, etc. Donde no se crearia un objeto "item", si no 
// que se desarrollaria un objeto hijo que cuente con atributos de la clase item.
class Item {
public:
    string nombre;
        string descripcion;
        int id;
        float precio;
        int maxCant; // a partir de si el objeto es acumulable establecemos un limite de acumulacion 
        int cantidad;  // este atributo lo utilizamos para mantener un recuento de cuanto falta para alcanzar maxCant
        bool acumulable; // este atributo nos establecera si el objeto es acumulable o no 
        Item(string n, string d, int id, float p, bool ac, int maxC)
            : nombre(n), descripcion(d), id(id), precio(p), maxCant(maxC), cantidad(0), acumulable(ac)
        {
            if (acumulable) {
                cantidad = 0; // si es acumulable, cantidad inicializa en 0
            } else {
                cantidad = 1; // si no es acumulable, cantidad es 1
            }
        }
        Item(string n, string d, int id, float p, int maxC)
        : nombre(n), descripcion(d), id(id), precio(p), maxCant(maxC), cantidad(0), acumulable(false)
        {
        cantidad = 1;
        }
        virtual void usar() = 0 //

        string getNombre() const {
             return nombre; 
            }
        float getPrecio() const { 
            return precio; 
            }
};
#endif


