#include <vector>
#include <iostream>
#include <iomanip>
#include "../include/DNI.hpp"
#include "../include/templates/SortFunctions.tpp"
#include "../include/templates/VisualSortFunctions.tpp"

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
