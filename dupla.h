#ifndef Dupla_H
#define Dupla_H

#include <string>
#include <iostream>

template <class DATA = std::string> 
class Dupla {
    private:
        int index;
        DATA data;

    public:
        Dupla();
        Dupla(const Dupla&);
        Dupla(const int&, const DATA&);
        Dupla(const DATA&);
        ~Dupla();

        int getIndex()const;
        DATA getData() const;
        
        void setIndex(const int&);
        void setData(const DATA&);

        Dupla& operator = (const Dupla&);
        Dupla& operator = (const DATA&);
        bool operator == (const Dupla&);
        bool operator != (const Dupla&);
        bool operator < (const Dupla&);
        bool operator <= (const Dupla&);
        bool operator > (const Dupla&);
        bool operator >= (const Dupla&);

        template <class x>
        friend std::istream& operator >> (std::istream&, Dupla<x>&);
        template <class x>
        friend std::ostream& operator << (std::ostream&, Dupla<x>&);

};

using namespace std;

// Constructores
template <class DATA>
Dupla<DATA>::Dupla() {}
template<class DATA>
Dupla<DATA>::Dupla(const Dupla& t) : index(t.index), data(t.data) {}
template<class DATA>
Dupla<DATA>::Dupla(const int& i, const DATA &e) : index(i), data(e) {}
template<class DATA>
Dupla<DATA>::Dupla(const DATA &e) : data(e) {}

// Destructor
template <class DATA>
Dupla<DATA>::~Dupla() {}

// Getters
template<class DATA>
int Dupla<DATA>::getIndex() const { return index; }

template<class DATA>
DATA Dupla<DATA>::getData() const { return data; }

// Setters
template<class DATA>
void Dupla<DATA>::setIndex(const int &i) {
    index = i;
}

template<class DATA>
void Dupla<DATA>::setData(const DATA &e) { data = e; }

// Operadores
template<class DATA>
Dupla<DATA> & Dupla<DATA>::operator=(const Dupla &t) {
    if (this == &t) {
        return *this;
    }

    this->index = t.index;
    this->data = t.data;

    return *this;
}

template<class DATA>
Dupla<DATA>& Dupla<DATA>::operator=(const DATA &e) {
    data = e;
    return *this;
}

template<class DATA>
inline bool Dupla<DATA>::operator==(const Dupla &t) {
    return (this->data == t.data);
}

template<class DATA>
inline bool Dupla<DATA>::operator!=(const Dupla &t) {
    return !(*this == t);
}

template<class DATA>
inline bool Dupla<DATA>::operator<(const Dupla &t) {
    return (this->index < t.index);
}

template<class DATA>
inline bool Dupla<DATA>::operator<=(const Dupla &t) {
    return (this->index <= t.index);
}

template<class DATA>
inline bool Dupla<DATA>::operator>(const Dupla &t) {
    return (this->index > t.index);
}

template<class DATA>
inline bool Dupla<DATA>::operator>=(const Dupla &t) {
    return (this->index >= t.index);
}

// Operadores de flujo
template<class x>
istream& operator >> (istream& is, Dupla<x>& t) {
    string mySring;

    getline(is, mySring, '*');
    t.index = stoi(mySring);

    is >> t.data;

    return is;
}

template<class x>
ostream& operator << (ostream& os, Dupla<x>& t) {
    os << t.index << "*";
    os << t.data << "*";
    return os;
}

template <class DATA>
std::ostream& operator<<(ostream& os, const Dupla<DATA>& t) {
    os << t.getIndex() << "*" << t.getData() << "*";
    return os;
}

#endif //Dupla_H