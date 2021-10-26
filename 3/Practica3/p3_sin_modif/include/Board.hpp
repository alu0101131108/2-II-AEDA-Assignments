#ifndef BOARD_
#define BOARD_
#include "Cell.hpp"
#include <vector>
#include <iostream>

class Cell;
class Board
{
  private:
  int turn, height, width;
  std::vector<Cell*> cell_vector;

  public:
    Board(int n, int m);
    Cell* at(int i, int j);
    int getTurn();
    void initializeCells(int cell_num, std::istream & is);
    void updateBoard();
    void print(std::ostream & os);
    void printStates();
    // Cell* maxLifetimeCell();
};

#endif
