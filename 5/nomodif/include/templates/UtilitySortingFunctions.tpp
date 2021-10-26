#ifndef _UTSF_
#define _UTSF_
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
void swap(std::vector<T> & keys, int posA, int posB)
{
  T aux = keys[posA];
  keys[posA] = keys[posB];
  keys[posB] = aux;
}

#endif
