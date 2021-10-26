#ifndef CELL_
#define CELL_
#include "Board.hpp"
#include <vector>
#include <iostream>

class Board;
class Cell
{
  protected:
  int x, y;

  public:
    Cell(int i, int j): x(i), y(j)
    {}

    static Cell* createCell(int i, int j,int type);
    virtual int getState() const;
    virtual int countNearCells(Board & main_board);
    virtual int updateState(int near_cells);
    virtual void print(std::ostream & os) const;

};

class Cell_1 : public Cell
{
public:
  Cell_1(int i, int j);
  int getState() const;
  int updateState(int near_cells);
  void print(std::ostream & os) const;
};

class Cell_2 : public Cell
{
public:
  Cell_2(int i, int j);
  int getState() const;
  int updateState(int near_cells);
  void print(std::ostream & os) const;
};

class Cell_3 : public Cell
{
public:
  Cell_3(int i, int j);
  int getState() const;
  int updateState(int near_cells);
  void print(std::ostream & os) const;
};

#endif
