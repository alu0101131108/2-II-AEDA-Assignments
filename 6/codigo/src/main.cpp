#include <vector>
#include <iostream>
#include <iomanip>

#include "../include/DNI.hpp"
#include "../include/Count.hpp"
#include "../include/templates/BNode.tpp"
#include "../include/templates/BTree.tpp"

// El modo estadístico no funciona. Las sobrecargas de operador de la clase DNI, no se llegan a llamar nunca y no se por qué. El modo visual si funciona.

void runVisualMode()
{
  BTree_S<int> tree;
  bool finishSignal = false;
  while(!finishSignal)
  {
    std::cout << "[0] - Salir" << '\n';
    std::cout << "[1] - Insertar clave" << '\n';
    std::cout << "[2] - Eliminar clave" << '\n';
    std::cout << "[3] - Comprobar si está perfectamente equilibrado" << '\n';

    int action, key;
    std::cin >> action;
    switch (action)
    {
      case 0:
        finishSignal = true;
        break;
      case 1:
        std::cin >> key;
        tree.insert(key);
        std::cout << "Clave insertada:" << '\n';
        tree.printTree();
        break;
      case 2:
        std::cin >> key;
        tree.deleteKey(key);
        std::cout << "Clave borrada:" << '\n';
        tree.printTree();
        break;
      case 3:
        if (tree.balanced(tree.getRoot()))
          std::cout << "El arbol está perfectamente equilibrado" << '\n';
        else
          std::cout << "El arbol no está perfectamente equilibrado" << '\n';
        break;
      default:
        std::cout << "Opción inválida - Intentelo de nuevo." << '\n';
    }
  }
}

void runStatisticMode()
{
  int size, ntests;
  std::cout << "Introduzca el tamaño para el arbol: ";
  std::cin >> size;
  std::cout << "Introduzca el número de pruebas para el experimento: ";
  std::cin >> ntests;

  std::vector<DNI> test_bench;
  for (int i = 0; i < 2 * size; i++)
    test_bench.push_back(DNI());

  BTree_S<DNI> tree;
  for (int i = 0; i < size; i++)
    tree.insert(test_bench[i]);
  DNI::count.resetCount();

  BNode<DNI>* temp;
  for (int i = 0; i < ntests; i++)
  {
    temp = tree.search(test_bench[rand() % size]);
  DNI::count.resetCount();
  }
  int b_min = test_bench[0].getMin();
  int b_max = test_bench[0].getMax();
  int b_mean = test_bench[0].getMean();
  DNI::count.resetAll();

  for (int i = 0; i < ntests; i++)
  {
    temp = tree.search(test_bench[size + (rand() % size)]);
    DNI::count.resetCount();
  }
  int i_min = test_bench[0].getMin();
  int i_max = test_bench[0].getMax();
  int i_mean = test_bench[0].getMean();
  DNI::count.resetAll();

///Results Display///
  int wd = 20;
  std::cout << '\n' << "                    Número de comparaciones" << '\n';
  std::cout << "                      Mínimo:        Media:                   Máximo:" << '\n';
  std::cout << "Búsqueda:     " << std::setw(5) << b_min << std::setw(wd) << b_mean << std::setw(wd) << b_max << '\n';
  std::cout << "Inserción:        " << std::setw(5) << i_min << std::setw(wd) << i_mean << std::setw(wd) << i_max << '\n';
  std::cout << "nPruebas: "<< ntests << '\n';
  std::cout << "Tamaño: "<< size << '\n';
}

int main()
{
  srand(time(NULL));
  int mode;
  std::cout << "Enter \"0\" for Visual Mode, or  \"1\" for Statistics mode.\n";
  std::cin >> mode;
  switch (mode)
  {
    case 0:
      runVisualMode();
      break;
    case 1:
      runStatisticMode();
      break;
    default:
      std::cout << "Invalid mode.\n";
      main();
  }
  return 0;
}
