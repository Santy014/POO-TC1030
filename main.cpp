#include <iostream>
#include "Item.h"
#include "Consumible.h"
#include "Equipamiento.h"
#include "inventario.h"

using namespace std;

int main() {
    inventario inv;

    Arma* espada = new Arma("Espada Fuerte", "Una espada filosa que derrota a los mas grandes enemigos", 12356, 45, false, 1, 100, 50, 0, "Fisico", "Espada", "Arma");
    Arma* vara = new Arma("Varita Magica", "Una poderosa varita magica", 22356, 100, false, 1, 80, 30, 10, "Magico", "Vara", "Arma");
    PocionSalud* pociongrande = new PocionSalud("Pocion Grande", "Una pocion grande que te cura 200 de vida", 12324, 20, 1, 200);

    inv.agregarItem(espada);
    inv.agregarItem(vara);
    inv.agregarItem(pociongrande);

    inv.mostrarInv();
    inv.UsarItem();

    return 0;
}
