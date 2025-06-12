#ifndef INVENTARIO_H        
#define INVENTARIO_H

#include<iostream>        
#include "item.h"         

using namespace std;        // Permite usar cout y cin sin std::

class inventario  {         // Define la clase inventario
    private:
        Item *items[36];    // Arreglo de punteros a Item, capacidad máxima 36
        int indice = 0;     // Lleva el control de cuantos ítems hay

    public:
        void agregarItem(Item* item) {           // Agrega un ítem al inventario
            if (indice < 36) {                   // Verifica si hay espacio
                items[indice] = item;            // Coloca el ítem en la posición libre
                indice++;                        // Aumenta el contador de ítems
                cout << "Se ha agregado el item: " << item->nombre << endl; // Mensaje
            } else {
                cout << "Inventario lleno, no se puede agregar el item: " << item->nombre << endl; // Mensaje si está lleno
            };
        }

        void mostrarInv() {                      // Muestra el contenido del inventario
            cout << "Inventario: " << endl;      // Título de sección
            for(int i = 0, j = 1; i < indice; i++, j++) {  // Recorre los ítems existentes
                cout << j << ". " << items[i]->nombre << " - x" << items[i]->cantidad << endl; // Muestra nombre y cantidad
            }
            int disponibles = 36 - indice;       // Calcula cuántos espacios quedan
            cout << "- Hay un total de " << disponibles << " espacios disponibles para inventario."; // Muestra espacios libres
        }

        void usarItem() {                        // Permite seleccionar y usar un ítem
            mostrarInv();                        // Muestra el inventario antes
            cout << "Selecciona el numero del item que deseas seleccionar: "; // Pide selección
            int seleccion;                       // Variable para guardar la opción
            cin >> seleccion;                    // Lee la opción del usuario
            items[seleccion-1]->usar();          // Llama al método usar() del ítem elegido
        };
};

#endif  // Final del guardia de inclusión
