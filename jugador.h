#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <iostream>
#include "Item.h"  
#include "inventario.h"
using namespace std;

class Jugador {
private:
    string nombre;
    float monedas;
    int vida;
    float mana; 
    inventario inv;
public:
    Jugador(string n, float m, int v, float ma);
    void agregarMonedas(float precio);
    void mostrarStats();
};


Jugador::Jugador(string nom, float m, int v, float ma) {
    nombre = nom;
    monedas = m;
    vida = v;
    mana = ma;
}

void Jugador::agregarMonedas(float precio) {
    monedas += precio;
}
    
void Jugador::mostrarStats() {
    cout << "Estadísticas del Jugador:\n";
    cout << "- Nombre: " << nombre << endl;
    cout << "- Vida: " << vida << endl;
    cout << "- Mana: " << mana << endl;
    cout << "- Monedas: " << monedas << endl;
    cout << "-----------------------------" << endl;
    cout << "Si deseas ver el inventario, pulsa 1, si no pulsa 0: " << endl;
    int eleccion;
    cin >> eleccion;
    if (eleccion == 1) {
        cout << "Mostrando inventario..." << endl;
        inv.mostrarInv(); 
    } else {
        cout << "No se mostrará el inventario." << endl;
    }
    void venderItem(Item* item) {
    cout << "Se vendio: " << item->getNombre() << " por " << item->getPrecio() << " monedas." << endl;
    agregarMonedas(item->getPrecio());
}

}
#endif