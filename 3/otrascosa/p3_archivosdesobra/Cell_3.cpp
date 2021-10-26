#include "../include/Cell_3.hpp"

Cell_3::Cell_3(int i, int j):Cell(i, j)
{}
int Cell_3::getState() const
{
  return 3;
}
int Cell_3::updateState(int near_cells)
{
  if (near_cells != 5 && near_cells != 1)
    return 0;
  else
    return 3;
}
void Cell_3::print(std::ostream os) const
{
  os << "3";
}
