#include <iostream>
using namespace std;
#include "Item.h"
#include "Consumible.h"
#include "PocionSalud.h"
#include "Equipamiento.h"
#include "Arma.h"
#include "Armadura.h"


int main() {
    // Crear objetos de cada una de las clases
    Item* item1 = new PocionSalud("Pocion de vida", "Restaura vida", 1, 25, 0.0f, 50);
    Item* item2 = new Arma("Espada corta", "Espada basica", 2, 100, 50, 15, 0, "corte", "espada");
    Item* item3 = new Armadura("Armadura de cuero", "Protege como pechera", 3, 75, 40, "fisica", 0.15f, "Pecho");
    Item* item4 = new Item("telescopio movil", "Un objeto mistico", 4, 10);

    cout << "--- Ejemplo de Uso de distintos objetos de inventario ---\n" << endl;

    item1->usar();
    cout << "-----------------------------\n";
    item2->usar();
    cout << "-----------------------------\n";
    item3->usar();
    cout << "-----------------------------\n";
    item4->usar();
    cout << "-----------------------------\n";

    return 0;
}
