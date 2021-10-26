#include "../include/DNI.hpp"

Count DNI::count;

DNI::DNI()
{
  valor = rand() % MAX_VALOR;
}

bool DNI::operator==(DNI& dni2)
{
  // std::cout << "opi" << '\n';
  count.inc();
  return valor == dni2.getValor();
}

bool DNI::operator>(DNI& dni2)
{
  // std::cout << "op" << '\n';
  count.inc();
  return valor > dni2.getValor();
}

bool DNI::operator<(DNI& dni2)
{
  // std::cout << "op" << '\n';
  count.inc();
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

int DNI::getMin()
{
  return count.getMin();
}

int DNI::getMax()
{
  return count.getMax();
}

int DNI::getMean()
{
  return count.getMean();
}

void DNI::resetCount()
{
  count.resetCount();
}

void DNI::resetAll()
{
  count.resetAll();
}
