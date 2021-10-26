#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const long MAX_VALOR = 100000000;

class DNI
{
  private:
    long valor;

  public:
    DNI();
    bool operator== (DNI& dni2);
    bool operator> (DNI& dni2);
    bool operator< (DNI& dni2);
    operator unsigned long() const;
    long getValor();
    void setValor(long newValor);
    long operator<<(DNI& dni);
};
