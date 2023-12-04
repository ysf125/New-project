#include "ticTacToeGame.hpp"
#include "tools.hpp"
#include <iostream>
#define S std::

int main() {

  // testing for ticTacToeGame class
  // 0 1 2 /
  // 3 4 5 /
  // 6 7 8 /

  ticTacToeGame g({'x','x'});
  g.ratingGameState(g.getGameState(),'x',7);


  return 0;
}
