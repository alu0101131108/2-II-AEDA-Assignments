#ifndef _BNODE_
#define _BNODE_

#include <cstdio>

template <class T>
class BNode
{
  public:
    T clave;
    BNode<T>* izdo;
    BNode<T>* dcho;

    BNode(const T dat, BNode<T> *izq = NULL, BNode<T> *der = NULL): clave(dat), izdo(izq), dcho(der)
    {}

    void imprimirNodo()
    {
        std::cout << long(clave);
    }

    virtual BNode<T>* get_Dcho()
    {
        return dcho;
    }

    virtual BNode<T>* get_Izdo()
    {
        return izdo;
    }

    T get_Clave()
    {
        return clave;
    }
};

#endif
