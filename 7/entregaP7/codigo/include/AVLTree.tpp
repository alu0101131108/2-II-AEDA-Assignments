#ifndef _AVLTREE_
#define _AVLTREE_

#include "../include/AVLNode.tpp"
#include "../include/BBTree.tpp"

template <class T>
class AVLTree : public BBTree<T>
{
  private:
    AVLNode<T>* root;

  public:
    AVLTree():BBTree<T>()
    {}

    void Insertar( T data)
    {
        AVLNode<T>* newNode = new AVLNode<T>(data);
        bool increase = false;
        inserta_bal(get_Raiz(), newNode, increase);
    }

    void Eliminar( T data)
    {
        bool decrease = false;
        elimina_rama(get_Raiz(), data, decrease);
    }

    AVLNode<T>*& get_Raiz()
    {
        return reinterpret_cast<AVLNode<T>*&>(BBTree<T>::get_Raiz());
    }

    void inserta_bal( AVLNode<T>*& node, AVLNode<T>* newNode, bool& increase)
    {
        if (node == NULL)
        {
            node = newNode;
            increase = true;
        }
        else if (newNode->get_Clave() < node->get_Clave())
        {
            inserta_bal(node -> izdo, newNode, increase);
            if (increase)
              insert_re_balancea_izda(node, increase);
        }
        else
        {
            inserta_bal(node -> dcho, newNode, increase);
            if (increase)
              insert_re_balancea_dcha(node, increase);
        }
    }

    void insert_re_balancea_izda(AVLNode<T>*& node, bool& increase)
    {
        switch (node -> bal)
        {
          case -1:
            node->bal = 0;
            increase = false;
            break;
          case 0:
            node->bal = 1 ;
            break;
          case 1:
            AVLNode<T>* nodo1 = node->izdo;
            if (nodo1->bal == 1)
              rotacion_II(node);
            else
              rotacion_ID(node);
            increase = false;
          }
    }

    void insert_re_balancea_dcha (AVLNode<T>*& node, bool& increase)
    {
        switch (node->bal)
        {
          case 1:
            node->bal = 0;
            increase = false;
            break;
          case 0:
            node->bal = -1;
            break;
          case -1:
            AVLNode<T>* nodo1 = node->dcho;
              if (nodo1->bal == -1)
                rotacion_DD(node);
              else
                rotacion_DI(node);
            increase = false;
        }
    }

    void elimina_rama( AVLNode<T>*& node, T data, bool& decrease)
    {
        if (node == NULL)
          return;
        if (data < node -> get_Clave())
        {
          elimina_rama(node->izdo, data, decrease);
          if (decrease)
            eliminar_re_balancea_izda(node,decrease);
        }
        else if (data > node -> get_Clave())
        {
            elimina_rama(node -> dcho, data, decrease);
            if (decrease)
                eliminar_re_balancea_dcha(node, decrease);
        }
        else
        {
            AVLNode<T>* Eliminado = node;
            if (node->izdo == NULL)
            {
                node = node->dcho;
                decrease = true;
            }
            else if (node->dcho == NULL)
            {
                node = node->izdo;
                decrease = true;
            }
            else
            {
                sustituye(Eliminado,node->izdo,decrease);
                if (decrease)
                    eliminar_re_balancea_izda(node,decrease);
            }
            delete Eliminado;
        }
    }

    void sustituye(AVLNode<T>*& eliminado, AVLNode<T>*& sust, bool &decrease)
    {
        if (sust->dcho != NULL)
        {
            sustituye(eliminado, sust->dcho, decrease);
            if (decrease)
                eliminar_re_balancea_dcha(sust, decrease);
        }
        else
        {
            eliminado->clave = sust->get_Clave();
            eliminado = sust;
            sust = sust->izdo;
            decrease = true;
        }
    }

    void eliminar_re_balancea_izda (AVLNode<T>*& node, bool& decrease)
    {
        AVLNode<T>* nodo1 = node->dcho;
        switch (node->bal)
        {
            case -1:
                if (nodo1->bal > 0)
                    rotacion_DI(node);
                else
                {
                    if (nodo1->bal == 0)
                        decrease = false;
                    rotacion_DD(node);
                }
            break;
            case 0:
                node->bal = -1;
                decrease = false;
            break;
            case 1:
                node->bal = 0;
        }
    }

    void eliminar_re_balancea_dcha (AVLNode<T>*& node, bool& decrease)
    {
        AVLNode<T>* nodo1 = node->izdo;
        switch (node->bal)
        {
            case 1:
                if (nodo1->bal < 0)
                    rotacion_ID(node);
                else
                {
                    if (nodo1->bal == 0)
                        decrease = false;
                    rotacion_II(node);
                }
            break ;
            case 0:
                node->bal = 1;
                decrease = false;
            break;
            case -1:
                node->bal = 0;
        }
    }

    void rotacion_II (AVLNode<T>* &node)
    {
        AVLNode<T>* nodo1 = node->izdo;
        node->izdo = nodo1->dcho;
        nodo1->dcho = node;
        if (nodo1->bal == 1) {
        node->bal = 0;
        nodo1->bal = 0;
        }
        else { // nodo1->bal == 0
        node->bal = 1;
        nodo1->bal = -1;
        }
        node = nodo1;
    }

    void rotacion_DD (AVLNode<T>* &node)
    {
     AVLNode<T>* nodo1 = node->dcho;
     node->dcho = nodo1->izdo;
     nodo1->izdo = node ;
     if (nodo1->bal == -1) {
     node->bal = 0;
     nodo1->bal = 0;
     }
     else { // nodo1->bal == 0
     node->bal = -1;
     nodo1->bal = 1;
     }
     node = nodo1;
    }

    void rotacion_ID (AVLNode<T>* &node)
    {
     AVLNode<T>* nodo1 = node->izdo;
     AVLNode<T>* nodo2 = nodo1->dcho;
     node->izdo = nodo2->dcho;
     nodo2->dcho = node;
     nodo1->dcho = nodo2->izdo;
     nodo2->izdo = nodo1;
     if (nodo2->bal == -1)
     nodo1->bal = 1;
     else nodo1->bal = 0;
     if (nodo2->bal == 1)
     node->bal = -1;
     else node->bal = 0;
     nodo2->bal = 0;
     node = nodo2;
    }

    void rotacion_DI (AVLNode<T>* &node)
    {
     AVLNode<T>* nodo1 = node->dcho;
     AVLNode<T>* nodo2 = nodo1->izdo;
     node->dcho = nodo2->izdo;
     nodo2->izdo = node;
     nodo1->izdo = nodo2->dcho;
     nodo2->dcho = nodo1;
     if (nodo2->bal == 1)
     nodo1->bal = -1;
     else nodo1->bal = 0;
     if (nodo2->bal == -1)
     node->bal = 1;
     else node->bal = 0;
     nodo2->bal = 0;
     node = nodo2;
    }

};

#endif
