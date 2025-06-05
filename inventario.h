#ifndef INVENTARIO_H
#define INVENTARIO_H

#include<iostream>
#include "item.h" 
using namespace std;

class inventario  {
    private:
        Item *items[36];
        int indice = 0;

    public:
        void agregarItem(Item* item) {
            if (indice < 36) {
                items[indice] = item;
                indice++;
                cout << "Se ha agregado el item: " << item->nombre << endl;
            } else {
                cout << "Inventario lleno, no se puede agregar el item: " << item->nombre << endl;
            };
        }
        void mostrarInv() { 
            cout << "Inventario: " << endl;
            for(int i = 0, j = 1; i < indice; i++, j++) {
                cout << j << ". " << items[i]->nombre << " - x" << items[i]->cantidad << endl;
            }
            int disponibles = 36 - indice;
            cout << "- Hay un total de " << disponibles << " espacios disponibles para inventario.";
        }
        void UsarItem() {
            mostrarInv();
            cout << "Selecciona el numero del item que deseas usar: ";
            int seleccion;
            cin >> seleccion;
            
            items[seleccion-1]->usar();
        }

 };

#endif


