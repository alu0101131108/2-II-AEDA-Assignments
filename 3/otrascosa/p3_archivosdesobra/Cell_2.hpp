#ifndef CELL_2_
#define CELL_2_

#include "Cell.hpp"

class Cell_2 : public Cell
{
public:
  Cell_2(int i, int j);
  int getState() const;
  int updateState(int near_cells);
  void print(std::ostream) const;
};

#endif
