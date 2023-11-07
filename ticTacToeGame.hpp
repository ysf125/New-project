#ifndef ticTacToeGame_hpp
#define ticTacToeGame_hpp
#include "treeDS.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <string>
#include <vector>

#define S std::

struct report {
  char win = ' ';
  S vector<int> xcanWin;
  S vector<int> ocanWin;
};

class ticTacToeGame {

  S array<char, 9> gameState;
  S array<int, 9> gameStateN;
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
    if (player == '`') {
      if (emptySpaces.size() % 2 == 0) {
        play(SpaceIndex, 'o');
      } else {
        play(SpaceIndex, 'x');
      }
    } else if (tolower(player) == 'x') {
      gameState[SpaceIndex] = 'x';
      gameStateN[SpaceIndex] = 1;
    } else if (tolower(player) == 'o') {
      gameState[SpaceIndex] = 'o';
      gameStateN[SpaceIndex] = 4;
    } else {
      gameState[SpaceIndex] = player;
      gameStateN[SpaceIndex] = 0;
      emptySpaces.push_back(SpaceIndex);
    }
  }

  report gameReport() {
    report returnVal;
    S array<int, 16> P = {0, 1, 3, 1, 6, 1};

    for (int i = 0; i < 3; i++) {
      int temp = 0, empty;
      for (int x = 0; x < 3; x++) {
        int point = (P[(i * 2) + 1] * x) + (P[i * 2]);
        if (gameStateN[point] == 0) {
          empty = point;
        } else {
          temp += gameStateN[point];
        }
      }
      int x = temp % 4, o = S floor(temp / 4);
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