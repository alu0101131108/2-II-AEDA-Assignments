#include "../include/NumSS.hpp"

SSN::SSN()
{
  num = rand() % MAX_VALOR;
  L1 = 'A' + rand() % 26;
  L2 = 'A' + rand() % 26;
  Y1 = 'A' + rand() % 26;
  Y2 = 'A' + rand() % 26;

  valor = std::stol(std::to_string(L1) + std::to_string(L2) + std::to_string(num) + std::to_string(Y1) + std::to_string(Y2));
}

bool SSN::operator==(SSN& ssn2)
{
  return valor == ssn2.getValor();
}

bool SSN::operator>(SSN& ssn2)
{
  return valor > ssn2.getValor();
}

bool SSN::operator<(SSN& ssn2)
{
  return valor < ssn2.getValor();
}

SSN::operator unsigned long() const
{
  return valor;
}

long SSN::getValor()
{
  return valor;
}

void SSN::setValor(long newValor)
{
  valor = newValor;
}

long SSN::operator<<(SSN& ssn)
{
  return valor;
}
