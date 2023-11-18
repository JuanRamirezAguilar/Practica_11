#include "contacto.h"

#include <iostream>

// Constructores
Contacto::Contacto() : telefono("") {}
Contacto::Contacto(Nombre valorNombre, std::string valorTelefono) : nombre(valorNombre), telefono(valorTelefono) {}
Contacto::Contacto(const Contacto & copia) : nombre(copia.nombre), telefono(copia.telefono) {}
Contacto::~Contacto() {}

// Metodos
std::string Contacto::toString() const {
    return nombre.toString() + ", " + telefono;
}

// Setters
void Contacto::setNombre(Nombre valorNombre) { nombre = valorNombre; }
void Contacto::seTelefono(std::string valorTelefono) { telefono = valorTelefono; }

// Getters
Nombre Contacto::getNombre() const { return nombre; }
std::string Contacto::getTelefono() const { return telefono; }

// Operadores
Contacto & Contacto::operator=(const Contacto & copia) {
    if (this == &copia) { return *this; }

    nombre = copia.nombre;
    telefono = copia.telefono;
    return *this;
}

bool Contacto::operator==(const Contacto & comparado) const {
    return (nombre == comparado.nombre) && (telefono == comparado.telefono);
}

bool Contacto::operator!=(const Contacto & comparado) const {
    return !(*this == comparado);
}

bool Contacto::operator<(const Contacto & comparado) const {
    return nombre < comparado.nombre;
}

bool Contacto::operator>(const Contacto & comparado) const {
    return nombre > comparado.nombre;
}

std::ostream & operator<<(std::ostream & out, const Contacto & objSalida) {
    out << objSalida.nombre;
    out << objSalida.telefono;
    out << std::string("*");

    return out;
}

std::istream & operator>>(std::istream & in, Contacto & objEntrada) {
    // Toma el nombre del contacto
    in >> objEntrada.nombre;

    // Toma el telefono del contacto
    std::string miCadena;
    std::getline(in, miCadena, '*');
    objEntrada.seTelefono(miCadena);

    return in;
}
