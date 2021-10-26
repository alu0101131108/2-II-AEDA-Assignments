#include "../include/Board.hpp"
#include "../include/Cell.hpp"
#include <iostream>
#include <unistd.h>

int main()
{
  int width, height, turns, initial_cells;
  std::cout << "Introduzca las dimensiones del tablero: \nAncho: ";
  std::cin >> width;
  std::cout << "Alto: ";
  std::cin >> height;
  std::cout << "Introduzca el número de turnos deseados: ";
  std::cin >> turns;
  std::cout << "Introduzca el número de células vivas iniciales: ";
  std::cin >> initial_cells;

  Board cell_board(width, height);
  cell_board.initializeCells(initial_cells, std::cin);
  cell_board.print(std::cout);

  while (cell_board.getTurn() < turns)
  {
    system("clear");
    cell_board.updateBoard();
    cell_board.print(std::cout);
    usleep(200000);
  }

  Cell* maxLifeTime = cell_board.maxLifetimeCell();
  std::cout << "\nLa célula que más turnos ha estado viva:\nX: " << maxLifeTime -> getX() << "\nY: " << maxLifeTime -> getY() << "\nTurnos viva: " << maxLifeTime -> getLifeTime() << std::endl;

  return 0;
}

// Entrada 1.
// 3 3
// 3 4
// 5 4
// 2 5
// 4 5
// 3 6
// 5 6
// 6 6
// 5 7
// 20 20
//
// Entrada 2.
// 2 1
// 3 2
// 1 3
// 2 3
// 3 3
