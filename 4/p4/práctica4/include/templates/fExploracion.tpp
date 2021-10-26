#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fDispersion.tpp"

template <class T>
class fExploracion
{
  protected:
    int nCeldas;

  public:
    fExploracion(int nCel): nCeldas(nCel)
    {}
    virtual int operator()(const T& clave, int i)=0;

};

template <class T>
class fExpLineal : public fExploracion<T>
{
  public:
    fExpLineal(int nCel): fExploracion<T>(nCel)
    {}
    int operator()(const T& clave, int i)
    {
      return i;
    }
};

template <class T>
class fExpCuadratica : public fExploracion<T>
{
  public:
    fExpCuadratica(int nCel): fExploracion<T>(nCel)
    {}
    int operator()(const T& clave, int i)
    {
      return i*i;
    }
};

template <class T>
class fExpDispDoble : public fExploracion<T>
{
  private:
    fDispersion<T>* fDisp;

  public:
    fExpDispDoble(int nCel, int opcion): fExploracion<T>(nCel)
    {
      switch (opcion)
      {
        case 0:
          fDisp = new fDispSuma<T>(fExploracion<T>::nCeldas);
          break;
        case 1:
          fDisp = new fDispModulo<T>(fExploracion<T>::nCeldas);
          break;
        case 2:
          fDisp = new fDispPseudoaleatoria<T>(fExploracion<T>::nCeldas);
          break;
        default:
          fDisp = new fDispSuma<T>(fExploracion<T>::nCeldas);
      }
    }
    int operator()(const T& clave, int i)
    {
      return (*fDisp)(clave) == 0 ? i * 1 : i * (*fDisp)(clave);
    }
};

template <class T>
class fExpReDispersion : public fExploracion<T>
{
  public:
    fExpReDispersion(int nCel): fExploracion<T>(nCel)
    {}
    int operator()(const T& clave, int i)
    {
      int desp;
      long semilla;
      long(clave) % 2 == 0 ? semilla = long(clave) + 1 : semilla = long(clave);
      srand(semilla);
      for(int j = 0; j < i; j++)
        desp = rand();
      // srand(time(NULL));
      return desp % fExploracion<T>::nCeldas;
    }
};
