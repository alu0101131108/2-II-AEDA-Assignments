#include "../include/Cell_1.hpp"

Cell_1::Cell_1(int i, int j):Cell(i, j)
{}

int Cell_1::getState() const
{
  return 1;
}
int Cell_1::updateState(int near_cells)
{
  if (near_cells != 2 && near_cells != 3)
    return 0;
  else
    return 1;
}
void Cell_1::print(std::ostream os) const
{
  os << "1";
}
