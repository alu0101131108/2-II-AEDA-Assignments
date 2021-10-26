#include <vector>
#include <iostream>

template <class T>
bool compPrint(std::vector<T> & keys, int i1, int i2)
{
  for (int i = 0; i < keys.size(); i++)
  {
    if (i == i1)
      std::cout << "{{" << keys[i] << "}} ";
    else if (i == i2)
      std::cout << "((" << keys[i] << ")) ";
    else
      std::cout << "[" << keys[i] << "] ";
  }
  char entry;
  std::cin >> entry;
  std::cout << '\n';
  return true;
}

template <class T>
bool compSearchPrint(std::vector<T> & keys, int i1, T item, bool order)
{
  int index = 0;
  for(int i = 0; i < keys.size(); i++)
    if (keys[i] == item)
      index = i;
  if (order)
    return compPrint(keys, i1, index);
  else
    return compPrint(keys, index, i1);
}

template <class T>
void printVec(std::vector<T> keys)
{
  std::cout << "Sorted vector:" << '\n';
  for(int i = 0; i < keys.size(); i++)
  std::cout << "[" << keys[i] << "] ";
  std::cout << "\n";
}

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
void swap(std::vector<T> & keys, int posA, int posB)
{
  T aux = keys[posA];
  keys[posA] = keys[posB];
  keys[posB] = aux;
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
