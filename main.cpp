#include <iostream>
#include "item.h"
#include "consumible.h"
#include "equipamiento.h"
#include "inventario.h"
#include "jugador.h"
#include <limits>
using namespace std;

int main() {
    string nombre;

    cout << "------------------------------------------" << endl; 
    cout << "----------- Crea tu Personaje! -----------" << endl; 
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << "Cual seria el nombre del jugador?" << endl;
    cin >> nombre;

    Jugador Player(nombre, 0 , 100, 100);

     cout << "Se ha registrado al jugador "<< endl; 
     Player.mostrarStats();
     cout << "Estas son estadisticas iniciales, las estadisticas aumentan gracias a tu equipamiento!" << endl; 
     cout << endl;
     cout << "Presione cualquier tecla para continuar!";
     cin.get();

    int opcion = -1;
    while (opcion != 0) {
        cout << "\nMenu:\n";
        cout << "1. Agregar item\n";
        cout << "2. Mostrar inventario y usar item\n";
        cout << "3. Mostrar estadisticas\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Tipo de item (1=Arma, 2=Armadura): ";
            int tipo;
            cin >> tipo;

            if (tipo == 1) {
                string n,d,tD,tA,slot;
                int id,dura,da,mun;
                float precio;
                cout << "Nombre: ";
                cin >> n;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Descripcion: ";
                cin >> d;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID: ";
                cin >> id;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Precio: ";
                cin >> precio;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Durabilidad: ";
                cin >> dura;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Slot: ";
                cin >> slot; 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Dano: ";
                cin >> da;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Municion: ";
                cin >> mun;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Slot: ";
                cin >> slot; 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Arma* arma = new Arma(n,d,id,precio,0,1,dura,da,mun,slot);
                Player.agregarItem(arma);
            } else if (tipo == 2) {
                string n,d,slot,parte;
                int id,dura, mana ;
                float precio,reduc;
                cout << "Nombre: ";
                cin >> n;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Descripcion: ";
                cin >> d;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID: ";
                cin >> id;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Precio: ";
                cin >> precio;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Durabilidad: ";
                cin >> dura;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Slot: ";
                cin >> slot; 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Reduccion de dano (0-1): ";
                cin >> reduc;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Parte de armadura: ";
                cin >> parte;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Mana adicional: ";
                cin >> mana; 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Armadura* armadura = new Armadura(n,d,id,precio,0,1,dura,slot,reduc,parte, mana );
                Player.agregarItem(armadura);
            }
        } else if (opcion == 2) {
            Player.mostrarInv();
            Player.usarItem();
        } else if (opcion == 3) {
            Player.mostrarStats();
        }
    }
    

    return 0;
}
