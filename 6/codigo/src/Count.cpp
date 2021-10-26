#include "../include/Count.hpp"

void Count::resetCount()
{
  nsum++;
  sum += count;

  if (min > count)
    min = count;
  if (max < count)
    max = count;

  // std::cout << "count: " << count << '\n';
  // std::cout << "min: " << min << '\n';
  // std::cout << "max: " << max << '\n';
  // std::cout << "sum: " << sum << '\n';

  count = 0;
}

void Count::resetAll()
{
  count = 0;
  sum = 0;
  nsum = 0;
  min = 99999999;
  max = -1;
}

void Count::inc()
{
  count++;
  std::cout << "AAAAAA" << count << '\n';
}

int Count::getCount()
{
  return count;
}

int Count::getMean()
{
  return sum / nsum;
}

int Count::getMin()
{
  return min;
}

int Count::getMax()
{
  return max;
}
