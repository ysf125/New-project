#ifndef ticTacToeGame_hpp
#define ticTacToeGame_hpp
#include "treeDS.hpp"
#include <algorithm>
#include <array>
#include <vector>
#define S std::

struct report {
  char win = ' ';
  S vector<int> xcanWin;
  S vector<int> ocanWin;
};

class ticTacToeGame {

  S array<char, 9> gameState;
  S vector<int> emptySpaces;

public:
  ticTacToeGame() {
    for (int i = 0; i < 9; i++) {
      play(i, ' ');
    }
  }
  ticTacToeGame(S array<char, 9> gameState) {
    for (int i = 0; i < 9; i++) {
      play(i, gameState[i]);
    }
  }

  S array<char, 9> getGameState() { return this->gameState; }

  S vector<int> getEmptySpaces() { return this->emptySpaces; }

  void play(int SpaceIndex, char player = '`') {
    switch (tolower(player)) {
    case '`':
      if (emptySpaces.size() % 2 == 0) {
        play(SpaceIndex, 'o');
      } else {
        play(SpaceIndex, 'x');
      }
      break;
    case 'x':
      gameState[SpaceIndex] = 'x';
      break;
    case 'o':
      gameState[SpaceIndex] = 'o';
      break;
    default:
      gameState[SpaceIndex] = player;
      emptySpaces.push_back(SpaceIndex);
      break;
    }
  }

  report gameReport() {
    report returnVal;
    S array<int, 16> P = {0, 1, 3, 1, 6, 1};

    for (int i = 0; i < 3; i++) {
      int empty, x = 0, o = 0;
      for (int y = 0; y < 3; y++) {
        int point = (P[(i * 2) + 1] * y) + (P[i * 2]);
        switch (gameState[point]) {
        case 'x':
          x += 1;
          break;
        case 'o':
          o += 1;
          break;
        default:
          empty = point;
          break;
        }
      }
      if (x == 3 || o == 3) {
        returnVal.win = x == 3 ? 'x' : 'o';
      } else if (x == 2 && o == 0) {
        returnVal.xcanWin.push_back(empty);
      } else if (o == 2 && x == 0) {
        returnVal.ocanWin.push_back(empty);
      }
    }
    return returnVal;
  }
};

#endif