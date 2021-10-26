#include "../include/DNI.hpp"

DNI::DNI()
{
  valorNum = rand() % MAX_VALOR;
  c1 = (char)('A' + rand()%26);
  c2 = (char)('A' + rand()%26);
  c3 = (char)('A' + rand()%26);
  valorComparable = std::stol(std::to_string(valorNum) + std::to_string(c1) + std::to_string(c2) + std::to_string(c3));

}

bool DNI::operator==(DNI& dni2)
{
  return valorComparable == dni2.getValor();
}

bool DNI::operator>(DNI& dni2)
{
  return valorComparable > dni2.getValor();
}

bool DNI::operator<(DNI& dni2)
{
  return valorComparable < dni2.getValor();
}

DNI::operator unsigned long() const
{
  return valorComparable;
}

long DNI::getValor()
{
  return valorComparable;
}

void DNI::setValor(long newValor)
{
  valorComparable = newValor;
}

// void DNI::print(std::ostream & os)
// {
//   os << valorComparable;
// }
// void DNI::addCount()
// {
//   count++;
// }
//
// int DNI::getCount()
// {
//   return count;
// }
