#include "../include/DNI.hpp"

DNI::DNI()
{
  valor = rand() % MAX_VALOR;
}

bool DNI::operator==(DNI& dni2)
{
  return valor == dni2.getValor();
}

bool DNI::operator>(DNI& dni2)
{
  return valor > dni2.getValor();
}

bool DNI::operator<(DNI& dni2)
{
  return valor < dni2.getValor();
}

DNI::operator unsigned long() const
{
  return valor;
}

long DNI::getValor()
{
  return valor;
}

void DNI::setValor(long newValor)
{
  valor = newValor;
}

long DNI::operator<<(DNI& dni)
{
  return dni.getValor();
}
