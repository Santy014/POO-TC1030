#include "item.h"
#include "arma.h"

int main() {
    Jugador jugador(50);
    Arma espada("Espada Fragil", "Espada de Piedra", 1, 25, 50, 10);

    espada.usararma();
    jugador.mostrarMonedas();
    espada.venderItem(jugador);
    jugador.mostrarMonedas();

    return 0;
}
