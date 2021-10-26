#ifndef COUNT_
#define COUNT_

#include <iostream>

class Count
{
  private:
    int count;
    int sum;
    int nsum;
    int min;
    int max;

  public:
    Count(): count(0), sum(0), nsum(0), min(99999999), max(-1)
    {}
    void resetCount();
    void resetAll();
    void inc();
    int getCount();
    int getMean();
    int getMin();
    int getMax();
};
#endif
