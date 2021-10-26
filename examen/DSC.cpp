#include<iostream>
// Clase base DSC.
template <class T>
class dsc_base
{
  private:
    virtual std::ostream& write(std::ostream&) const = 0;

  public:
    virtual bool empty(void) const = 0;
    virtual void insert(const T&) = 0;
    virtual T retrieve(void) = 0;
    friend std::ostream& operator<<(std::ostream& os,dsc_base<T> DSC)
    {
      DSC.write(os);
      return os;
    }
};

// Clase derivada Array.
template <class T, int N = 10>
class dsc_array: dsc_base<T>
{
  private:
    vector<T*> coleccion(N);
    int n;

  public:
    dsc_array():n(0)
    {}

    virtual bool empty(void) const
    {
      if( n == 0)
        return true;
    }
    virtual void insert(const T& elemento)
    {
      if (n < N)
      {
        T* nuevo = new T(elemento);
        coleccion[n] = nuevo;
        n++;
      }
      else
         throw(dsc_exception_full);
    }
    virtual T retrieve(void)
    {
      if (empty())
        throw ("dsc_exception_empty");
      T elem = *coleccion[n - 1];
      delete coleccion[n - 1];
      n--;
      return elem;
    }
    ostream& write(ostream& os)const
    {
      for (int i = 0; i < size; i++)
      os << array[i] << '\n';
      return os;
    }
};

// func move.
template <class T>
void dsc_move<T>(dsc_base*<T> first, dsc_base*<T> second)
{
  try
  {
    while (!first.empty())
    {
      T elem = first.retrieve();
      second.insert(elem);
    }
  }
  catch(string& e) {
    cout << "Excepción: " << e << '\n';
  }
}
