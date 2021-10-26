#include "../include/Cell_2.hpp"

Cell_2::Cell_2(int i, int j):Cell(i, j)
{}
int Cell_2::getState() const
{
  return 2;
}
int Cell_2::updateState(int near_cells)
{
  if (near_cells != 2 && near_cells != 4 && near_cells != 5)
    return 0;
  else
    return 2;
}
void Cell_2::print(std::ostream os) const
{
  os << "2";
}
