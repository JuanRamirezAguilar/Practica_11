#ifndef NOMBRE_H
#define NOMBRE_H

#include <string>

class Nombre {
    private:
        std::string nombres;
        std::string apellidoPaterno;
        std::string apellidoMaterno;

    public:
        // Constructores
        Nombre();
        Nombre(std::string name, std::string apPaterno, std::string apMaterno);
        Nombre(const Nombre& copia);
        // Destructor
        ~Nombre();
        // Metodos
        std::string toString() const;
        // Setters
        void setNombre(std::string valorNombre);
        void setApellidoPaterno(std::string valorApPaterno);
        void setApellidoMaterno(std::string valorApMaterno);
        // Getters
        std::string getNombre();
        std::string getApellidoPaterno();
        std::string getApellidoMaterno();
        // Operadores
        Nombre &operator = (const Nombre& copia);
        bool operator == (const Nombre& comparado) const;
        bool operator != (const Nombre& comparado) const;
        bool operator < (const Nombre& comparado) const;
        bool operator > (const Nombre& comparado) const;
        friend std::ostream& operator << (std::ostream& out, const Nombre& objSalida);
        friend std::istream& operator >> (std::istream& in, Nombre& objEntrada);
};

#endif