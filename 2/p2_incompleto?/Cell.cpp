#include "Board.hpp"
int Cell::getState() const
{
  return state;
}
void Cell::setState(int new_state)
{
  state = new_state;
}
void Cell::updateState(int near_cells)
{
  if (state == 0)
    near_cells == 3 ? state = 1 : state = 0;
  else
    (near_cells == 2 || near_cells == 3) ? state = 1 : state = 0;
}
int Cell::countNearCells(Board & main_board)
{
  int near_cells = 0;
  for(int j = -1; j < 2; j++)
    for(int i = -1; i < 2; i++)
      if (main_board.at(x + i, y + j) -> getState() == 1)
        near_cells++;
        
  return state == 0 ? near_cells : near_cells - 1;
}
void Cell::setPos(int i, int j)
{
  x = i;
  y = j;
}
int Cell::getX()
{
  return x;
}
int Cell::getY()
{
  return y;
}
void Cell::print(std::ostream & os)
{
  if(state == 0)
    os << " ";
  else
    os << "x";
}
