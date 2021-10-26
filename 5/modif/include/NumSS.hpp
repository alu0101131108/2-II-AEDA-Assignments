#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const long MAX_VALOR = 10000000000;

class SSN
{
  private:
    char L1, L2, Y1, Y2;
    long num;
    long valor;

  public:
    SSN();
    bool operator== (SSN& ssn2);
    bool operator> (SSN& ssn2);
    bool operator< (SSN& ssn2);
    operator unsigned long() const;
    long getValor();
    void setValor(long newValor);
    long operator<<(SSN& ssn);
};
