#include "../include/Count.hpp"

void Contador::Reset()
{
  contador = 0;
}

void Contador::Inc(int incremento )
{
  contador = contador + incremento;
}

int Contador::Get()
{
  return contador;
}
