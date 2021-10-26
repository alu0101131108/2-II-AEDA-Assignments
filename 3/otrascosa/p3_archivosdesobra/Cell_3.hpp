#ifndef CELL_3_
#define CELL_3_

#include "Cell.hpp"

class Cell_3 : public Cell
{
public:
  Cell_3(int i, int j);
  int getState() const;
  int updateState(int near_cells);
  void print(std::ostream) const;
};

#endif
