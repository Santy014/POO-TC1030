#include <iostream>                          // Entrada y salida estándar
#include "item.h"                            // Clase base de ítems
#include "consumible.h"                      // Definición de consumibles
#include "equipamiento.h"                    // Definición de armas y armaduras
#include "inventario.h"                      // Gestión del inventario
#include "jugador.h"                         // Clase Jugador
#include <limits>                            // Usado para limpiar el buffer
using namespace std;

int main() {
    string nombre;

    // Sección de creación del personaje
    cout << "------------------------------------------" << endl; 
    cout << "----------- Crea tu Personaje! -----------" << endl; 
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << "Cual seria el nombre del jugador?" << endl;
    cin >> nombre;

    // Inicializa al jugador con 0 monedas, 100 de vida y 100 de mana
    Jugador Player(nombre, 0 , 100, 100);

    // Muestra mensaje de confirmación y estadísticas
    cout << "Se ha registrado al jugador "<< endl; 
    Player.mostrarStats();
    cout << "Estas son estadisticas iniciales, las estadisticas aumentan gracias a tu equipamiento!" << endl; 
    cout << endl;
    cout << "Presione cualquier tecla para continuar!";
    cin.get(); // Espera un input

    int opcion = -1;
    while (opcion != 0) {
        // Menú principal del sistema
        cout << "\nMenu:\n";
        cout << "1. Agregar item\n";
        cout << "2. Mostrar inventario y usar item\n";
        cout << "3. Mostrar estadisticas\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        //Sistema para gregar item
        if (opcion == 1) {
            // Selección de tipo de item
            cout << "Tipo de item (1=Arma, 2=Armadura): ";
            int tipo;
            cin >> tipo;

            if (tipo == 1) {
                // Ingreso de datos para crear un arma
                string n,d,tD,tA,slot;
                int id,dura,da,mun;
                float precio;
                
                cout << "Nombre: ";
                cin >> n;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                
                cout << "Descripcion: ";
                cin >> d;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "ID: ";
                cin >> id;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); // tras ejecutar el codigo multiples veces al llegar a esta linea
                // el codigo entraba en un loop interminable, la unica solución que encontré en linea que limpia el buffer de entrada, por lo que al
                // corre nuevamente el codigo ya no entraba en ese loop 
                
                cout << "Precio: ";
                cin >> precio;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "Durabilidad: ";
                cin >> dura;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "Slot: ";
                cin >> slot; 
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "Dano: ";
                cin >> da;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "Municion: ";
                cin >> mun;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "Slot: ";               
                cin >> slot; 
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Crea el arma y la agrega al inventario
                Arma* arma = new Arma(n,d,id,precio,0,1,dura,da,mun,slot);
                Player.agregarItem(arma);
            } else if (tipo == 2) {
                // Ingreso de datos para crear una armadura
                string n,d,slot,parte;
                int id,dura, mana;
                float precio,reduc;

                cout << "Nombre: ";
                cin >> n;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Descripcion: ";
                cin >> d;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "ID: ";
                cin >> id;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Precio: ";
                cin >> precio;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Durabilidad: ";
                cin >> dura;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Slot: ";
                cin >> slot; 
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Reduccion de dano (0-1): ";
                cin >> reduc;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Parte de armadura: ";
                cin >> parte;
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Mana adicional: ";
                cin >> mana; 
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Crea la armadura y la agrega al inventario
                Armadura* armadura = new Armadura(n,d,id,precio,0,1,dura,slot,reduc,parte, mana);
                Player.agregarItem(armadura);
            }
        } else if (opcion == 2) {
            // Muestra el inventario y permite usar un item
            Player.mostrarInv();
            Player.usarItem();
        } else if (opcion == 3) {
            // Muestra las estadisticas del jugador
            Player.mostrarStats();
        }
    }

    return 0;
}
