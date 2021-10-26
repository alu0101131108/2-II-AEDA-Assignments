#ifndef _DNI_
#define _DNI_

#include <iostream>
#include <string>

#include "../include/Count.hpp"

const long MAX_VALOR = 100000000;

class DNI
{
  private:
    long valor;

  public:
    static Contador contador;
    DNI();
    ~DNI(){}
    operator unsigned long( ) const;
    bool operator<(const DNI& X);
    bool operator==(const DNI& X);
};

#endif
