#include "Cell.cpp"

Cell* Board::at(int i, int j)
{
  return cell_matrix[j * (width + 2) + i];
}
int Board::getTime()
{
  return time;
}
int Board::getPoblation()
{
  return poblation;
}
void Board::initializeCells(int cell_num, std::istream & is)
{
  int aux_i, aux_j;
  for(int i = 0; i < cell_num; i++)
  {
    is >> aux_i;
    is >> aux_j;
    at(aux_i, aux_j) -> setState(1);
  }
}
void Board::updateBoard()
{
  // Se recorre por primera vez para analizar las células vecinas.
  std::vector<int> near_cells_value(cell_matrix.size(), 0);
  for(int j = 1; j < height + 1; j++)
    for(int i = 1; i < width + 1; i++)
      near_cells_value[j * (width + 2) + i] = at(i, j) -> countNearCells(*this);
      
  // Se recorre por segunda vez para actualizar el estado.
  for(int j = 1; j < height + 1; j++)
    for(int i = 1; i < width + 1; i++)
      cell_matrix[j * width + i] -> updateState(near_cells_value[j * width + i]);

}
void Board::print(std::ostream & os)
{
  for(int j = 0; j < height + 2; j++)
  {
    os << "| ";
    for(int i = 0; i < width + 2; i++)
    {
      at(i,j) -> Cell::print(os);
      os << " | ";
    }
    os << std::endl;
  }
  os << std::endl;
}
