#include <vector>
#include <iostream>
#include "UtilitySortingFunctions.tpp"

template <class T>
void demInsert(std::vector<T> & keys, int oldPos)
{
  T aux = keys[oldPos];
  int newPos = 0;
  while(compSearchPrint(keys, newPos, aux, true) && keys[newPos] < aux && newPos < oldPos)
  {
    newPos++;
  }
  for (int i = 0; i < (oldPos - newPos); i++)
  {
    keys[oldPos - i] = keys[oldPos - i - 1];
  }
  keys[newPos] = aux;
}

template <class T>
void demInsertionSort(std::vector<T> & keys, int size)
{
  if (size >= 2)
  {
    T aux = keys[0];
    for (int i = 1; i < size; i++)
    {
      if (compPrint(keys, i, i - 1) && keys[i - 1] > keys[i])
        demInsert(keys, i);
    }
  }
  printVec(keys);
}

template <class T>
void demBubbleSort(std::vector<T> & keys, int size)
{
  bool sorted;
  for (int i = 1; i < size; i++)
  {
    sorted = true;
    for (int j = size - 1; j >= i; j--)
    {
      if (compPrint(keys, j, j - 1) && keys[j] < keys[j - 1])
      {
        swap(keys, j - 1, j);
        sorted = false;
      }
    }
    if (sorted)
      break;
  }
  printVec(keys);
}

template <class T>
void demHeapify(std::vector<T> & keys, int size, int root)
{
  int largest = root;
  int leftChild = 2 * root + 1;
  int rightChild = 2 * root + 2;

  if (compPrint(keys, largest, leftChild) && leftChild < size && keys[leftChild] > keys[largest])
    largest = leftChild;
  if (compPrint(keys, largest, rightChild) && rightChild < size && keys[rightChild] > keys[largest])
    largest = rightChild;

  if (largest != root)
  {
    swap(keys, root, largest);
    demHeapify(keys, size, largest);
  }
}

template <class T>
void demHeapSort(std::vector<T> & keys, int size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
    demHeapify(keys, size, i);

  for (int i = size - 1; i > 0; i--)
  {
    swap(keys, 0, i);
    demHeapify(keys, i, 0);
  }
}

template <class T>
int demPartition(std::vector<T> & keys, int low, int high)
{
  T pivot = keys[high];
  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    if (compSearchPrint(keys, j, pivot, true) && keys[j] <= pivot)
    {
      i++;
      swap(keys, i, j);
    }
  }

  swap(keys, i + 1, high);
  return (i + 1);
}

template <class T>
void demQuickSort(std::vector<T> & keys, int low, int high)
{
  if (low < high)
  {
    int pi = demPartition(keys, low, high);
    demQuickSort(keys, low, pi - 1);
    demQuickSort(keys, pi + 1, high);
  }
}

template <class T>
void demFullQuickSort(std::vector<T> & keys, int size)
{
  demQuickSort(keys, 0, size - 1);
  printVec(keys);
}

template <class T>
void demShellSort(std::vector<T> & keys, int size, float alpha)
{
  for (int limit = size * alpha; limit > 0; limit *= alpha)
    for(int i = limit; i < size; i++)
    {
      T aux = keys[i];
      int j;
      for (j = i; compSearchPrint(keys, j - limit, aux, false) && (j >= limit) && (keys[j - limit] > aux); j -= limit)
      {
        keys[j] = keys[j - limit];
      }
      keys[j] = aux;
    }
  printVec(keys);
}
