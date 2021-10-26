#include "../include/Board.hpp"

Board::Board(int n, int m): turn(0), width(n + 2), height(m + 2)
{
  for (int j = 0; j < height; j++)
    for (int i = 0; i < width; i++)
      cell_matrix.push_back(new Cell(i, j));
}
Cell* Board::at(int i, int j)
{
  return cell_matrix[j * width + i];
}
int Board::getTurn()
{
  return turn;
}
void Board::initializeCells(int cell_num, std::istream & is)
{
  int aux_i, aux_j;
  for (int i = 0; i < cell_num; i++)
  {
    std::cout << "Coordenadas x, y:" << std::endl;
    is >> aux_i;
    is >> aux_j;
    at(aux_i, aux_j) -> setState(1);
  }
}
void Board::updateBoard()
{
  // Se recorre por primera vez para analizar las células vecinas.
  std::vector<int> near_cells_value(cell_matrix.size(), 0);
  for (int j = 1; j < height - 1; j++)
    for (int i = 1; i < width - 1; i++)
    {
      near_cells_value[j * width + i] = at(i, j) -> countNearCells(*this);
      at(i, j) -> addLifeTimeUnit();
    }
  // Se recorre por segunda vez para actualizar el estado.
  for (int j = 1; j < height - 1; j++)
    for (int i = 1; i < width - 1; i++)
      cell_matrix[j * width + i] -> updateState(near_cells_value[j * width + i]);

  // Se añade un turno.
  turn++;

}
void Board::print(std::ostream & os)
{
  os << "Turn: " << turn << std::endl;
  for (int j = 1; j < height - 1; j++)
  {
    os << "| ";
    for (int i = 1; i < width - 1; i++)
    {
      at(i,j) -> Cell::print(os);
      os << " | ";
    }
    os << std::endl;
  }
  os << std::endl;
}

Cell* Board::maxLifetimeCell()
{
  Cell* max = at(1, 1);
  for (int j = 1; j < height - 1; j++)
    for (int i = 1; i < width - 1; i++)
      if (at(i, j) -> getLifeTime() > max -> getLifeTime())
        max = at(i, j);
  return max;
}
