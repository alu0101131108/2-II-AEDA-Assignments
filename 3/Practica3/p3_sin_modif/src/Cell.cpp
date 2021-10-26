#include "../include/Cell.hpp"

Cell* Cell::createCell(int i, int j, int type)
{
  Cell* cell_ptr;
  switch (type) {
    case 0:
      cell_ptr = new Cell(i, j);
    break;
    case 1:
      cell_ptr = new Cell_1(i, j);
    break;
    case 2:
      cell_ptr = new Cell_2(i, j);
    break;
    case 3:
      cell_ptr = new Cell_3(i, j);
    break;
  }
  return cell_ptr;
}
int Cell::getState() const
{
  return 0;
}
int Cell::countNearCells(Board & main_board)
{
  int near_cells = 0;
  for (int j = -1; j < 2; j++)
    for (int i = -1; i < 2; i++)
      if (main_board.at(x + i, y + j) -> getState() != 0)
        near_cells++;

  return getState() == 0 ? near_cells : near_cells - 1;
}
int Cell::updateState(int near_cells)
{
  switch (near_cells)
  {
    case 3:
      return 1;
      break;
    case 6:
      return 2;
      break;
    case 8:
      return 2;
      break;
    case 4:
      return 3;
      break;
    default:
      return 0;
  }
}
void Cell::print(std::ostream & os) const
{
  os << " ";
}


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
void Cell_1::print(std::ostream & os) const
{
  os << "1";
}


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
void Cell_2::print(std::ostream & os) const
{
  os << "2";
}


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
void Cell_3::print(std::ostream & os) const
{
  os << "3";
}
