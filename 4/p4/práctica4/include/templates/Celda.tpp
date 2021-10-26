#include <iostream>
#include <vector>

template <class T>
class Celda
{
  private:
    int nClaves;
    int enUso;
    std::vector<T> vClaves;


  public:
    Celda(int nClav): enUso(0), nClaves(nClav)
    {
      vClaves.resize(nClav);
    }
    bool buscar(const T clave, int & contador)
    {
      bool return_value = false;
      for (int i = 0; i < vClaves.size(); i++)
      {
       contador++;
        if (vClaves[i] == clave)
          return_value = true;
      }
      return return_value;
    }
    bool insertar(const T clave)
    {
      if(estaLlena())
        return false;
      else
      {
        vClaves[enUso] = clave;
       enUso++;
        return true;
      }
    }
    bool estaLlena()
    {
      return nClaves == enUso;
    }
    void print(std::ostream & os)
    {
      for(int i = 0; i < enUso; i++)
        os << "[" << long(vClaves[i]) << "] ";
      os << std::endl;
    }
};
