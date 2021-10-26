#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

const long MAX_VALOR = 10000;

class DNI
{
  private:
    long valorNum;
    char c1, c2, c3;
    long valorComparable;

  public:
    DNI();
    bool operator== (DNI& dni2);
    bool operator> (DNI& dni2);
    bool operator< (DNI& dni2);
    operator unsigned long() const;
    long getValor();
    void setValor(long newValor);
    //void print(std::ostream & os);
    //void addCount();
    //int getCount();
};
