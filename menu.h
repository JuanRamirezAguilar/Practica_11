#ifndef MENU_H
#define MENU_H

#include <list>

#include "contacto.h"
#include "fileManager.h"

enum OPCIONES {INSERTAR = 1, BUSCAR, LISTARTEL, LISTARNOM, SALIR};

class Menu {
    private:
        list<Contacto> misContactos;
        FileManager miArchivo;

    public:
        Menu();
        ~Menu();
        int menuPrincipal();
        void insertar();
        void buscar();
        void listarPorTelefono();
        void listarPorNombre();
        void Default();
};

#endif