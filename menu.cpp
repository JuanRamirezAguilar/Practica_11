#include "menu.h"

#include <iostream>
#include <algorithm>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void pausa() {
    std::cin.clear(); std::cin.sync(); std::cin.ignore();
}

Menu::Menu() {}
Menu::~Menu() {}

int Menu::menuPrincipal() {
    int opcMenu;
    system(CLEAR);
    std::cout << "\tMenú - Agenda de contactos" <<std::endl<<std::endl;
    std::cout << "1. Insertar contacto." <<std::endl;
    std::cout << "2. Buscar contacto." <<std::endl;
    std::cout << "3. Listar contacto por orden de teléfonos." <<std::endl;
    std::cout << "4. Listar contactos por orden natural." <<std::endl;
    std::cout << "5. Salir." <<std::endl;
    std::cout << "Elige tu opcion >> ";
    cin >> opcMenu;

    return opcMenu;
}

void Menu::insertar() {
    std::string strAux1, strAux2, strAux3, strAux4;

    std::cout << std::endl << "Dame el nombre del contacto: ";
    fflush(stdin);
    std::getline(std::cin, strAux1);

    std::cout << std::endl << "Dame el apellido paterno del contacto: ";
    fflush(stdin);
    std::getline(std::cin, strAux2);

    std::cout << std::endl << "Dame el apellido materno del contacto: ";
    fflush(stdin);
    std::getline(std::cin, strAux3);

    std::cout << std::endl << "Dame el telefono del contacto: ";
    fflush(stdin);
    std::getline(std::cin, strAux4);

    Nombre nuevoNombre(strAux1, strAux2, strAux3);
    Contacto nuevoContacto(nuevoNombre, strAux4);

    miArchivo.addData(nuevoContacto);
    std::cout << std::endl << "Contacto guardado con exito"; pausa();
}

void Menu::buscar() {
    std::string telToFind;

    std::cout << std::endl << "Dame el telefono del contacto a buscar: ";
    fflush(stdin);
    std::getline(std::cin, telToFind);

    miArchivo.reIndexacion();
    int idx = miArchivo.findData(telToFind);

    if (idx != -1) {
        Contacto contactoEncontrado = miArchivo.getData(idx);

        std::cout << std::endl << "Datos de del contacto:" << std::endl;
        std::cout << "Nombre: " << contactoEncontrado.getNombre().getNombre() << "." << std::endl;
        std::cout << "Apellidos: " << contactoEncontrado.getNombre().getApellidoPaterno() << " " << contactoEncontrado.getNombre().getApellidoMaterno() << "." << std::endl;
        std::cout << "N° de Telefono: " << contactoEncontrado.getTelefono() << "."; pausa();
    } else {
        std::cout << std::endl << "No se encontro contacto con esa informacion." <<std::endl; pausa();
    }
}

void Menu::listarPorTelefono() {
    misContactos = miArchivo.toList();
    
    misContactos.sort([](const Contacto& a, const Contacto& b) {
        return a.getTelefono() < b.getTelefono();
    });

    std::cout<<std::endl;
    for (const auto& contacto : misContactos) {
        std::cout << "Contacto: " << std::endl;
        std::cout << "Telefono: " << contacto.getTelefono() << ", ";
        std::cout << "Nombre: " << contacto.getNombre().getNombre() << ", ";
        std::cout << "Apellido Paterno: " << contacto.getNombre().getApellidoPaterno() << ", ";
        std::cout << "Apellido Materno: " << contacto.getNombre().getApellidoMaterno() << std::endl<<std::endl;
    }
    pausa();
}

void Menu::listarPorNombre() {
    misContactos = miArchivo.toList();
    /*misContactos.sort();*/

    std::cout<<std::endl;
    for (const auto& contacto : misContactos) {
        std::cout << "Contacto: " << std::endl;
        std::cout << "Nombre: " << contacto.getNombre().getNombre() << ", ";
        std::cout << "Apellido Paterno: " << contacto.getNombre().getApellidoPaterno() << ", ";
        std::cout << "Apellido Materno: " << contacto.getNombre().getApellidoMaterno() << ", ";
        std::cout << "Telefono:" << contacto.getTelefono() << std::endl<<std::endl;
    }
    pausa();
}

void Menu::Default() {
    std::cout << std::endl << "Opcion equivocada, intentalo de nuevo."; pausa();
}


