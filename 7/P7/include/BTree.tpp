#ifndef _BTREE
#define _BTREE

#include <queue>

#include "../include/BNode.tpp"

template <class T>
class BTree
{
  protected:
    BNode<T>* raiz;

  public:
   BTree() : raiz(NULL)
   {}

   ~BTree()
   {
     Podar(raiz);
   }

   void Podar(BNode<T>* &nodo)
   {
    if (nodo == NULL) return ;
    Podar(nodo->izdo);
    Podar(nodo->dcho);
    delete nodo;
    nodo = NULL;
   }

   void imprimirArbol()
   {
     if (raiz == NULL){std::cout<<"vacio"<<std::endl;
       return;}

     std::queue<BNode<T>*> cola;
     int nivel = 0;

     cola.push(raiz);

     while (!cola.empty())
     {
       int nNodos = cola.size();
       std::cout << "Nivel " << nivel << ": ";
       while (nNodos > 0) {
         BNode<T>* nodo = cola.front();
        imprimirNodo(nodo);
         cola.pop();

         if (nodo != NULL) {
           cola.push(nodo -> get_Izdo());
           cola.push(nodo -> get_Dcho());
         }
         nNodos--;
       }
       std::cout << '\n';
       nivel++;
     }
   }

   void imprimirNodo(BNode<T>* nodo)
   {
       if(nodo != NULL)
       {
           std::cout << "[" << long(nodo->clave) << "] ";
       }
       else {
           std::cout << "[.] ";
       }
   }

   int Brofundidad(BNode<T>* nodo)
   {
     int d = 0;
     while (nodo != NULL) {
       d++;
       nodo = nodo -> izdo;
     }
     return d;
   }

   bool arbolEquilibrado()
   {
     int d = profundidad(raiz);
     return nivelEquilibrado(raiz, d);
   }

   bool nivelEquilibrado(BNode<T>* nodo, int d, int nivel = 0)
   {

     if (nodo == NULL) {
       return true;
     }

     if (nodo -> izdo == NULL && nodo -> dcho == NULL) {
       return (d == nivel + 1);
     }

     if (nodo -> izdo == NULL || nodo -> dcho == NULL) {
       return false;
     }

     return nivelEquilibrado(nodo -> izdo, d, nivel + 1) && nivelEquilibrado(nodo -> dcho, d, nivel + 1);

   }
};



#endif
