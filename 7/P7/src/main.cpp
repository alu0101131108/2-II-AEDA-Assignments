#include <iostream>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/BBTree.tpp"
#include "../include/AVLTree.tpp"
#include "../include/DNI.hpp"

void demo()
{
  AVLTree<int> tree;
  int option;
  int data;

  while(true)
  {
    std::cout << "Traza de AVL - Sebastián Daniel Tamayo Guzmán" << '\n';
    std::cout << "[1] Insertar" << '\n';
    std::cout << "[2] Eliminar" << '\n';
    std::cin >> option;
    switch (option)
    {
      case 1:
        std::cin >> data;
        tree.Insertar(data);
        tree.imprimirArbol();
        break;

      case 2:
        std::cin >> data;
        tree.Eliminar(data);
        tree.imprimirArbol();
        break;

      default:
        system("clear");
        std::cout << "Opción no soportada" << '\n';
    }
  }
}

void estad()
{
  int size, ntests;
  std::cout << "Introduzca el tamaño para el arbol: ";
  std::cin >> size;
  std::cout << "Introduzca el número de pruebas: ";
  std::cin >> ntests;

  std::vector<DNI> test_bench;
  for (int i = 0; i < 2 * size; i++)
    test_bench.push_back(DNI());

  AVLTree<DNI> tree;
  for (int i = 0; i < size; i++)
    tree.Insertar(test_bench[i]);


  int b_min = 999999999;
  int b_max = -1;
  int b_sum = 0;
  for (int i = 0; i < ntests; i++)
  {
    DNI::contador.Reset();
    tree.Buscar(test_bench[rand() % size]);
    b_sum += DNI::contador.Get();
    if(DNI::contador.Get() < b_min)
      b_min = DNI::contador.Get();
    if(DNI::contador.Get() > b_max)
      b_max = DNI::contador.Get();
  }


  int i_min = 999999999;
  int i_max = -1;
  int i_sum = 0;
  for (int i = 0; i < ntests; i++)
  {
    DNI::contador.Reset();
    tree.Buscar(test_bench[(rand() % size) + size]);
    i_sum += DNI::contador.Get();
    if(DNI::contador.Get() < i_min)
      i_min = DNI::contador.Get();
    if(DNI::contador.Get() > i_max)
      i_max = DNI::contador.Get();
  }


  std::cout << "Tamaño del arbol: " << size << "      Número de pruebas: " << ntests <<  "\n\n";
  std::cout << "\t\tMínimo\t\tMedia\t\tMáximo" << '\n';
  std::cout << "Búsqueda:\t" << b_min << "\t\t" << (b_sum / ntests) << "\t\t" << b_max << '\n';
  std::cout << "Inserción:\t" << i_min << "\t\t" << (i_sum / ntests) << "\t\t" << i_max << '\n';
}

int main()
{
  srand(time(NULL));

  int option;
  std::cout << "[1] Modo Demostración" << '\n';
  std::cout << "[2] Modo Estadístico" << '\n';
  std::cin >> option;

  switch (option)
  {
    case 1:
      system("clear");
      demo();
      break;

    case 2:
      system("clear");
      estad();
      break;

    default:
      system("clear");
      main();
  }

  return 0;
}
