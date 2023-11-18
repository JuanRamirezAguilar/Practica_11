#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>

#include "nombre.h"

class Contacto {
    private:
        Nombre nombre;
        std::string telefono;

    public:
        // Constructores
        Contacto();
        Contacto(Nombre valorNombre, std::string valorTelefono);
        Contacto(const Contacto & copia);
        ~Contacto();

        // Metodos
        std::string toString() const;

        // Setters
        void setNombre(Nombre valorNombre);
        void seTelefono(std::string valorTelefono);

        // Getters
        Nombre getNombre() const;
        std::string getTelefono() const;

        // Operadores
        Contacto &operator = (const Contacto& copia);
        bool operator == (const Contacto& comparado) const;
        bool operator != (const Contacto& comparado) const;
        bool operator < (const Contacto& comparado) const;
        bool operator > (const Contacto& comparado) const;
        friend std::ostream& operator << (std::ostream& out, const Contacto& objSalida);
        friend std::istream& operator >> (std::istream& in, Contacto& objEntrada);
};

#endif