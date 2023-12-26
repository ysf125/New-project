#ifndef ticTacToe_hpp
#define ticTacToe_hpp

#include <array>
#include <map>
#include <vector>
#define S std::

struct movesReport {
    int center = 0;
    S vector<int> corners;
    S vector<int> edges; 
};

struct report {
    char win = ' ';
    S vector<int> xCanWin;
    S vector<int> oCanWin;
};

class ticTacToeGame {

private:
    bool AIActivated = false;
    int emptySpacesSize = 9;
    S map<int, float> ratings;
    S array<int, 9> gameStateN;

    template <typename T>

    ticTacToeGame(S array<T, 9> gameStateN);

    float ratingGameState(ticTacToeGame game, char AIC, S map<int, float>& ratings);

    int createID(S array<int, 9> gameStateN);

public:
    ticTacToeGame();

    ticTacToeGame(S array<char, 9> gameStateC);

    S array<char, 9> getGameStateC();

    S vector<int> getEmptySpaces();

    void play(int SpaceIndex, char player = 'a');

    report gameReport();

    movesReport playersMovesReport(char player);

    int AI(char AIC);
};

#endif
