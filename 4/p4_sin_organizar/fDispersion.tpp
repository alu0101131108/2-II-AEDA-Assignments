template <class T>
class fDispersion
{
  protected:
    int nCeldas;

  public:
    fDispersion(int nCel): nCeldas(nCel)
    {}
    virtual int operator()(const T& clave)=0;
};

template <class T>
class fDispModulo : public fDispersion<T>
{
  public:
    fDispModulo(int nCel): fDispersion<T>(nCel)
    {}
    int operator()(const T& clave)
    {
      return long(clave) % fDispersion<T>::nCeldas;   // Devolverá número entre 0 y nCeldas - 1.
    }

};

template <class T>
class fDispSuma : public fDispersion<T>
{
  public:
    fDispSuma(int nCel): fDispersion<T>(nCel)
    {}
    int operator()(const T& clave)
    {
      int sum = 0;
      long valor = long(clave);
      int elem = 0;
      while (valor > 0)
      {
        elem = valor % 10;
        sum += elem;
        valor = valor / 10;
      }
      return sum % fDispersion<T>::nCeldas;
    }

};

template <class T>
class fDispPseudoaleatoria : public fDispersion<T>
{
  public:
    fDispPseudoaleatoria(int nCel): fDispersion<T>(nCel)
    {}
    int operator()(const T& clave)
    {
      long semilla;
      long(clave) % 2 == 0 ? semilla = long(clave) + 1 : semilla = long(clave);
      srand(semilla);
      int random = rand();
      // srand(time(NULL));
      return random % fDispersion<T>::nCeldas;
    }

};
