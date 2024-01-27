#include "ticTacToe.hpp"

// private area

template <typename T>

ticTacToeGame::ticTacToeGame(S array<T, 9> gameStateN) {
    for (int i = 0; i < 9; i++) play(i, (char)gameStateC[i]);
}

int ticTacToeGame::ratingGameState(ticTacToeGame game, char AIC, S map<int, int>& ratings) {
 
    return 0;
}

int ticTacToeGame::createID(S array<char, 9> gameStateC) {
    int ID = 0;
    S array<int, 9> map = { 1, 3, 9, 27, 81, 27, 9, 3, 1 };
    for (int i = 0; i < 9; i++) {
        ID += (gameStateC[i] == '-' ? 0 : map[i]);
        ID += (gameStateC[i] == '-' ? 0 : (int)gameStateC[i]);
    }
    return ID;
}

// public area

ticTacToeGame::ticTacToeGame() { gameStateC.fill('-'); }

ticTacToeGame::ticTacToeGame(S array<char, 9> gameStateC) { editGameState(gameStateC); }

void ticTacToeGame::editGameState(S array<char, 9> gameStateC) {
    AIActivated = false;
    emptySpacesSize = 9;
    for (int i = 0; i < 9; i++) play(i, gameStateC[i]);
}

S array<char, 9> ticTacToeGame::getGameStateC() { return gameStateC; }

S vector<int> ticTacToeGame::getEmptySpaces() {
    S vector<int> temp;
    for (int i = 0; i < 9; i++) if (gameStateC[i] == '-') temp.push_back(i);
    return temp;
}

void ticTacToeGame::play(int SpaceIndex, char player) {
    switch (tolower(player)) {
    case 'a': gameStateC[SpaceIndex] = emptySpacesSize % 2 == 1 ? 'x' : 'o'; break;
    case 'x': gameStateC[SpaceIndex] = 'x'; break;
    case 'o': gameStateC[SpaceIndex] = 'o'; break;
    default: gameStateC[SpaceIndex] = '-'; emptySpacesSize++; break;
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
            switch (gameStateC[point]) {
            case 'x': x += 1; break;
            case 'o': o += 1; break;
            default: empty = point; break;
            }
        }
        if ((x == 3) || (o == 3)) returnVal.win = x == 3 ? 'x' : 'o';
        else if ((x == 2) && (o == 0)) returnVal.xCanWin.push_back(empty);
        else if ((o == 2) && (x == 0)) returnVal.oCanWin.push_back(empty);
    }
    return returnVal;
}

moves ticTacToeGame::playersMoves(char player) {
    moves returnVal;
    S array<bool, 9> corners = { 1, 0, 1, 0, 0, 0, 1, 0, 1 };
    S array<bool, 9> edges = { 0, 1, 0, 1, 0, 1, 0, 1, 0 };
    for (int i = 0; i < 9; i++) {
        if ((gameStateC[i] == player) && corners[i]) {
            returnVal.corners.push_back(i);
        }
        else if ((gameStateC[i] == player) && edges[i]) {
            returnVal.edges.push_back(i);
        }
        else if ((gameStateC[i] == player) && (i == 5)) {
            returnVal.center = 5;
        }
    }
    return returnVal;
}

int ticTacToeGame::AI(char AIC) {
   return 0;
}
