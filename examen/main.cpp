#include <iostream>
#include <vector>

void swap(std::vector<int> & sec, int i, int j)
{
  int temp = sec[i];
  sec[i] = sec[j];
  sec[j] = temp;
}

// Dividir en dos partes con una iteración de QSort y ordenar la primera por selección y la seguda por inserción.
void mixSort(std::vector<int> & sec)
{
  int n = sec.size(), ini = 0, fin = n - 1;
  int pivote = sec[n/2];
  while (ini <= fin)
  {
    while (sec[ini] < pivote) ini++ ;
    while (sec[fin] > pivote) fin-- ;
    if (ini <= fin)
    {
      swap(sec, ini, fin);
      ini++ ;
      fin-- ;
    }
  }

// sec separado en dos, de 0 a fin y de ini a (n - 1).
// SELECTION SORT:
  for (int i = 0; i < fin; i++)
  {
   int min = i;
   for(int j = i + 1; j <= fin; j++)
     if(sec[j] < sec[min])
       min = j;
   swap(sec, min, i);
  }

 // INSERTION SORT:
  for (int i = ini + 1; i < n; i++)
  {
    int j = i-1;
    int x = sec[i];
    while ((x < sec[j]) && (j > 0))
    {
      sec[j+1] = sec[j] ;
      j--;
    }
    sec[j+1] = x;
  }
}

int main()
{
  std::vector<int> unsorted = {90, 3, 4, 7, 2, 9, 5, 2, 9, 0, 1, 4, 7, 2, 9, 5, 2, 9, 0, 20, 2323, 6234, 1564, 2123, -1566, -12555, 98, 97, 96, 99, 1000, 10};

  for(int i = 0; i < unsorted.size(); i++)
    std::cout << unsorted[i] << "  ";
  std::cout << '\n' << '\n' << '\n';

  mixSort(unsorted);

  for(int i = 0; i < unsorted.size(); i++)
    std::cout << unsorted[i] << "  ";
  std::cout << '\n';

}
