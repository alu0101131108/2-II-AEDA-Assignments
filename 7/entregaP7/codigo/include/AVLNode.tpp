#ifndef _AVLNODE_
#define _AVLNODE_

#include "../include/BNode.tpp"

template <class T>
class AVLNode : public BNode<T>
{
  public:
    int bal;
    AVLNode<T>* izdo;
    AVLNode<T>* dcho;

    AVLNode(T dat, AVLNode<T> *iz = NULL, AVLNode<T> *de = NULL): BNode<T>(dat)
    {
        bal = 0;
        izdo = iz;
        dcho = de;
    }

    AVLNode<T>* get_Izdo()
    {
        return izdo;
    }

    AVLNode<T>* get_Dcho()
    {
        return dcho;
    }
};

#endif
