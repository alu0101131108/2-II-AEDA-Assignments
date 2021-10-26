#include "Vector.hpp"

template <class T>
void Vector<T>::push_back(T item)
{
  size++;
  cout << "size: " << size << endl;
  v[size - 1] = item;
}

template <class T>
void Vector<T>::resize(int sz)
{
  Vector<T> aux(size);                  // Creo una copia del vector.
  for(int i = 0; i < size;  i++)
    aux[i] = v[i];
  int aux_sz = (sz < size ? sz : size);
  delete[] v;                           // Se vacía el vector y se le asigna el nuevo tamaño.
  v = new T[sz];
  size = sz;
  for(int i = 0; i < aux_sz; i++)       // Se recuerdan los elementos antiguos que estuvieran dentro del nuevo tamaño.
    v[i] = aux[i];
}

template <class T>
int Vector<T>::get_size(void)
{
  return size;
}

template <class T>
void Vector<T>::basic_type_print(void)
{
  for(int i = 0; i < size; i++)
    cout << v[i] << " ";
  cout << endl;
}
