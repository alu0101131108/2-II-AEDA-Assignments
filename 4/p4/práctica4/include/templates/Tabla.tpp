#include <iostream>
#include <vector>
#include "Celda.tpp"
#include "fExploracion.tpp"

template <class T>
class Tabla
{
  private:
    std::vector<Celda<T>> vCelda;
    int nCeldas;
    fDispersion<T>* funDisp;
    fExploracion<T>* funExp;


  public:
    Tabla(int nCel,int nClav, int op_fDisp, int op_fExp, int op_fExpDispDoble = 0): nCeldas(nCel)
    {
      switch (op_fDisp)
      {
        case 0:
          funDisp = new fDispSuma<T>(nCel);
          break;
        case 1:
          funDisp = new fDispModulo<T>(nCel);
          break;
        case 2:
          funDisp = new fDispPseudoaleatoria<T>(nCel);
          break;
        default:
          funDisp = new fDispSuma<T>(nCel);
      }
      switch (op_fExp)
      {
        case 0:
          funExp = new fExpLineal<T>(nCel);
          break;
        case 1:
          funExp = new fExpCuadratica<T>(nCel);
          break;
        case 2:
          funExp = new fExpDispDoble<T>(nCel, op_fExpDispDoble);
          break;
        case 3:
          funExp = new fExpReDispersion<T>(nCel);
          break;
        default:
          funExp = new fExpLineal<T>(nCel);
      }
      for(int i = 0; i < nCel; i++)
        vCelda.push_back(Celda<T>(nClav));
    }
    bool buscar(const T clave, int & contador)
    {
      int pos = (*funDisp)(clave);
      int i = 0;
      while(!vCelda[pos].buscar(clave, contador))
      {
          if (!vCelda[pos].estaLlena())
            return false;
          else
            pos = ((*funDisp)(clave) + (*funExp)(clave, ++i)) % nCeldas;
      }
      return true;
    }
    bool insertar(const T clave)
    {
      int pos = (*funDisp)(clave);
      int i = 0;
      while(vCelda[pos].estaLlena())
        pos = ((*funDisp)(clave) + (*funExp)(clave, ++i)) % nCeldas;

      return vCelda[pos].insertar(clave);
    }
    void print(std::ostream & os )
    {
      for (int i = 0; i < nCeldas; i++)
      {
        os << i << ":   ";
        vCelda[i].print(os);
      }
    }
};
