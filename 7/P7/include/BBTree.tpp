#ifndef _BBTREE_
#define _BBTREE_

#include "../include/BNode.tpp"
#include "../include/BTree.tpp"

template <class T>
class BBTree : public BTree<T>
{
  public:
    BBTree()
    {
      BTree<T>::raiz = NULL;
    }

    ~BBTree()
    {}

    BNode<T>*& get_Raiz()
    {
        return BTree<T>::raiz;
    }

    BNode<T>* Buscar( T clave_dada )
    {
      return BuscarRama(BTree<T>::raiz, clave_dada);
    }

    BNode<T>* BuscarRama( BNode<T>* nodo, T clave_dada)
    {
     if (nodo == NULL)
     return NULL ;
     if (clave_dada == nodo->clave)
     return nodo ;
     if (clave_dada < nodo->clave )
     return BuscarRama(nodo->get_Izdo(), clave_dada);
     return BuscarRama(nodo->get_Dcho(), clave_dada);
    }

    bool Insertar( T clave_dada)
    {
     InsertarRama( BTree<T>::raiz, clave_dada);
     return true;
    }

    bool InsertarRama( BNode<T>* &nodo, T clave_dada)
    {
     if (nodo == NULL)
     nodo = new BNode<T>(clave_dada);
     else if (clave_dada < nodo->clave)
     InsertarRama(nodo->izdo, clave_dada);
     else
     InsertarRama(nodo->dcho, clave_dada);
     return true;
    }

    bool Eliminar( T clave_dada)
    {
     EliminarRama( BTree<T>::raiz, clave_dada) ;
     return true;
    }

    void EliminarRama( BNode<T>* &nodo, T clave_dada)
    {
     if (nodo == NULL) return;
     if (clave_dada < nodo->clave)
     EliminarRama(nodo->izdo, clave_dada);
     else if (clave_dada > nodo->clave)
     EliminarRama(nodo->dcho, clave_dada);
    else {
     BNode<T>* Eliminado = nodo;
     if (nodo->dcho == NULL)
     nodo = nodo->izdo;
     else if (nodo->izdo == NULL)
     nodo = nodo->dcho;
     else
     sustituye(Eliminado, nodo->izdo);
     delete (Eliminado);
     }
    }

    void sustituye(BNode<T>* &eliminado, BNode<T>* &sust)
    {
     if (sust->dcho != NULL)
     sustituye(eliminado, sust->dcho);
     else {
     eliminado->clave = sust->clave ;
     eliminado = sust ;
     sust = sust->izdo ;
     }
    }
};

#endif
