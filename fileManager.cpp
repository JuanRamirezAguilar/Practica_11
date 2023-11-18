#include "fileManager.h"

#include <sstream>

#define FILENAME "contactos.txt"
#define FILEINDEX "indice.txt"

FileManager::FileManager() : fileName(FILENAME), fileNameIndex(FILEINDEX) {
    crearArchivos(fileName);
    crearArchivos(fileNameIndex);
}

FileManager::~FileManager() {
    if (archivo.is_open())
        archivo.close();
    if (fileIndices.is_open())
        fileIndices.close();
}

void FileManager::crearArchivos(const std::string & nameFile) {
    std::ifstream file(nameFile);
    if (!file.good()) {
        std::ofstream create(nameFile);
        create.close();
    }
    file.close();
}

void FileManager::reIndexacion() {
    std::string miString;
    int miIndice;
    Contacto miContacto;
    Dupla<> duplaIndices;

    archivo.open(fileName, std::ios_base::in);
    if (!archivo.is_open())
        throw std::ios_base::failure("Error en Indexacion.");

    indices.clear();

    while (!archivo.eof()) {
        miIndice = int(archivo.tellg());
        std::getline(archivo, miString, '#');
        if (miString.empty())
            continue;
    
        stringstream miFlujo(miString);

        std::getline(miFlujo, miString, '*');
        if (miString == "1") {
            miFlujo >> miContacto;

            duplaIndices.setIndex(miIndice);
            duplaIndices.setData(miContacto.getTelefono());
            indices.push_back(duplaIndices);
            miListaDeContactos.push_back(miContacto);
        }
    }

    fileIndices.open(fileNameIndex, std::ios_base::out | std::ios_base::trunc);
    if (!fileIndices.is_open())
        throw std::ios_base::failure("Error en Indexacion.");

    // Se pasa los indices a su archivo.
    fileIndices.clear();
    listToFile(fileIndices, indices);
    fileIndices.close();

    archivo.close();
}

template <class T>
list<T> FileManager::fileToList(std::fstream & miFile, list<T> miLista) {
    std::string miString;
    T data;

    while (std::getline(miFile, miString, '#')) {
        if (!miString.empty()) {
            stringstream miFlujo(miString);

            std::getline(miFlujo, miString, '*');

            if (miString == "1") {
                miFlujo >> data;
                miLista.push_back(data);
            }
        }
    }
    return miLista;
}

template<class T>
void FileManager::listToFile(std::fstream & miFile, const list<T> & miLista) {
    for (const auto& elemento : miLista) {
        miFile << "1*" << elemento << "#";
    }
}

template<class T>
int FileManager::getIndex(const list<Dupla<T>>& miLista, const T & e) const {
    for (auto it = miLista.begin(); it != miLista.end(); ++it) {
        if (it->getData() == e) {
            return it->getIndex();
        }
    }
    return -1;
}

void FileManager::addData(Contacto & nuevoContacto) {
    list<Contacto> nuevaLista;
    nuevaLista.push_back(nuevoContacto);
    addData(nuevaLista);
}

void FileManager::addData(list<Contacto> & miLista) {
    archivo.open(fileName, std::ios_base::out | std::ios_base::app);
    if (!archivo.is_open())
        throw std::ios_base::failure("Error en addData.");

    listToFile(archivo, miLista);
    archivo.close();
    reIndexacion();
}

Contacto FileManager::getData(const int idx) {
    string miString;
    Contacto miContacto;

    archivo.open(fileName, std::ios_base::in);
    if (!archivo.is_open())
        throw std::ios_base::failure("Error en addData.");

    archivo.seekg(idx);
    std::getline(archivo, miString, '#');
    if (miString.empty()) {
        throw std::ios_base::failure("Dato inexistente.");
    }

    stringstream miFlujo(miString);
    getline(miFlujo, miString, '*');
    if (miString == "0")
        throw std::ios_base::failure("Dato borrado.");

    miFlujo >> miContacto;

    archivo.close();
    return miContacto;
}

int FileManager::findData(const std::string & tel) const {
     return getIndex<std::string>(indices, tel);
}

void FileManager::clearFile() {
    std::remove(fileName.c_str());
}


list<Contacto> FileManager::toList() { 
    archivo.open(fileName, std::ios_base::in);
    if (!archivo.is_open())
        throw ios_base::failure("Error en toList");

    list<Contacto> listaAux;
    listaAux = fileToList(archivo, listaAux);
    archivo.close();

    return listaAux;
}