#include <cassert>
#include <iostream>

template <class T>
class Vector
{
  private:
    T* v;
    int size;

  public:
    Vector(): v(NULL), size(0)
    {}

    Vector(int sz): v(new T[sz]), size(sz)
    {}

    ~Vector(void)
    {
      delete[] v;
    }

    T& operator[](int pos)
    {
      assert((pos < size) && (pos >=0));
      return v[pos];
    }

    Vector& operator=(Vector vec)
    {
      delete[] v;
      size = vec.get_size();
      v = new T[size];
      for(int i = 0; i < size; i++)
      v[i] = vec[i];

      return *this;
    }

    void push_back(T item)
    {
      resize(size + 1);
      v[size - 1] = item;
      // Así funciona pero no tiene sentido (?).
      // size++;
      // v[size - 1] = item;
    }
    void resize(int sz)
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
    int get_size(void)
    {
      return size;
    }
    void basic_type_print(void)
    {
      for(int i = 0; i < size; i++)
        std::cout << v[i] << " ";
      std::cout << std::endl;
    }
};
