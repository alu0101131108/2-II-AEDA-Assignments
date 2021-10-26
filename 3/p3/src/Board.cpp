#include "../include/Board.hpp"

Board::Board(int n, int m): turn(0), width(n + 2), height(m + 2)
{
  for (int j = 0; j < height; j++)
    for (int i = 0; i < width; i++)
      cell_vector.push_back(new Cell(i, j));
}
Cell* Board::at(int i, int j)
{
  return cell_vector[j * width + i];
}
int Board::getTurn()
{
  return turn;
}
void Board::initializeCells(int cell_num, std::istream & is)
{
  int coor_i, coor_j, type;
  for (int i = 0; i < cell_num; i++)
  {
    std::cout << "Coordenada X: ";
    is >> coor_i;
    std::cout << "Coordenada Y: ";
    is >> coor_j;
    std::cout << "Tipo de célula: ";
    is >> type;

    Cell* cell_ptr = at(coor_i, coor_j) -> createCell(coor_i, coor_j, type);
    delete at(coor_i, coor_j);
    // at(coor_i, coor_j) = cell_ptr;
    cell_vector[coor_i + coor_j * width] = cell_ptr;
  }
}
void Board::updateBoard()
{
  // Se recorre por primera vez para analizar las células vecinas.
  std::vector<int> near_cells_value(cell_vector.size(), 0);
  for (int j = 1; j < height - 1; j++)
    for (int i = 1; i < width - 1; i++)
      near_cells_value[j * width + i] = at(i, j) -> countNearCells(*this);

  // Se recorre por segunda vez para actualizar el estado.
  for (int j = 1; j < height - 1; j++)
    for (int i = 1; i < width - 1; i++)
    {
      int new_type = at(i, j) -> updateState(near_cells_value[j * width + i]);
      if (new_type != at(i, j) -> getState())
      {
        Cell* cell_ptr = at(i, j) -> createCell(i, j, new_type);
        delete at(i, j);
        // at(i, j) = cell_ptr;
        cell_vector[i + j * width] = cell_ptr;
      }
    }

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
      at(i,j) -> print(os);
      os << " | ";
    }
    os << std::endl;
  }
  os << std::endl;
}
// Cell* Board::maxLifetimeCell()
// {
//   Cell* max = at(1, 1);
//   for (int j = 1; j < height - 1; j++)
//     for (int i = 1; i < width - 1; i++)
//       if (at(i, j) -> getLifeTime() > max -> getLifeTime())
//         max = at(i, j);
//   return max;
// }

void Board::printStates()
{
  for(int i = 0; i < cell_vector.size(); i++)
    std::cout << cell_vector[i] -> getState();
  std::cout << std::endl;  
}
