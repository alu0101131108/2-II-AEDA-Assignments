#include <vector>
#include <iostream>
#include "UtilitySortingFunctions.tpp"

template <class T>
void insert(std::vector<T> & keys, int oldPos, int & count)
{
  T aux = keys[oldPos];
  int newPos = 0;
  while(keys[newPos] < aux && newPos < oldPos)
  {
    newPos++;
    count++;
  }
  count++;
  for (int i = 0; i < (oldPos - newPos); i++)
    keys[oldPos - i] = keys[oldPos - i - 1];
  keys[newPos] = aux;
}

template <class T>
void insertionSort(std::vector<T> & keys, int size, int & count)
{
  if (size >= 2)
  {
    T aux = keys[0];
    for (int i = 1; i < size; i++)
    {
      count++;
      if (keys[i - 1] > keys[i])
        insert(keys, i, count);
    }
  }
}

template <class T>
void bubbleSort(std::vector<T> & keys, int size, int & count)
{
  bool sorted;
  for (int i = 1; i < size; i++)
  {
    sorted = true;
    for (int j = size - 1; j >= i; j--)
    {
      count++;
      if (keys[j] < keys[j - 1])
      {
        swap(keys, j - 1, j);
        sorted = false;
      }
    }
    if (sorted)
      break;
  }
}

template <class T>
void heapify(std::vector<T> & keys, int size, int root, int & count)
{
  int largest = root;
  int leftChild = 2 * root + 1;
  int rightChild = 2 * root + 2;

  count++;
  if (leftChild < size && keys[leftChild] > keys[largest])
    largest = leftChild;
  count++;
  if (rightChild < size && keys[rightChild] > keys[largest])
    largest = rightChild;

  if (largest != root)
  {
    swap(keys, root, largest);
    heapify(keys, size, largest, count);
  }
}

template <class T>
void heapSort(std::vector<T> & keys, int size, int & count)
{
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(keys, size, i, count);

  for (int i = size - 1; i > 0; i--)
  {
    swap(keys, 0, i);
    heapify(keys, i, 0, count);
  }
}

template <class T>
int partition(std::vector<T> & keys, int low, int high, int & count)
{
  T pivot = keys[high];
  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    count++;
    if (keys[j] <= pivot)
    {
      i++;
      swap(keys, i, j);
    }
  }

  swap(keys, i + 1, high);
  return (i + 1);
}

template <class T>
void quickSort(std::vector<T> & keys, int low, int high, int & count)
{
  if (low < high)
  {
    int pi = partition(keys, low, high, count);
    quickSort(keys, low, pi - 1, count);
    quickSort(keys, pi + 1, high, count);
  }
}

template <class T>
void fullQuickSort(std::vector<T> & keys, int size, int & count)
{
  quickSort(keys, 0, size - 1, count);
}

template <class T>
void shellSort(std::vector<T> & keys, int size, float alpha, int & count)
{
  for (int limit = size * alpha; limit > 0; limit *= alpha)
    for(int i = limit; i < size; i++)
    {
      T aux = keys[i];
      int j;
      for (j = i; j >= limit && keys[j - limit] > aux; j -= limit)
      {
        count++;
        keys[j] = keys[j - limit];
      }
      count++;
      keys[j] = aux;
    }
}
