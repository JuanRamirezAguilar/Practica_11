#include <iostream>
#include <windows.h>

#include "menu.h"

using namespace std;

int main () {
    SetConsoleOutputCP(CP_UTF8);
    Menu miMenu;
    int opc;
    while ((opc = miMenu.menuPrincipal()) != SALIR) {
        switch (opc) {
            case INSERTAR: miMenu.insertar(); break;
            case BUSCAR: miMenu.buscar(); break;
            case LISTARTEL: miMenu.listarPorTelefono(); break;
            case LISTARNOM: miMenu.listarPorNombre(); break;
            default: miMenu.Default(); break;
        }
    }
    cout << endl << "Saliendo del programa."; cin.clear(); cin.sync(); cin.ignore();
    return 0;
}