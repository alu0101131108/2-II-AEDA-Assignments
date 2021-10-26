#include "Board.cpp"

int main()
{
  Board cell_board(25, 25);
  cell_board.initializeCells(10, std::cin);

  cell_board.print(std::cout);
  std::cout << std::endl;

char t;

while(true)
{
  cell_board.updateBoard();
  cell_board.print(std::cout);
  std::cout << std::endl;
  std::cin >> t;
}

  return 0;
}

// Entrada curiosa.
// 3
// 3
// 3
// 4
// 5
// 4
// 2
// 5
// 4
// 5
// 3
// 6
// 5
// 6
// 6
// 6
// 5
// 7
// 20
// 20
