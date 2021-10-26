#include "Cell.hpp"

class Board
{
  private:
  int time, height, width;
  std::vector<Cell*> cell_matrix;
  int poblation;                            // No tiene en cuenta los bordes.

  public:
    Board(int n, int m): time(0), width(n), height(m)
    {
      for(int j = 0; j < height + 2; j++)
        for(int i = 0; i < width + 2; i++)
          cell_matrix.push_back(new Cell(i, j));
    }

    Cell* at(int i, int j);
    int getTime();
    int getPoblation();
    void initializeCells(int cell_num, std::istream & is);
    void updateBoard();
    void print(std::ostream & os);

};
