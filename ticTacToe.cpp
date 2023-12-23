#include "ticTacToe.hpp"
#include <array>
#include <ctype.h>
#include <map>
#include <iostream>
#include <vector>
#define S std::

struct report {
    char win = ' ';
    S vector<int> xCanWin;
    S vector<int> oCanWin;
};

// private area

template <typename T>

ticTacToeGame::ticTacToeGame(S array<T, 9> gameStateN) {
    gameStateN.fill(95);
    for (int i = 0; i < 9; i++) play(i, (char)gameStateN[i]);
}

float ticTacToeGame::ratingGameState(ticTacToeGame game, char AIC, S map<int, float>& ratings) {
    float rating = 0;
    int ID = createID(game.gameStateN);
    char playerC = AIC == 'x' ? 'o' : 'x';
    report reportForGS = game.gameReport();
    // getting the rating
    if (ratings.contains(ID)) rating = ratings[ID];
    else {
        int winR = 0, AICanWinR = 0;
        float depth = 9 - game.emptySpacesSize;

        if (AIC == reportForGS.win) winR = 5;
        else if (playerC == reportForGS.win) winR = -5;
        if (AIC == 'x') AICanWinR = reportForGS.xCanWin.size() + (-reportForGS.oCanWin.size());
        else if (AIC == 'o') AICanWinR = reportForGS.oCanWin.size() + (-reportForGS.xCanWin.size());
        rating = (10 - depth) * 10 / 100 * (winR + AICanWinR);
    }
    if (game.emptySpacesSize == 0 || AIC == reportForGS.win || playerC == reportForGS.win) return rating;
    //recursion time beby!
    else {
        for (int i = 0; i < game.emptySpacesSize; i++) {
            ticTacToeGame temp = game;
            S vector<int> emptySpaces = game.getEmptySpaces();
            temp.play(emptySpaces[i]);
            rating += game.ratingGameState(temp, AIC, ratings);
            if (!ratings.contains(ID)) ratings[ID] = rating;
        }
    }
    return 0;
}

int ticTacToeGame::createID(S array<int, 9> gameStateN) {
    int key = 0;
    S array<int, 9> map = { 1, 3, 2, 4, 5, 4, 2, 3, 1 };
    for (int i = 0; i < 9; i++) key += gameStateN[i] + map[i];
    return key;
}

// public area

ticTacToeGame::ticTacToeGame() { gameStateN.fill(95); }

ticTacToeGame::ticTacToeGame(S array<char, 9> gameStateC) {
    gameStateN.fill(95);
    for (int i = 0; i < 9; i++) play(i, gameStateC[i]);
}

S array<char, 9> ticTacToeGame::getGameStateC() {
    S array<char, 9> gameStateC;
    for (int i = 0; i < 9; i++) gameStateC[i] = (char)gameStateN[i];
    return gameStateC;
}

S vector<int> ticTacToeGame::getEmptySpaces() {
    S vector<int> temp;
    for (int i = 0; i < 9; i++) {
        if (gameStateN[i] == 95) temp.push_back(i);
    }
    return temp;
}

void ticTacToeGame::play(int SpaceIndex, char player) {
    if (gameStateN[SpaceIndex] != 95) return;
    switch (tolower(player)) {
    case 'a': gameStateN[SpaceIndex] = emptySpacesSize % 2 == 1 ? 120 : 111; break;
    case 'x': gameStateN[SpaceIndex] = 120; break;
    case 'o': gameStateN[SpaceIndex] = 111; break;
    default: gameStateN[SpaceIndex] = 95; emptySpacesSize++; break;
    }
    emptySpacesSize--;
}

report ticTacToeGame::gameReport() {
    report returnVal;
    S array<int, 16> patterns = { 0, 1, 3, 1, 6, 1, 0, 3, 1, 3, 2, 3, 0, 4, 2, 2 };
    for (int i = 0; i < 8; i++) {
        int empty, x = 0, o = 0;
        for (int y = 0; y < 3; y++) {
            int point = (patterns[(i * 2) + 1] * y) + (patterns[i * 2]);
            switch (gameStateN[point]) {
            case 120: x += 1; break;
            case 111: o += 1; break;
            default: empty = point; break;
            }
        }
        if (x == 3 || o == 3) returnVal.win = x == 3 ? 'x' : 'o';
        else if (x == 2 && o == 0) returnVal.xCanWin.push_back(empty);
        else if (o == 2 && x == 0) returnVal.oCanWin.push_back(empty);
    }
    return returnVal;
}

int ticTacToeGame::AI(char AIC) {
    int AIMove = 0, bestMoveRating = 0;
    // first two moves
    if (9 - emptySpacesSize <= 1) {
        if (!(gameStateN[0] == 120) || !(gameStateN[0] == 111)) AIMove = 0;
        else AIMove = 4;
    }
    else {
        if (AIActivated == false) {
            AIActivated = true;

        }

    }
    return AIMove;
}
