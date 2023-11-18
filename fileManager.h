#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <list>

#include "lista.h"
#include "dupla.h"
#include "contacto.h"

class FileManager {
    private:
        std::string fileName;
        std::string fileNameIndex;
        std::fstream archivo;
        std::fstream fileIndices;

        list<Contacto> miListaDeContactos;
        //Lista<Contacto> miListaDeContactos;
        list<Dupla<>> indices;

    public:
        FileManager();
        ~FileManager();

        void crearArchivos(const std::string& nameFile);
        void reIndexacion();
        template <class T>
        list<T> fileToList(std::fstream & miFile, list<T> miLista);
        template <class T>
        void listToFile(std::fstream & miFile, const list<T> & miLista);
        void addData(Contacto & nuevoContacto);
        void addData(list<Contacto> & miLista);
        template <class T>
        int getIndex(const list<Dupla<T>> & miLista, const T & e) const;
        Contacto getData(const int idx);
        int findData(const std::string & tel) const;
        void clearFile();

        list<Contacto> toList();
};

#endif