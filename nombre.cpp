#include "nombre.h"
#include <iostream>

using std::string;

// Constructores
Nombre::Nombre() : nombres(""), apellidoPaterno(""), apellidoMaterno("") {}
Nombre::Nombre(std::string name, std::string apPaterno, std::string apMaterno) : nombres(name), apellidoPaterno(apPaterno), apellidoMaterno(apMaterno) {}
Nombre::Nombre(const Nombre& copia) : nombres(copia.nombres), apellidoPaterno(copia.apellidoPaterno), apellidoMaterno(copia.apellidoMaterno) {}

// Destructor
Nombre::~Nombre() {}

// Metodos
string Nombre::toString() const{
    return nombres + " " + apellidoPaterno + " " + apellidoMaterno;
}

// Setters
void Nombre::setNombre(string valorNombre) {nombres = valorNombre;}
void Nombre::setApellidoPaterno(std::string valorApPaterno) { apellidoPaterno = valorApPaterno; }
void Nombre::setApellidoMaterno(std::string valorApMaterno) { apellidoMaterno = valorApMaterno; }

// Getters
string Nombre::getNombre() {return nombres;}
std::string Nombre::getApellidoPaterno() { return apellidoPaterno; }
std::string Nombre::getApellidoMaterno() { return apellidoMaterno; }

// Operadores
Nombre& Nombre::operator=(const Nombre& copia) {
    if (this == &copia) { return *this; }
    nombres = copia.nombres;
    apellidoPaterno = copia.apellidoPaterno;
    apellidoMaterno = copia.apellidoMaterno;
    return *this;
}

bool Nombre::operator == (const Nombre& comparado) const{
    return (nombres == comparado.nombres) && (apellidoPaterno == comparado.apellidoPaterno) && (apellidoMaterno == comparado.apellidoMaterno);
}

bool Nombre::operator != (const Nombre& comparado) const{
    return !(*this == comparado);
}

bool Nombre::operator < (const Nombre& comparado) const{
    if (nombres < comparado.nombres) {
            return true;
    } else if (nombres == comparado.nombres) {
        return apellidoPaterno < comparado.apellidoPaterno;
    } else {
        return apellidoMaterno < comparado.apellidoMaterno;
    }
    return false;
}

bool Nombre::operator > (const Nombre& comparado) const{
    if (nombres > comparado.nombres) {
            return true;
    } else if (nombres == comparado.nombres) {
        return apellidoPaterno > comparado.apellidoPaterno;
    } else {
        return apellidoMaterno > comparado.apellidoMaterno;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Nombre& objSalida) {
    out << objSalida.nombres << "*" << objSalida.apellidoPaterno << "*" << objSalida.apellidoMaterno << "*";
    return out;
}

std::istream& operator >> (std::istream& in, Nombre& objEntrada) {
    std::string myString;
    std::getline(in, myString, '*');
    objEntrada.setNombre(myString);
    std::getline(in, myString, '*');
    objEntrada.setApellidoPaterno(myString);
    std::getline(in, myString, '*');
    objEntrada.setApellidoMaterno(myString);
    return in;
}