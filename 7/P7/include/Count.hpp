#ifndef _COUNT_
#define _COUNT_

class Contador
{
  private:
    int contador;

  public:
    Contador(){}
    ~Contador(){}
    void Reset();
    void Inc(int incremento = 1);
    int Get();
};

#endif
