#ifndef CELL_1_
#define CELL_1_

#include "Cell.hpp"

class Cell_1 : public Cell
{
public:
  Cell_1(int i, int j);
  int getState() const;
  int updateState(int near_cells);
  void print(std::ostream) const;
};

#endif
