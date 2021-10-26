#include "../include/DNI.hpp"

Contador DNI::contador;

DNI::DNI()
{
  valor = rand() % MAX_VALOR;
}

DNI::operator unsigned long() const
{
    return valor;
}

bool DNI::operator==(const DNI& X)
{
  contador.Inc();
  return long(*this) == long(X);
}

bool DNI::operator<(const DNI& X)
{
  contador.Inc();
  return long(*this) < long(X);
}
