#ifndef DNI_
#define DNI_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Count.hpp"

const long MAX_VALOR = 100000000;

class DNI
{
  private:
    long valor;

  public:
    static Count count;

    DNI();
    bool operator== (DNI& dni2);
    bool operator> (DNI& dni2);
    bool operator< (DNI& dni2);
    operator unsigned long() const;
    long getValor();
    void setValor(long newValor);
    int getMin();
    int getMax();
    int getMean();
    void resetCount();
    void resetAll();
};

#endif
