#ifndef JUGADOR_H          
#define JUGADOR_H

#include <string>         
#include <iostream>          
#include "item.h"             // Incluye la clase base de items
#include "inventario.h"       // Incluye el sistema de inventario
using namespace std;

class Jugador {
private:
    string nombre;            // Nombre del jugador
    float monedas;            // Cantidad de monedas
    int vida;                 // Vida del jugador
    float mana;               // Mana del jugador
    inventario inv;           // Inventario

public:
    Jugador(string n, float m, int v, float ma);     // Constructor
    void agregarMonedas(float precio);              // Agrega monedas al jugador
    void mostrarStats();                            // Muestra las estadisticas
    void venderItem(Item* item);                    // Vende un item del inventario
    void agregarItem(Item* item);                   // Agrega item al inventario
    void agregarMana(Item* item);                   // Agrega mana si el item otorga
    void mostrarInv();                              // Muestra inventario
    void usarItem();                                // Usa un item del inventario
};

// Constructor que inicializa los atributos del jugador
Jugador::Jugador(string nom, float m, int v, float ma) {
    nombre = nom;
    monedas = m;
    vida = v;
    mana = ma;
}

// Suma monedas al saldo actual
void Jugador::agregarMonedas(float precio) {
    monedas += precio;
}
    
// Imprime estadisticas actuales del jugador
void Jugador::mostrarStats() {
    cout << "Estadisticas del Jugador:\n";
    cout << "- Nombre: " << nombre << endl;
    cout << "- Vida: " << vida << endl;
    cout << "- Mana: " << mana << endl;
    cout << "- Monedas: " << monedas << endl;
    cout <<  endl; 
}

// Imprime mensaje de venta y agrega el precio al saldo
void Jugador::venderItem(Item* item) {
    cout << "Se vendio: " << item->getNombre() << " por " << item->getPrecio() << " monedas." << endl;
    agregarMonedas(item->getPrecio());
}

// Llama a la funcion de mostrar inventario del objeto inv
void Jugador::mostrarInv() {
    inv.mostrarInv();
}

// Llama al metodo usar del inventario
void Jugador::usarItem() {
    inv.usarItem();
}

// Agrega un item al inventario
void Jugador::agregarItem(Item* item) {
    inv.agregarItem(item);
}

// Aumenta el mana usando el metodo getMana del item
void Jugador::agregarMana(Item* item) { 
    mana += item->getMana();
}

#endif
