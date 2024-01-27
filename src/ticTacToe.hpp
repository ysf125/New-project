#ifndef ticTacToe_hpp
#define ticTacToe_hpp

#include <array>
#include <map>
#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
#define S std::

struct moves {
    int center = 0;
    S vector<int> corners;
    S vector<int> edges;
};

struct report {
    char win = '-';
    S vector<int> xCanWin;
    S vector<int> oCanWin;
};

class ticTacToeGame {

private:
    bool AIActivated = false;
    int emptySpacesSize = 9;
    S map<int, int> ratings;
    S array<char, 9> gameStateC;

    template <typename T>

    ticTacToeGame(S array<T, 9> gameStateN);

    int ratingGameState(ticTacToeGame game, char AIC, S map<int, int>& ratings);

    int createID(S array<char, 9> gameStateC);

public:
    ticTacToeGame();

    ticTacToeGame(S array<char, 9> gameStateC);

    void editGameState(S array<char, 9> gameStateC);

    S array<char, 9> getGameStateC();

    S vector<int> getEmptySpaces();

    void play(int SpaceIndex, char player = 'a');

    report gameReport();

    moves playersMoves(char player);

    int AI(char AIC);
};

#endif
