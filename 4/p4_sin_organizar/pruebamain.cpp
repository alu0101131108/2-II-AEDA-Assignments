#include <iostream>
#include "Tabla.tpp"
#include "DNI.cpp"

int main()
{
  srand(time(NULL));

  int nCeldas = 997;
  fExploracion<DNI>* papa = new fExpDispDoble<DNI>(nCeldas, 1);
  DNI dni1;
  std::cout << long(dni1) << std::endl;
  std::cout << (*papa)(dni1, 1) << std::endl;
  std::cout << (*papa)(dni1, 2) << std::endl;
  std::cout << (*papa)(dni1, 3) << std::endl;
  std::cout << (*papa)(dni1, 4) << std::endl;

  DNI dni2;
  std::cout << long(dni2) << std::endl;
  std::cout << (*papa)(dni2, 1) << std::endl;
  std::cout << (*papa)(dni2, 2) << std::endl;
  std::cout << (*papa)(dni2, 3) << std::endl;
  std::cout << (*papa)(dni2, 4) << std::endl;

  DNI dni3;
  std::cout << long(dni3) << std::endl;
  std::cout << (*papa)(dni3, 1) << std::endl;
  std::cout << (*papa)(dni3, 2) << std::endl;
  std::cout << (*papa)(dni3, 3) << std::endl;
  std::cout << (*papa)(dni3, 4) << std::endl;

  DNI dni4;
  std::cout << long(dni4) << std::endl;
  std::cout << (*papa)(dni4, 1) << std::endl;
  std::cout << (*papa)(dni4, 2) << std::endl;
  std::cout << (*papa)(dni4, 3) << std::endl;
  std::cout << (*papa)(dni4, 4) << std::endl;

  return 0;

  // srand(time(NULL));
  // std::vector<DNI> v;
  // for (int i = 0; i < 100; i++)
  // {
  //   DNI caca;
  //   v.push_back(caca);
  //   std::cout << caca.getValor() << std::endl;
  // }
  // v[50].setValor(10);
  // v[51].setValor(5);
  // v[52].setValor(5);
  // v[53].setValor(10);
  // v[54].setValor(0);
  // v[55].setValor(420);
  //
  // std::cout << (v[50] > v[51]) << std::endl;
  // std::cout << (v[52] < v[53]) << std::endl;
  // std::cout << (v[54] == v[55]) << std::endl;
  //
  // std::cout << long(v[55]) << std::endl;

}
