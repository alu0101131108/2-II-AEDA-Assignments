#include <vector>
#include <iostream>
#include <iomanip>
#include "../include/DNI.hpp"
#include "../include/templates/SortFunctions.tpp"

typedef std::vector<std::vector<DNI>> DNI_testbench;
enum algorithms {INSERTIONSORT, BUBBLESORT, HEAPSORT, QUICKSORT, SHELLSORT};

void runVisualMode()
{
  ///Parameter setup///
  int size, algorithm;
  std::cout << "\nVisual mode." << '\n';
  std::cout << "Enter sequence size: ";
  std::cin >> size;
  std::cout << "Enter algorithm [0-InsertionSort, 1-BubbleSort, 2-HeapSort, 3-QuickSort, 4-ShellSort]: ";
  std::cin >> algorithm;
  std::cout << "Comparisons follow the next notation: ¿{{DNI}} < ((DNI))? \nEnter any char to continue with iterations.\n";

  std::vector<DNI> dni_test;
  for (int i = 0; i < size; i++)
    dni_test.push_back(DNI());

  switch (algorithm)
  {
    case INSERTIONSORT:
      demInsertionSort(dni_test, size);
      break;

    case BUBBLESORT:
      demBubbleSort(dni_test, size);
      break;

    case HEAPSORT:
      demHeapSort(dni_test, size);
      break;

    case QUICKSORT:
      demFullQuickSort(dni_test, size);
      break;

    case SHELLSORT:
      float shellSort_alpha;
      std::cout << "Enter alpha value for Shell Sorting Method: ";
      std::cin >> shellSort_alpha;
      demShellSort(dni_test, size, shellSort_alpha);
      break;

    default:
      std::cout << "Invalid algorithm." << '\n';
      runVisualMode();
  }

}

void runStatisticMode()
{
  ///Parameter setup///
  int size, iterations;
  float shellSort_alpha;
  std::cout << "\nStatistics mode." << '\n';
  std::cout << "Enter sequence size: ";
  std::cin >> size;
  std::cout << "Enter number of iterations: ";
  std::cin >> iterations;
  std::cout << "Enter alpha value for Shell Sorting Method: ";
  std::cin >> shellSort_alpha;

  ///Random test bench creation for each sorting method///
  DNI_testbench model;
  for (int i = 0; i < iterations; i++)
  {
    model.push_back(std::vector<DNI>());
    for (int j = 0; j < size; j++)
      model[i].push_back(DNI());
  }

  DNI_testbench insertSort_tb = model;
  DNI_testbench bubbleSort_tb = model;
  DNI_testbench heapSort_tb = model;
  DNI_testbench quickSort_tb = model;
  DNI_testbench shellSort_tb = model;

  ///Insertion Sort method testing///
  int count;
  int insert_min = 99999999, insert_max = 0;
  float insert_mean = 0;
  for (int i = 0; i < iterations; i++)
  {
    count = 0;
    insertionSort(insertSort_tb[i], size, count);
    if (count < insert_min)
      insert_min = count;
    if (count > insert_max)
      insert_max = count;
    insert_mean += count;
  }
  insert_mean /= iterations;

  ///Bubble Sort method testing///
  int bubble_min = 99999999, bubble_max = 0;
  float bubble_mean = 0;
  for (int i = 0; i < iterations; i++)
  {
    count = 0;
    bubbleSort(bubbleSort_tb[i], size, count);
    if (count < bubble_min)
      bubble_min = count;
    if (count > bubble_max)
      bubble_max = count;
    bubble_mean += count;
  }
  bubble_mean /= iterations;

  ///Heap Sort method testing///
  int heap_min = 99999999, heap_max = 0;
  float heap_mean = 0;
  for (int i = 0; i < iterations; i++)
  {
    count = 0;
    heapSort(heapSort_tb[i], size, count);
    if (count < heap_min)
      heap_min = count;
    if (count > heap_max)
      heap_max = count;
    heap_mean += count;
  }
  heap_mean /= iterations;

  ///Quick Sort method testing///
  int quick_min = 99999999, quick_max = 0;
  float quick_mean = 0;
  for (int i = 0; i < iterations; i++)
  {
    count = 0;
    fullQuickSort(quickSort_tb[i], size, count);
    if (count < quick_min)
      quick_min = count;
    if (count > quick_max)
      quick_max = count;
    quick_mean += count;
  }
  quick_mean /= iterations;

  ///Shell Sort method testing///
  int shell_min = 99999999, shell_max = 0;
  float shell_mean = 0;
  for (int i = 0; i < iterations; i++)
  {
    count = 0;
    shellSort(shellSort_tb[i], size, shellSort_alpha, count);
    if (count < shell_min)
      shell_min = count;
    if (count > shell_max)
      shell_max = count;
    shell_mean += count;
  }
  shell_mean /= iterations;

  ///Results Display///
  int wd = 20;
  std::cout << '\n' << "                    Number of comparisons:" << '\n';
  std::cout << "                      Minimum:        Mean:                   Maximum:" << '\n';
  std::cout << "Insertion Sort:     " << std::setw(5) << insert_min << std::setw(wd) << insert_mean << std::setw(wd) << insert_max << '\n';
  std::cout << "Bubble Sort:        " << std::setw(5) << bubble_min << std::setw(wd) << bubble_mean << std::setw(wd) << bubble_max << '\n';
  std::cout << "Heap Sort:          " << std::setw(5) << heap_min << std::setw(wd) << heap_mean << std::setw(wd) << heap_max << '\n';
  std::cout << "Quick Sort:         " << std::setw(5) << quick_min << std::setw(wd) << quick_mean << std::setw(wd) << quick_max << '\n';
  std::cout << "Shell Sort:         " << std::setw(5) << shell_min << std::setw(wd) << shell_mean << std::setw(wd) << shell_max << "\n\n";
}

int main()
{
  srand(time(NULL));
  int mode;
  std::cout << "Enter \"0\" for Visual Mode, or  \"1\" for Statistics mode.\n";
  std::cin >> mode;
  switch (mode)
  {
    case 0: runVisualMode();
    break;
    case 1: runStatisticMode();
    break;
    default:
      std::cout << "Invalid mode.\n";
      main();
  }
  return 0;
}




///TRIES A SORTING METHOD///
// std::vector<int> v = {9, 8, 7, 30, 12, 49 , 22, 100, 1, 0, -5};
// printVec(v);
// shellSort(v, v.size());
// printVec(v);
























// #include <iomanip>
// #include "../include/templates/Tabla.tpp"
// #include "../include/DNI.hpp"
//
// enum funcionDispersion {SUMA, MODULO, PSEUDOALEATORIA};
// enum funcionExploracion {LINEAL, CUADRATICA, DOBLEDISPERSION, REDISPEPRSION};
//
// int main()
// {
// /////// INICIALZACIÓN DE PARÁMETROS //////////
//   srand(time(NULL));
//   int nCel, nClav, fDisp, fExp, opfExp = 0, nPruebas;
//   float factor;
//   std::cout << "Introducir los parámetros:\n> Número de Celdas.\n> Número de Claves.\n> Función de Dispersion:\n0 - Suma\n1 - Módulo\n2 - PseudoAleatoria.\n> Función de Exploración:\n0 - Lineal\n1 - Cuadrática\n2 - Doble Dispersión\n3 - Redispersión.\n";
//   std::cin >> nCel;
//   std::cin >> nClav;
//   std::cin >> fDisp;
//   std::cin >> fExp;
//   if (fExp == 2)
//   {
//     std::cout << "Introducir la función de dispersión a utilizar en la técnica de exploración de Doble Dispersión.\n";
//     std::cin >> opfExp;
//   }
//   std::cout << "Introducir factor de carga: ";
//   std::cin >> factor;
//   std::cout << "Introducir el número de pruebas para el experimento: ";
//   std::cin >> nPruebas;
//
//   Tabla<DNI> t1(nCel, nClav, fDisp, fExp, opfExp);
//   std::vector<DNI> banco;
//   int n = factor * nCel * nClav;
//
// /////// CREACIÓN E INSERCIÓN DE CLAVES //////////
//   for (int i = 0; i < 2 * n; i++)
//     banco.push_back(DNI());
//
//   int nClavesInsertadas = factor * 2 * n;
//
//   for (int i = 0; i < nClavesInsertadas; i++)
//     if (!t1.insertar(banco[i]))
//       std::cout << "----------------ERROR AL INSERTAR----------------\n";
//
// /////// EXPERIMENTO DE BÚSQUEDA //////////
//   int contador = 0, b_minimo = 999999, b_maximo = 0, b_media = 0;
//   for (int i = 0; i < nPruebas; i++)
//   {
//     t1.buscar(banco[rand() % nClavesInsertadas], contador);
//     if (b_minimo > contador)
//       b_minimo = contador;
//     if (b_maximo < contador)
//       b_maximo = contador;
//     b_media += contador;
//     contador = 0;
//   }
//   b_media = b_media / nPruebas;
//
//
// /////// EXPERIMENTO DE INSERCIÓN //////////
//   int i_minimo = 999999, i_maximo = 0, i_media = 0;
//   for (int i = 0; i < nPruebas; i++)
//   {
//     t1.buscar(banco[nClavesInsertadas + rand() % (2 * n - nClavesInsertadas)], contador);
//     if (i_minimo > contador)
//       i_minimo = contador;
//     if (i_maximo < contador)
//       i_maximo = contador;
//     i_media += contador;
//     contador = 0;
//   }
//   i_media = i_media / nPruebas;
//
// /////// MUESTEO DE VALORES //////////
//   int wd = 30;
//   std::string str_fDisp;
//   switch (fDisp)
//   {
//     case 0:
//     str_fDisp = "Módulo";
//       break;
//     case 1:
//     str_fDisp = "Suma";
//       break;
//     case 2:
//     str_fDisp = "Pseudoaleatoria";
//       break;
//     default:
//     str_fDisp = "Módulo";
//   }
//   std::string str_fExp;
//   switch (fExp)
//   {
//     case 0:
//     str_fExp = "Lineal";
//       break;
//     case 1:
//     str_fExp = "Cuadrática";
//       break;
//     case 2:
//     str_fExp = "Doble Dispersión";
//       break;
//     case 3:
//     str_fExp = "Redispersión";
//       break;
//     default:
//     str_fExp = "Módulo";
//   }
//   std::cout << std::endl << "nCeldas" << std::setw(wd) << "nClaves" << std::setw(wd) << "Dispersión" << std::setw(wd) << "Exploración" << std::setw(wd) << "Carga" << std::setw(wd) << "Pruebas" << std::endl;
//   std::cout << nCel << std::setw(wd - 1) << nClav << std::setw(wd + 5) << str_fDisp << std::setw(wd) << str_fExp << std::setw(wd) << factor << std::setw(wd) << nPruebas << std::endl << std::endl;
//   std::cout << std::setw(1.3 * wd) << "Mínimo" << std::setw(wd) << "Medio" << std::setw(wd) << "Máximo" << std::endl;
//   std::cout << "Búsquedas:" << std::setw(wd) << b_minimo << std::setw(wd) << b_media << std::setw(wd) << b_maximo << std::endl;
//   std::cout << "Inserción:" << std::setw(wd) << i_minimo << std::setw(wd) << i_media << std::setw(wd) << i_maximo << std::endl << std::endl;
//
//
// //  t1.print(std::cout);
//   return 0;
// }
