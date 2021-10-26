#ifndef CELULA_
#define CELULA_
#include "Board.hpp"
#include <vector>
#include <iostream>

class Board;
class Cell
{
  private:
  int x, y, state;
  int lifetime;

  public:
    Cell(int i = 0, int j = 0, int init_state = 0): x(i), y(j), state(init_state), lifetime(0)
    {}
    int getState() const;
    void setState(int new_state);
    void updateState(int near_cells);
    int countNearCells(Board & main_board);
    void setPos(int i, int j = 0);
    int getX();
    int getY();
    int getLifeTime();
    void addLifeTimeUnit();
    void print(std::ostream & os);
};
#endif
